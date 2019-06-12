%{
	#include <stdio.h>
    #include <stdlib.h>
    #include "tabelasimbolos.c"
  
  int yylex(void);
  int yyerror(char *s);
  extern int yylineno;
  extern char * yytext; 

  int escopo = -1;
  char buffer[33];
  

  //typedef enum {false, true} bool;

  char* _itoa(int valor, char* resultado, int base);

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
%token <sValue> FUNCAO PROC RETURN TBEGIN CONSTANTE PRINTF SCANF 
%token <sValue> CARACTERE STRING INTEIRO FLOAT DOUBLE VOID
%token <sValue> BOOLEANO TRUE FALSE JUMP BREAK TNULL
%token <iValue> DIGITO
%token <sValue> ID
%token LITERAL_QUALQUER

%type <sValue> args type 
%type <sValue> id

%start prog



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

decl                : type id           { insertVar($2, escopo, $1); }
                    | type vars         { insertVar($2, escopo, $1); }
                    | type vars decl    {}
                    | type atribuicoes  {}
                    ;

struct_list         : struct                                            {}
                    | struct struct_list                                {}
                    ;

struct              : STRUCT ID IS decl_list ENDSTRUCT                  {}
                    ;

stmt                : decl PONTO_E_VIRGULA                              {} 
                    | if_stmt                                           {}
                    | while_stmt                                        {} 
                    | for_stmt                                          {}
                    | atribuicoes PONTO_E_VIRGULA                       {}
                    | invoca_procedimento PONTO_E_VIRGULA               {}
                    | switch_stmt                                       {}
                    | print PONTO_E_VIRGULA                             {}
                    | scan PONTO_E_VIRGULA                              {}
                    | RETURN id PONTO_E_VIRGULA                         {}
                    ;

print               : PRINTF PARENTESE_ESQUERDA ids types_args PARENTESE_DIREITA {} 
                    ;

scan                : SCANF PARENTESE_ESQUERDA ids types_args PARENTESE_DIREITA {} 
                    ;

ids                 : expressoes {}
                    | ids VIRGULA expressoes  {}
                    ;

types_args          :                                            {}
                    | prints_list                                {}
                    ;

prints_list         : VIRGULA tipos_prints                                            {}
                    | VIRGULA tipos_prints prints_list                                {}
                    ;

tipos_prints        : PRINT_INT {}
                    | PRINT_FLOAT {}
                    | PRINT_CHAR {}
                    | PRINT_STRING {}
                    ;

invoca_procedimento : ID PARENTESE_ESQUERDA parametros PARENTESE_DIREITA { }
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

type                : CARACTERE     {$$ = $1;}
                    | STRING        {$$ = $1;}
                    | INTEIRO       {$$ = $1;}
                    | FLOAT         {$$ = $1;}
                    | DOUBLE        {$$ = $1;}
                    | VOID          {$$ = $1;}
                    | BOOLEANO      {$$ = $1;}
                    ;
 
/*Colocar demais operadores*/


valor               : expressoes E_LOGICO expressoes    {}  
                    | expressoes OU_LOGICO expressoes   {}   
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

vars                : ID VIRGULA ID     { $$ = strcat(strcat($1,","),$3); }
                    | ID VIRGULA vars   { $$ = strcat(strcat($1,","),$3); }
                    ;

args                :                                                           { $$ = ""; }
                    | type ID                                                   { $$ = strcat(strcat($1, "#"),$2); }
                    | type ID COLCHETE_ESQUERDA COLCHETE_DIREITA VIRGULA args   {$$ = ""; }
                    | type ID VIRGULA args                                      {$$ = ""; }
                    ;

funcao              : FUNCAO ID  PARENTESE_ESQUERDA args 
                      PARENTESE_DIREITA RETURN type IS
                      TBEGIN { insertFunc($2, escopo, $7, $4); escopo++;} stmts END ID  
                      { }
                    ;

id                  : ID                                                { $$ = $1; }
                    | DIGITO                                            { }
                    | ID COLCHETE_ESQUERDA expressoes COLCHETE_DIREITA  {}
                    | PARENTESE_ESQUERDA expressoes PARENTESE_DIREITA   {}
                    ;
%%

int main (void) {

    yyparse ( );
    
    return 1;
}


int yyerror (char *msg) {
  fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
  return 0;
}

char* _itoa(int valor, char* resultado, int base) {
    if (base < 2 || base > 36) { 
        *resultado = '\0'; return resultado; 
    }
    char* ponteiro = resultado, *ponteiro1 = resultado, tmp_char;
    int tmp_valor;

    do {
        tmp_valor = valor;
        valor /= base;
        *ponteiro++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_valor - valor * base)];
    } while ( valor );

    if (tmp_valor < 0) 
        *ponteiro++ = '-';
    *ponteiro-- = '\0';
    while(ponteiro1 < ponteiro) {
        tmp_char = *ponteiro;
        *ponteiro--= *ponteiro1;
        *ponteiro1++ = tmp_char;
    }
    return resultado;
}

