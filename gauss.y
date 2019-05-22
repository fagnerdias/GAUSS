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
prog                : stmts                           {}
                    ;

stmts               : stmt                            {}
                    | stmt PONTO_E_VIRGULA stmts      {}
                    ;

stmt                : if_stmt                       {} 
                    | atribuicoes                         {}
                    ;

if_stmt             : IF PARENTESE_DIREITA valor PARENTESE_ESQUERDA THEN stmts 
                    elses_opcoes END_IF                            {}
                    ;

elses_opcoes        : {}
                    | else {}
                    | elseif {}
                    ;
else                : ELSE THEN stmts {}
                    ;
elseif              : ELSE if_stmt {}
                    ;
              /*
aa                  :   else_if_list {}
                    | {}
                    ;

elses               : else                                  {}
                    | else_if_list aux                      {}
                    ;

aux                 : else                                  {}
                    ;

else_if_list        : ELSEIF                                {}
                    | else_if_list                          {}
                    ;

bb                  : ELSE {}
                    |   {}
                    ;
*/
/************ ATRIBUICOES *****/
atribuicoes         : atribuicao_simples                    {}
                    | atribuicao_unaria                     {}
                    | atribuicao_composta                   {} 
                    ;

atribuicao_simples  : type ID IGUAL_A valor                 {}
                    ;

atribuicao_unaria   : var operador_unario                   {}
                    | operador_unario var                   {}
                    ;

atribuicao_composta : var operador_composto valor     {}
                    ;

operador_unario     : INCREMENTO                      {}
                    | DECREMENTO                      {}
                    ;

operador_composto   : MAIS_IGUAL                      {}
                    | MENOS_IGUAL                     {}
                    | VEZES_IGUAL                     {}
                    | DIV_IGUAL                       {}
                    | EXPONENCIACAO_IGUAL             {}
                    ;

type                : ID                              {}
                    ;

valor               : ID                              {}
                    ;

var                 : ID                              {}
                    ;

%%

int main (void) {
  return yyparse ( );
}

int yyerror (char *msg) {
  fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
  return 0;
}

