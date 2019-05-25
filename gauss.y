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
%type <sValue> funcao


%%
prog                : subprog stmts                           {}
                    ;

subprog             : funcao                        {}
                    | subprog funcao                        {}
                    ;

funcao              : FUNCAO ID  PARENTESE_ESQUERDA args 
                      PARENTESE_DIREITA RETURN type IS
                      TBEGIN stmts END ID               {}
                    ;

args                : type id {}
                    | type id COLCHETE_ESQUERDA COLCHETE_DIREITA VIRGULA args {}
                    | type id VIRGULA args                    {}
                    ;                    

stmts               : stmt PONTO_E_VIRGULA                      {}
                    | stmt PONTO_E_VIRGULA stmts      {}
                    ;

stmt                : decl {}
                    | atribuicoes                         {}
                    ;

decl                : type id {}
                    | type vars {}      
                    ;

atribuicoes         : atribuicao_simples                    {}
                    | atribuicao_unaria                     {}
                    | atribuicao_composta                   {} 
                    | atribuicao_paralela {}
                    ;

type                : CARACTERE {}
                    | STRING {}
                    | INTEIRO {}
                    | FLOAT {}
                    | DOUBLE {}
                    | VOID         {}
                    | BOOLEANO                              {}
                    ;


vars                : 
                    | id VIRGULA vars {}  
                    ;

atribuicao_simples  : id ATRIBUICAO id                 {}
                    ;

atribuicao_unaria   : id operador_unario                   {}
                    | operador_unario id                   {}
                    ;

atribuicao_composta : id operador_composto id     {}
                    ;

atribuicao_paralela : vars ATRIBUICAO vars {}
                    ;

operador_unario     : INCREMENTO                      {}
                    | DECREMENTO                      {}
                    ;

operador            : MAIS {}           
                    | MENOS_UNARIO {}
                    | EXPONENCIACAO {}
                    ;

operador_composto   : MAIS_IGUAL                      {}
                    | MENOS_IGUAL                     {}
                    | VEZES_IGUAL                     {}
                    | DIV_IGUAL                       {}
                    | EXPONENCIACAO_IGUAL             {}
                    ;
                                                                             

id                  : ID {}
                    | DIGITO {}
                    ;                    

                                                            

%%

int main (void) {
  return yyparse ( );
}

int yyerror (char *msg) {
  fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
  return 0;
}

