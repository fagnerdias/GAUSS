%{
	#include<stdio.h>

  int yylex(void);
  int yyerror(char *s);
  extern int yylineno;
  extern char * yytext; 

  //typedef enum {false, true} bool;


%}

%union {
  int    iValue;  /* integer value */
  float  fValue;  /* float value */
  double dValue;  /* double value */
  int   bValue;  /* boolean value */
  char   cValue;  /* char value */
  char * sValue;  /* string value */
}

%token CHAVE_ESQUERDA CHAVE_DIREITA PARENTESE_ESQUERDA PARENTESE_DIREITA COLCHETE_ESQUERDA COLCHETE_DIREITA 
%token PONTO_E_VIRGULA VIRGULA PONTO DOIS_PONTOS
%token E_LOGICO E_LOGICO_CURTO_CIRCUITO OU_LOGICO OU_LOGICO_CURTO_CIRCUITO EXCLAMACAO
%token ASTERISCO PRINT_INT PRINT_FLOAT PRINT_CHAR PRINT_STRING MODULO
%token BARRA INCREMENTO DECREMENTO MAIS MENOS_UNARIO EXPONENCIACAO ATRIBUICAO OPERADOR_TERNARIO
%token MENOR_QUE MAIOR_QUE MENOR_OU_IGUAL_A MAIOR_OU_IGUAL_A IGUAL_A DIFERENTE_DE
%token MAIS_IGUAL MENOS_IGUAL VEZES_IGUAL DIV_IGUAL EXPONENCIACAO_IGUAL
%token FOR END_FOR DO WHILE END_WHILE SWITCH END_SWITCH CASE END_CASE DEFAULT 
%token IF END_IF ELSE ELSEIF THEN STRUCT IS END FUNCAO PROC RETURN TBEGIN CONSTANTE PRINTF SCANF 
%token CARACTERE STRING INTEIRO FLOAT DOUBLE VOID
%token BOOLEANO TRUE FALSE JUMP BREAK TNULL
%token <iValue> DIGITO
%token <sValue> ID
%token LITERAL_QUALQUER

%start prog

%type <sValue> stmt


%%
prog                : subprog stmts                           {}
                    ;

subprog             : funcao                        {}
                    | subprog funcao                        {}
                    ;
stmts               : stmt PONTO_E_VIRGULA                          {}
                    | stmt PONTO_E_VIRGULA stmts      {}
                    ;

decl                : type vars {}
                    | type vars decl {}
                    ;

stmt                : decl {}
                    | if_stmt                       {}
                    | while_stmt {} 
                    | atribuicoes                         {}
                    ;

if_stmt             : IF PARENTESE_ESQUERDA valor PARENTESE_DIREITA THEN stmts elses_opcoes END_IF                            {}                    
                    ;

while_stmt          : WHILE PARENTESE_ESQUERDA expressoes PARENTESE_DIREITA stmts END_WHILE  {}
                    ;                 

elses_opcoes        : {}
                    | else {}
                    | elseif {}
                    ;
else                : ELSE THEN stmts {}
                    ;
elseif              : ELSE if_stmt {}
                    ;
/************ ATRIBUICOES *****/
atribuicoes         : atribuicao_simples                    {}
                    | atribuicao_unaria                     {}
                    | atribuicao_composta                   {} 
                    | atribuicao_paralela {}
                    ;

atribuicao_simples  : ID ATRIBUICAO id                 {}
                    ;

atribuicao_unaria   : ID operador_unario                   {}
                    | operador_unario ID                   {}
                    ;

atribuicao_composta : ID operador_composto valor     {}
                    ;

atribuicao_paralela : vars ATRIBUICAO exprecoes_list {}
                    ;

operador_unario     : INCREMENTO                      {}
                    | DECREMENTO                      {}
                    ;

operador            : MAIS {}           
                    | MENOS_UNARIO {}
                    | EXPONENCIACAO {}
                    | BARRA {}
                    | MODULO {}
                    ;
                    
operador_comp       : MENOR_QUE {}
                    | MAIOR_QUE {}
                    | MENOR_OU_IGUAL_A {}
                    | MAIOR_OU_IGUAL_A {}
                    | IGUAL_A {}
                    | DIFERENTE_DE {}
                    ;

operador_composto   : MAIS_IGUAL                      {}
                    | MENOS_IGUAL                     {}
                    | VEZES_IGUAL                     {}
                    | DIV_IGUAL                       {}
                    | EXPONENCIACAO_IGUAL             {}
                    ;

type                : CARACTERE {}
                    | STRING {}
                    | INTEIRO {}
                    | FLOAT {}
                    | DOUBLE {}
                    | VOID         {}
                    | BOOLEANO                              {}
                    ;
 

valor               : id {}                              
                    ;

expressoes           : 
                    | id {}
                    | id operador id {}
                    | id operador_comp id {}                    
                    ;

exprecoes_list      : expressoes VIRGULA expressoes {}
                    ;                                        

vars                : ID VIRGULA ID {}
                    | ID VIRGULA vars {}
                    ;

args                : type ID {}
                    | type ID COLCHETE_ESQUERDA COLCHETE_DIREITA VIRGULA args {}
                    | type ID VIRGULA args                    {}
                    ;

funcao              : FUNCAO ID  PARENTESE_ESQUERDA args 
                      PARENTESE_DIREITA RETURN type IS
                      TBEGIN stmts END                {}
                    ;

id                  : ID {}
                    | DIGITO {}
                    | ID COLCHETE_ESQUERDA expressoes COLCHETE_DIREITA
                    | PARENTESE_ESQUERDA expressoes PARENTESE_DIREITA {}
                    ;
%%

int main (void) {
  return yyparse ( );
}

int yyerror (char *msg) {
  fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
  return 0;
}

