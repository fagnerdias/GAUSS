%{
	#include<stdio.h>

  int yylex(void);
  int yyerror(char *s);
  extern int yylineno;
  extern char * yytext; 


%}

%union {
  int    iValue;  /* integer value */
  float  fValue;  /* float value */
  double dValue;  /* double value */
  bool   bValue;  /* boolean value */
  char   cValue;  /* char value */
  char * sValue;  /* string value */
}

%token GLOBAL SUBPROG MAIN
%token CHAVE_ESQUERDA CHAVE_DIREITA PARENTESE_ESQUERDA PARENTESE_DIREITA COLCHETE_ESQUERDA COLCHETE_DIREITA 
%token PONTO_E_VIRGULA VIRGULA PONTO DOIS_PONTOS
%token E_LOGICO E_LOGICO_CURTO_CIRCUITO OU_LOGICO OU_LOGICO_CURTO_CIRCUITO EXCLAMACAO
%token ASTERISCO PRINT_INT PRINT_FLOAT PRINT_CHAR PRINT_STRING MODULO
%token BARRA INCREMENTO DECREMENTO MAIS MENOS_UNARIO EXPONENCIACAO ATRIBUICAO OPERADOR_TERNARIO
%token MENOR_QUE MAIOR_QUE MENOR_OU_IGUAL_A MAIOR_OU_IGUAL_A IGUAL_A DIFERENTE_DE
%token MAIS_IGUAL MENOS_IGUAL VEZES_IGUAL DIV_IGUAL EXPONENCIACAO_IGUAL
%token FOR END_FOR DO WHILE END_WHILE SWITCH END_SWITCH CASE END_CASE DEFAULT 
%token IF END_IF ELSE ELSEIF THEN STRUCT IS END FUNCAO PROC RETURN BEGIN CONSTANTE PRINTF SCANF 
%token CARACTERE STRING INTEIRO FLOAT DOUBLE VOID
%token BOOLEANO TRUE FALSE JUMP BREAK NULL
%token <iValue> DIGITO
%token <sValue> ID
%token LITERAL_QUALQUER

%start prog

%type <sValue> stmt


%%
prog                : globais subprog main			  {}
                    ;

globais				: 
					| GLOBAL BEGIN declaracoes END 	  {}
					;

subprog 			: 
					| SUBPROG BEGIN subprogramas END  {}
					;

subprogramas		: subprograma subprogramas		  {}
					;

subprograma			: 								  {}
					| function_def					  {}
					| procedimento_def				  {}
					;

main				:
					| MAIN BEGIN stmts END 			  {}
					;

stmts               : stmt                            {}
                    | stmt PONTO_E_VIRGULA stmts      {}
                    ;

stmt                : if_stmt                         {}
                    | while_stmt                      {}
                    | switch_stmt                     {}
                    | assign                          {}
                    | for_stmt                        {}
                    | JUMP                            {}
                    | BREAK                           {}
                    | procedimento_call				  {}
                    | declaracao					  {}
                    ;
/* todo: expressao pode vir entre parenteses */
expressao           : expressao                       {}
                    | expressao operador expressao    {}
                    | valor 						  {}
                    | LITERAL_QUALQUER				  {}
                    | function_call					  {}
                    ;

operador            : MAIS                            {}
                    | MENOS_UNARIO                    {}
                    | ASTERISCO                       {}
                    | BARRA                           {}  
                    | MODULO                          {}
                    | EXPONENCIACAO                   {}
                    | E_LOGICO                        {}
                    | OU_LOGICO                       {}
                    ;

operador_unario     : INCREMENTO                      {}
                    | DECREMENTO                      {}
                    ;

operador_composto	: MAIS_IGUAL					  {}
					| MENOS_IGUAL					  {}
					| VEZES_IGUAL					  {}
					| DIV_IGUAL						  {}
					| EXPONENCIACAO_IGUAL			  {}
					;

vars                : var                             {}
                    | var VIRGULA vars                {}
                    ;

valores             : valor                           {}
                    | valor VIRGULA valores           {}
                    ;

valor 	            : var                             {}
                    | NULL                            {}
                    | ID                              {}
                    ;

expressao_constante : var                             {}
                    ;

var                 : ID                              {}
                    ;

type                : ID                              {}
                    ;

assign              : assign_simples                  {}
                    | assign_unaria                   {}
                    | assign_composta                 {}
                    | assign_paralela                 {}    
                    | assign_ternaria                 {}
                    ;              

assign_simples		: valor IGUAL_A expressao		  {}
					;

assign_unaria		: valor operador_unario			  {}
					| operador_unario valor 		  {}
					;

assign_composta		: var operador_composto valor 	  {}
					;

assign_paralela		: vars IGUAL_A valores			  {}
					;

assign_ternaria   	: expressao OPERADOR_TERNARIO 
					stmts DOIS_PONTOS stmts 		  {}

if_stmt             : IF PARENTESE_DIREITA expressao 
                    PARENTESE_ESQUERDA THEN stmts 
                    else_if_list else END_IF          {}
                    ;

else_if_list        : else_if                         {}
                    | else_if else_if_list            {}
                    ;

else_if             : ELSEIF PARENTESE_DIREITA 
                    expressao PARENTESE_ESQUERDA 
                    THEN stmts                        {}
                    ;

else                : 
                    | ELSE stmts                      {}
                    ;

switch_stmt         : SWITCH PARENTESE_DIREITA 
                    expressao PARENTESE_ESQUERDA 
                    case_stmt default END_SWITCH      {}  
                    ;

default             : 
                    | DEFAULT stmts
                    ;

case_stmt           : case                            {}
                    | case case_stmt                  {}
                    ;

case                : CASE PARENTESE_DIREITA 
                    expressao_constante PARENTESE_ESQUERDA 
                    DOIS_PONTOS stmts                 {}
                    ;

while_stmt          : WHILE PARENTESE_DIREITA 
                    expressao PARENTESE_ESQUERDA 
                    THEN stmts END_WHILE              {}
                    ;

for_stmt            : FOR PARENTESE_DIREITA 
                    for_cond PARENTESE_ESQUERDA 
                    THEN stmts END_FOR                {}
                    ;

for_cond            : assign PONTO_E_VIRGULA 
                    expressao PONTO_E_VIRGULA assign  {}
                    | PONTO_E_VIRGULA expressao 
                    PONTO_E_VIRGULA assign            {}
                    | assign PONTO_E_VIRGULA 
                    expressao PONTO_E_VIRGULA         {}
                    | PONTO_E_VIRGULA PONTO_E_VIRGULA
                    expressao                         {}
                    ;

function_def        : FUNCAO ID 
					PARENTESE_DIREITA params 
					PARENTESE_ESQUERDA 
					RETURN return_type IS BEGIN 
					stmts 
					END                   			  {}
                    ;

procedimento_def    : PROC ID 
					PARENTESE_DIREITA params 
					PARENTESE_ESQUERDA
					IS BEGIN 
					stmts 
					END                   			  {}
                    ;

function_call       : ID PARENTESE_ESQUERDA args 
					PARENTESE_DIREITA                 {}
                    ;

procedimento_call   : ID PARENTESE_ESQUERDA args 
					PARENTESE_DIREITA         		  {}
                    ;

params              : declaracao
                    | declaracao VIRGULA params
                    ;

args				: expressao 					  {}
					| expressao VIRGULA expressao
					;

/* adicionar constante */
declaracoes 		: declaracao					  {}
					| declaracao PONTO_E_VIRGULA 
					declaracoes						  {}
					;

declaracao			: 
					| type ids						  {}
					;

ids 				: ID VIRGULA ids				  {}
					;

return_type         : VOID 							  {}
                    | type 							  {}
                    ;

%%

int main (void) {
  return yyparse ( );
}

int yyerror (char *msg) {
  fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
  return 0;
}

