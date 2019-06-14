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
  FILE *arquivo;
  

  //typedef enum {false, true} bool;

  char* _itoa(int valor, char* resultado, int base);
  void makeStmt(char* stmt);
  void limparBuffer();

%}

%union {
  int    iValue;  /* integer value */
  float  fValue;  /* float value */
  double dValue;  /* double value */
  int   bValue;  /* boolean value */
  char   cValue;  /* char value */
  char * sValue;  /* string value */
}

%token <sValue> CHAVE_ESQUERDA CHAVE_DIREITA PARENTESE_ESQUERDA PARENTESE_DIREITA COLCHETE_ESQUERDA COLCHETE_DIREITA 
%token <sValue> PONTO_E_VIRGULA VIRGULA PONTO DOIS_PONTOS
%token <sValue> E_LOGICO E_LOGICO_CURTO_CIRCUITO OU_LOGICO OU_LOGICO_CURTO_CIRCUITO EXCLAMACAO
%token <sValue> ASTERISCO PRINT_INT PRINT_FLOAT PRINT_CHAR PRINT_STRING MODULO
%token <sValue> BARRA INCREMENTO DECREMENTO MAIS MENOS_UNARIO EXPONENCIACAO ATRIBUICAO OPERADOR_TERNARIO
%token <sValue> MENOR_QUE MAIOR_QUE MENOR_OU_IGUAL_A MAIOR_OU_IGUAL_A IGUAL_A DIFERENTE_DE
%token <sValue> MAIS_IGUAL MENOS_IGUAL VEZES_IGUAL DIV_IGUAL EXPONENCIACAO_IGUAL
%token <sValue> FOR END_FOR DO WHILE END_WHILE SWITCH END_SWITCH CASE END_CASE DEFAULT 
%token IF END_IF ELSE ELSEIF THEN STRUCT ENDSTRUCT IS END 
%token <sValue> FUNCAO PROC RETURN TBEGIN CONSTANTE PRINTF SCANF 
%token <sValue> CARACTERE STRING INTEIRO FLOAT DOUBLE VOID
%token <sValue> BOOLEANO TRUE FALSE JUMP BREAK TNULL
%token <iValue> DIGITO
%token <sValue> ID
%token LITERAL_QUALQUER


%type <sValue> valor
%type <sValue> args type 
%type <sValue> decl vars atribuicoes expressoes atribuicao_simples operador operador_composto operador_comp operador_unario atribuicao_unaria atribuicao_composta print ids types_args prints_list tipos_prints
%type <sValue> id lista_de_digitos vetorial
%type <sValue> stmt stmts if_stmt while_stmt for_stmt

%start prog



%%
prog                : subprog       {}
                    | struct_list subprog   {}
                    ;

subprog             : funcao                    {}
                    | subprog funcao            {}
                    ;

stmts               : stmt              {}
                    | stmt stmts        { }
                    ;

decl                : type id           { $$ = strcat(strcat($1," "),$2); }
                    | type vars         { $$ = strcat(strcat($1," "),$2); } 
                    | type vars decl    { $$ = strcat(strcat(strcat(strcat($1, " "),$2),","),$3);}
                    | type atribuicoes  { $$ = strcat(strcat($1, " "),$2);}
                    ;

struct_list         : struct                                            {}
                    | struct struct_list                                {}
                    ;

struct              : STRUCT ID IS decl_list ENDSTRUCT                  {}
                    ;

stmt                : decl PONTO_E_VIRGULA                              {makeStmt(strcat(strcat($1,";"),"\n"));} 
                    | if_stmt                                           {makeStmt($1);}
                    | while_stmt                                        {makeStmt($1);} 
                    | for_stmt                                          {makeStmt($1);}
                    | atribuicoes PONTO_E_VIRGULA                       {makeStmt(strcat(strcat($1,";"),"\n"));}
                    | invoca_procedimento PONTO_E_VIRGULA               {}
                    | switch_stmt                                       {}
                    | print PONTO_E_VIRGULA                             {/*makeStmt(strcat(strcat($1,";"),"\n"));*/}
                    | scan PONTO_E_VIRGULA                              {}
                    | RETURN id PONTO_E_VIRGULA                         {}
                    ;

print               : PRINTF PARENTESE_ESQUERDA expressoes PARENTESE_DIREITA {
                                                                             $$ = gerar_imprima($3);
                                                                             } 
                    ;

scan                : SCANF PARENTESE_ESQUERDA args_print PARENTESE_DIREITA {} 
                    ;

args_print          : ids types_args{ printf("teste ids - %s, types - %s",$1,$2);}
                    ;

ids                 : expressoes {
                                    printf("teste = %s\n",$1);
                                    $$ = $1;
                                }
                    | ids VIRGULA expressoes  {
                                                $$ = strcat(strcat($1,","),$3);
                                                }
                    ;

types_args          :                                            {$$ = "";}
                    | prints_list                                {printf("teste = %s\n",$1);$$ = $1;}
                    ;

prints_list         : VIRGULA tipos_prints                                            {$$ = strcat(",",$2);}
                    | VIRGULA tipos_prints prints_list                                {$$ = strcat(strcat(",",$2),$3);}
                    ;

tipos_prints        : PRINT_INT {$$ = $1;}
                    | PRINT_FLOAT {$$ = $1;}
                    | PRINT_CHAR {$$ = $1;}
                    | PRINT_STRING {$$ = $1;}
                    ;

invoca_procedimento : ID PARENTESE_ESQUERDA parametros PARENTESE_DIREITA { findFunc($1, escopo); }
                    ;
   
parametros          : expressoes {}
                    | expressoes VIRGULA parametros {}
                    ;  

decl_list           : decl PONTO_E_VIRGULA {}
                    | decl PONTO_E_VIRGULA decl_list    {}
                    ;

while_stmt          : WHILE PARENTESE_ESQUERDA 
                    valor PARENTESE_DIREITA
                    {
                        char* inicio = "condicao:\n\tif(";
                        sprintf(buffer, "condicao:\n\tif(%s)\n\t\tgoto inicio;\n\telse\n\t\tgoto fim;\ninicio:\n",$3);
                        
                        makeStmt(buffer);
                    } stmts 
                    
                    END_WHILE {makeStmt("\tgoto condicao;\nfim:\n");}
                    ;

for_stmt            : FOR PARENTESE_ESQUERDA 
                            decl PONTO_E_VIRGULA 
                            valor PONTO_E_VIRGULA 
                            {
                                printf("declaração - %s\n",$3);
                              fprintf(arquivo, "%s;\n", $3);
                              fprintf(arquivo, "condicao:\n\tif(%s)\n\t\tgoto inicio;\n\telse\n\t\tgoto fim;\ninicio:\n",$5);
                            }
                            atribuicoes PARENTESE_DIREITA 
                        stmts END_FOR  
                        {
                            printf("atribução - %s",$1);
                            printf("atribução - %s",$3);
                            fprintf(arquivo, "teste-\n%s\n", $1);
                          fprintf(arquivo, "\n%s\n", $1);
                          fprintf(arquivo, "fim:\n");
                        }
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
atribuicoes         : atribuicao_simples                    { $$ = $1;}
                    | atribuicao_unaria                     { $$ = $1;}
                    | atribuicao_composta                   { $$ = $1;} 
                    | atribuicao_paralela                   {}
                    ;

atribuicao_simples  : id ATRIBUICAO expressoes { $$ = strcat(strcat($1, $2),$3);}
                    ;

atribuicao_unaria   : id operador_unario                   {$$ = strcat($1,$2);}
                    | operador_unario ID                   {$$ = strcat($1,$2);}
                    ;

atribuicao_composta : id operador_composto valor     {$$ = strcat(strcat($1,$2),$3);}
                    ;

atribuicao_paralela : vars ATRIBUICAO expressoes_list {}
                    ;

operador_unario     : INCREMENTO        {$$ = $1;}
                    | DECREMENTO        {$$ = $1;}
                    ;

operador            : MAIS              {$$ = $1;}           
                    | MENOS_UNARIO      {$$ = $1;}
                    | EXPONENCIACAO     {$$ = $1;}
                    | BARRA             {$$ = $1;}
                    | MODULO            {$$ = $1;}
                    ;
                    
operador_comp       : MENOR_QUE         {$$ = $1;}
                    | MAIOR_QUE         {$$ = $1;}
                    | MENOR_OU_IGUAL_A  {$$ = $1;}
                    | MAIOR_OU_IGUAL_A  {$$ = $1;}
                    | IGUAL_A           {$$ = $1;}
                    | DIFERENTE_DE      {$$ = $1;}
                    ;

operador_composto   : MAIS_IGUAL                      {$$ = $1;}
                    | MENOS_IGUAL                     {$$ = $1;}
                    | VEZES_IGUAL                     {$$ = $1;}
                    | DIV_IGUAL                       {$$ = $1;}
                    | EXPONENCIACAO_IGUAL             {$$ = $1;}
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


valor               : expressoes E_LOGICO expressoes    {$$ = strcat(strcat($1,$2),$3);}  
                    | expressoes OU_LOGICO expressoes   {$$ = strcat(strcat($1,$2),$3);}   
                    | expressoes                        {$$ = $1;}                          
                    ;

expressoes          : {}
                    | id                    {$$ = $1;}
                    | id operador id        {$$ = strcat(strcat($1,$2),$3);}
                    | id operador_comp id   {$$ = strcat(strcat($1,$2),$3);}
                    | vetorial              {/*$$ = $1;*/} 
                    ;

vetorial            : CHAVE_ESQUERDA lista_de_digitos CHAVE_DIREITA { 
                                                                    /*$$ = "2";*/
                                                                    }  
                        
                    ;   
lista_de_digitos    : DIGITO                            {$$ = _itoa($1,buffer,10);}
                    | DIGITO VIRGULA lista_de_digitos   {$$ = strcat(strcat(_itoa($1,buffer,10),";"),$2);}
                    ;               

expressoes_list      : expressoes VIRGULA expressoes {}
                    ;                                        

vars                : ID VIRGULA ID     { $$ = strcat(strcat($1,","),$3); }
                    | ID VIRGULA vars   { $$ = strcat(strcat($1,","),$3); }
                    ;

args                :                                                           { $$ = ""; }
                    | type ID                                                   { $$ = strcat(strcat($1, " "),$2); }
                    | type ID COLCHETE_ESQUERDA COLCHETE_DIREITA VIRGULA args   {sprintf(buffer, "%s %s[], %s",$1,$2,$6); $$ = buffer; }
                    | type ID VIRGULA args                                      {sprintf(buffer,"%s %s,%s",$1,$2,$4); $$ = buffer; }
                    ;

funcao              : FUNCAO ID  PARENTESE_ESQUERDA args 
                      PARENTESE_DIREITA RETURN type IS
                      TBEGIN { insertFunc($2, escopo, $7, $4); escopo++; 
                                makeStmt(strcat(strcat(strcat(strcat(strcat($7," "),$2),"("),$4),"){\n"));
                                } stmts END ID  
                      { makeStmt("}");}
                    ;

id                  : ID                                                { $$ = $1; }
                    | DIGITO                                            { $$ = _itoa($1,buffer,10);}
                    | ID COLCHETE_ESQUERDA expressoes COLCHETE_DIREITA  { $$ = strcat(strcat(strcat($1,"["),$3),"]");}
                    | PARENTESE_ESQUERDA expressoes PARENTESE_DIREITA   { $$ = strcat(strcat(strcat($1,"("),$3),")");}
                    ;
%%

int main (void) {

    arquivo = fopen("compilado.c", "w+");

    fprintf (arquivo, "#include <%s>\n","stdio.h");

    yyparse ( );

    fclose(arquivo);
    
    return 1;
}

void makeStmt(char* stmt){
    printf("%s\n",stmt);
    fprintf (arquivo, "%s",stmt);
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
