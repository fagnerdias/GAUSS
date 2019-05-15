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

%token CHAVE_ESQUERDA CHAVE_DIREITA PARENTESE_ESQUERDA PARENTESE_DIREITA COLCHETE_ESQUERDA COLCHETE_DIREITA 
%token PONTO_E_VIRGULA VIRGULA PONTO DOIS_PONTOS
%token E_LOGICO E_LOGICO_CURTO_CIRCUITO OU_LOGICO OU_LOGICO_CURTO_CIRCUITO EXCLAMACAO
%token ASTERISCO PRINT_INT PRINT_FLOAT PRINT_CHAR PRINT_STRING MODULO
%token BARRA INCREMENTO DECREMENTO MAIS MENOS_UNARIO EXPONENCIACAO ATRIBUICAO
%token MENOR_QUE MAIOR_QUE MENOR_OU_IGUAL_A MAIOR_OU_IGUAL_A IGUAL_A DIFERENTE_DE
%token FOR END_FOR DO WHILE END_WHILE SWITCH END_SWITCH CASE END_CASE DEFAULT IF END_IF ELSE ELSEIF THEN STRUCT IS END FUNCAO RETURN BEGIN CONSTANTE PRINTF SCANF 
%token CARACTERE STRING INTEIRO FLOAT DOUBLE
%token BOOLEANO TRUE FALSE JUMP BREAK NULL
%token <iValue> DIGITO
%token <sValue> ID
%token LITERAL_QUALQUER

%start prog

%type <sValue> stm


%%
prog                : stmts                           {}
                    ;

stmts               : stmt                            {}
                    | stmt PONTO_E_VIRGULA stmts      {}
                    ;

stmt                : if_stmt                         {}
                    | while_stmt                      {}
                    | switch_stmt                     {}
                    | assing                          {}
                    | for_stmt                        {}
                    | JUMP                            {}
                    | BREAK                           {}
                    ;

expressoes          : expressao                       {}
                    | expressao operador expressoes   {}
                    ;

expressao           : valor operador valor            {}
                    | valor                           {}
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

vars                : var                             {}
                    | var VIRGULA vars                {}
                    ;

valores             : valor                           {}
                    | valor VIRGULA valores           {}
                    ;

valores             : var                             {}
                    | NULL                            {}
                    | ID                              {}
                    ;

expressao_constante : var                             {}
                    ;

var                 : ID                              {}
                    ;

type                : ID                              {}
                    ;

assing              : assing_simples                  {}
                    | assing_unaria                   {}
                    | assing_composta                 {}
                    | assing_paralela                 {}    
                    | assing_ternaria                 {}
                    ;                    

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
                    expessao PARENTESE_ESQUERDA 
                    DOIS_PONTOS stmts                 {}
                    ;

while_stmt          : WHILE PARENTESE_DIREITA 
                    expressoes PARENTESE_ESQUERDA 
                    THEN stmts END_WHILE              {}
                    ;

for_stmt            : FOR PARENTESE_DIREITA 
                    for_cond PARENTESE_ESQUERDA 
                    THEN stmts END_FOR                {}
                    ;

for_cond            : assing PONTO_E_VIRGULA 
                    expressoes PONTO_E_VIRGULA assing {}
                    | PONTO_E_VIRGULA expressoes 
                    PONTO_E_VIRGULA assing            {}
                    | assing PONTO_E_VIRGULA 
                    expressoes PONTO_E_VIRGULA        {}
                    | PONTO_E_VIRGULA PONTO_E_VIRGULA
                    expressoes                        {}
                    ;

function            : FUNCAO ID PARENTESE_DIREITA 
                    params RETURN return_type IS 
                    BEGIN stmts                       {}
                    ;

params              : param
                    | param VIRGULA params
                    ;

param               : 
                    | var
                    ;

return_type         : VOID
                    | type
                    ;

%%

int main (void) {
  return yyparse ( );
}

int yyerror (char *msg) {
  fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
  return 0;
}

