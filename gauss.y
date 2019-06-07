%{
	#include <stdio.h>
    #include "tabelaHash.h"

  int yylex(void);
  int yyerror(char *s);
  extern int yylineno;
  extern char * yytext; 

  //typedef enum {false, true} bool;

  valor makeValorFunc(char *nome, char *retorno, char *Params);


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
%token IF END_IF ELSE ELSEIF THEN STRUCT ENDSTRUCT IS END 
%token FUNCAO PROC RETURN TBEGIN CONSTANTE PRINTF SCANF 
%token CARACTERE STRING INTEIRO FLOAT DOUBLE VOID
%token BOOLEANO TRUE FALSE JUMP BREAK TNULL
%token <iValue> DIGITO
%token <sValue> ID
%token LITERAL_QUALQUER

%start prog

%type <sValue> subprog struct_list 
%type <sValue> FUNCAO



%%
prog                : subprog       {}
                    | struct_list subprog   {}
                    ;

subprog             : funcao                    {}
                    | subprog funcao            {}
                    ;

stmts               : stmt              {}
                    | stmt stmts        {}
                    ;

decl                : type id           {}
                    | type vars         {}
                    | type vars decl    {}
                    | type atribuicoes  {}
                    ;

struct_list         : struct                                            {}
                    | struct struct_list                                {}
                    ;

struct              : STRUCT ID IS decl_list ENDSTRUCT {}
                    ;

stmt                : decl PONTO_E_VIRGULA                              {} 
                    | if_stmt                                           {}
                    | while_stmt                                        {} 
                    | for_stmt                                          {}
                    | atribuicoes PONTO_E_VIRGULA                       {}
                    | invoca_procedimento PONTO_E_VIRGULA               {}
                    | switch_stmt                                       {}
                    ;

invoca_procedimento : ID PARENTESE_ESQUERDA parametros PARENTESE_DIREITA {}
                    ;
   
parametros          : expressoes {}
                    | expressoes VIRGULA parametros {}
                    ;  

decl_list           : decl PONTO_E_VIRGULA {}
                    | decl PONTO_E_VIRGULA decl_list    {}
                    ;

while_stmt          : WHILE PARENTESE_ESQUERDA valor PARENTESE_DIREITA stmts END_WHILE  {}
                    ;

for_stmt            : FOR PARENTESE_ESQUERDA 
                            decl PONTO_E_VIRGULA 
                            valor PONTO_E_VIRGULA 
                            atribuicoes PARENTESE_DIREITA 
                        stmts END_FOR  {}
                    ;                  


if_stmt             : IF PARENTESE_ESQUERDA valor PARENTESE_DIREITA THEN stmts elses_opcoes END_IF {}
                    ;

if_stmt_in_else     : IF PARENTESE_ESQUERDA valor PARENTESE_DIREITA THEN stmts elses_opcoes {}
                    ;

elses_opcoes        : {}
                    | ELSE THEN stmts {}
                    | ELSE if_stmt_in_else {}
                    ;

switch_stmt         : SWITCH PARENTESE_ESQUERDA valor PARENTESE_DIREITA 
                    case_stmt default END_SWITCH      {}  
                    ;

default             : 
                    | DEFAULT stmts
                    ;

case_stmt           : case                            {}
                    | case case_stmt                  {}
                    ;

case                : CASE PARENTESE_ESQUERDA id PARENTESE_DIREITA DOIS_PONTOS stmts       {}
                    ;

/************ ATRIBUICOES *****/
atribuicoes         : atribuicao_simples                    {}
                    | atribuicao_unaria                     {}
                    | atribuicao_composta                   {} 
                    | atribuicao_paralela                   {}
                    ;

atribuicao_simples  : id ATRIBUICAO expressoes {}
                    ;

atribuicao_unaria   : id operador_unario                   {}
                    | operador_unario ID                   {}
                    ;

atribuicao_composta : id operador_composto valor     {}
                    ;

atribuicao_paralela : vars ATRIBUICAO expressoes_list {}
                    ;

operador_unario     : INCREMENTO        {}
                    | DECREMENTO        {}
                    ;

operador            : MAIS              {}           
                    | MENOS_UNARIO      {}
                    | EXPONENCIACAO     {}
                    | BARRA             {}
                    | MODULO            {}
                    ;
                    
operador_comp       : MENOR_QUE         {}
                    | MAIOR_QUE         {}
                    | MENOR_OU_IGUAL_A  {}
                    | MAIOR_OU_IGUAL_A  {}
                    | IGUAL_A           {}
                    | DIFERENTE_DE      {}
                    ;

operador_composto   : MAIS_IGUAL                      {}
                    | MENOS_IGUAL                     {}
                    | VEZES_IGUAL                     {}
                    | DIV_IGUAL                       {}
                    | EXPONENCIACAO_IGUAL             {}
                    ;

type                : CARACTERE     {}
                    | STRING        {}
                    | INTEIRO       {}
                    | FLOAT         {}
                    | DOUBLE        {}
                    | VOID          {}
                    | BOOLEANO      {}
                    ;
 
/*Colocar demais operadores*/


valor               : expressoes E_LOGICO expressoes    {}  
                    | expressoes                        {}                          
                    ;

expressoes          : {}
                    | id                    {}
                    | id operador id        {}
                    | id operador_comp id   {}
                    | vetorial              {} 
                    ;

vetorial            : CHAVE_ESQUERDA lista_de_digitos CHAVE_DIREITA {}  
                        
                    ;   
lista_de_digitos    : DIGITO                            {}
                    | DIGITO VIRGULA lista_de_digitos   {}
                    ;               

expressoes_list      : expressoes VIRGULA expressoes {}
                    ;                                        

vars                : ID VIRGULA ID     {}
                    | ID VIRGULA vars   {}
                    ;

args                : 
                    | type ID {}
                    | type ID COLCHETE_ESQUERDA COLCHETE_DIREITA VIRGULA args {}
                    | type ID VIRGULA args                    {}
                    ;

funcao              : FUNCAO ID  PARENTESE_ESQUERDA args 
                      PARENTESE_DIREITA RETURN type IS
                      TBEGIN stmts END ID               {makeValorFunc($2, $4, $7, )}
                    ;

id                  : ID {}
                    | DIGITO {}
                    | ID COLCHETE_ESQUERDA expressoes COLCHETE_DIREITA {}
                    | PARENTESE_ESQUERDA expressoes PARENTESE_DIREITA {}
                    ;
%%

int main (void) {
  return yyparse ( );
}

valor makeValorFunc(char *nome, char *retorno, char qntParams, char *tiposParams){
    valor temp;
    temp.funcao->id = nome;
    temp.funcao->retorno = retorno;
    temp.funcao->qntParams = qntParams - '0';
    temp.funcao->tiposParams = tiposParams;
}


int yyerror (char *msg) {
  fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
  return 0;
}

