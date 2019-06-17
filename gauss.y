%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "tabelasimbolos.c"
  
  int yylex(void);
  int yyerror(char *s);
  extern int yylineno;
  extern char * yytext; 

  int escopo = -1;
  int contador_de_gotos_base = 0;
  int contador_de_gotos = 0;
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

%token <sValue> NUMERO_REAL FUNC_MAIN
%token <sValue> CHAVE_ESQUERDA CHAVE_DIREITA PARENTESE_ESQUERDA PARENTESE_DIREITA COLCHETE_ESQUERDA COLCHETE_DIREITA 
%token <sValue> PONTO_E_VIRGULA VIRGULA PONTO DOIS_PONTOS APONTADOR
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
%token <sValue> LITERAL_QUALQUER

%type <sValue> valor
%type <sValue> args 
%type <sValue> type expressoes
%type <sValue> decl vars atribuicoes  atribuicao_simples atribuicao_struct_valor operador operador_composto operador_comp operador_unario atribuicao_unaria atribuicao_composta print prints_list tipos_prints ids 
%type <sValue> id expressoes_list id_list registro
%type <sValue> stmt stmts if_stmt while_stmt for_stmt decl_list
%type <sValue> invoca_procedimento parametros

%start prog



%%

prog                : funcao_main {}
                    | subprog funcao_main     {}
                    | struct_list subprog funcao_main {}
                    ;

subprog             : funcao                   {}
                    | subprog funcao           {}
                    ;

stmts               : stmt              {}
                    | stmt stmts        {}
                    ;

decl                : atribuicoes {$$ = $1}
                    |type id           { 
                                            if(insertVar($2, escopo, $1)==0){
                                            
                                                char *um = $1;
                                                char *dois = $2;
                                                strcat(um," ");
                                                char *aux=( char *)malloc( strlen(um) + 1 );
                                                
                                                strcpy(aux,um);
                                                
                                                strcat(aux,dois);
                                         
                                                $$ = aux;
                                            
                                            }else{
                                                yyerror( strcat($2,": Variavel redeclarada") );
                                            }
                                        }
                    | id PONTO id                       { 
                                                            char *aux = (char *)malloc( strlen($1) + strlen($2) + 20 );
                                                            strcpy(aux,strcat($1,"."));    
                                                            $$ = strcat(aux,$3); 
                                                        }                                  
                    | type vars         { if(insertVars($2, escopo, $1)==0){

                                                char *um = $1;
                                                char *dois = $2;
                                                strcat(um," ");
                                                char *aux=( char *)malloc( strlen(um) + 1 );
                                                
                                                strcpy(aux,um);
                                                
                                                strcat(aux,dois);
                                         
                                                $$ = aux;

                                           }else{
                                                yyerror( strcat($2,": Variavel redeclarada") );
                                           }
                                        } 
                    | type vars decl    { $$ = strcat(strcat(strcat(strcat($1, " "),$2),","),$3);}

                    | type id ATRIBUICAO expressoes
                                        { 
                                            if(insertVar($2, escopo, $1)==0){

                                                //$$ = strcat(strcat(strcat(strcat($1," "), $2), $3), $4);

                                                char *aux = (char *)malloc( strlen($1) + strlen($2) + strlen($4) + strlen($4) + 40 );
                                                strcpy(aux, "");
                                                strcat(aux, $1);
                                                strcat(aux, " ");
                                                strcat(aux, $2);
                                                strcat(aux, $3);
                                                strcat(aux, $4);
                                                $$ = aux;

                                            }else{
                                                yyerror( strcat($2,": Variavel redeclarada") );
                                            }
                                        }
                    ;

struct_list         : struct                                            {}
                    | struct struct_list                                {}
                    ;

struct              : STRUCT ID IS decl_list ENDSTRUCT     
                    {
                        
                        fprintf(arquivo,"typedef struct %s {\n%s\n}%s;\n",$2, $4,$2);
                        
                    } 
                    ;

stmt                : decl PONTO_E_VIRGULA                              {makeStmt(strcat($1,";\n")); } 
                    | if_stmt                                           {}
                    | while_stmt                                        {}
                    | for_stmt                                          {}
                    //| atribuicoes PONTO_E_VIRGULA                       { makeStmt( strcat( $1, ";\n" ) ); }
                    | invoca_procedimento PONTO_E_VIRGULA               { makeStmt( strcat( $1, ";\n" ) ); }
                    | switch_stmt                                       {}
                    | print PONTO_E_VIRGULA                             {/*makeStmt(strcat(strcat($1,";"),"\n"));*/}
                    | scan PONTO_E_VIRGULA                              {}
                    | RETURN id PONTO_E_VIRGULA                         {makeStmt(strcat(strcat(strcat($1," "),$2),";\n"));}
                    ;

print               : PRINTF PARENTESE_ESQUERDA prints_list id_list PARENTESE_DIREITA {  
                                                                                    fprintf(arquivo,"printf(\"%s\", %s);\n",$3,$4);
                                                                             }
                    ;

scan                : SCANF PARENTESE_ESQUERDA prints_list id_list PARENTESE_DIREITA {
                                                                                fprintf(arquivo,"scanf(\"%s\" , &%s);\n",$3,$4);
                                                                                                } 
                    ;

id_list             : id {$$ = $1;}
                    | id VIRGULA id_list {$$ = strcat(strcat($1,","),$3);}
                    ;                    

prints_list         : tipos_prints VIRGULA                                            {$$ = strcat($2,",");}
                    | tipos_prints VIRGULA prints_list                                {$$ = strcat(strcat($2,","),$3);}
                    ;

tipos_prints        : PRINT_INT {$$ = $1;}
                    | PRINT_FLOAT {$$ = $1;}
                    | PRINT_CHAR {$$ = $1;}
                    | PRINT_STRING {$$ = $1;}
                    ;

invoca_procedimento : ID PARENTESE_ESQUERDA parametros PARENTESE_DIREITA { 
                            int retornoBusca = findFunc($1, escopo, $3);
                            if ( retornoBusca == 1 ){
                                yyerror( strcat($2,": Funcao nao declarada") );
                            }else if ( retornoBusca == 2 ) {
                                yyerror( strcat($2,": Parametros incorretos") );
                            }
                        }
                    ;
   
parametros          : {}
                    | expressoes {}
                    | expressoes VIRGULA parametros {}
                    ;  

decl_list           : decl PONTO_E_VIRGULA { $$ = strcat($1,";\n");}
                    | decl PONTO_E_VIRGULA decl_list    {$$ = strcat(strcat($1,";\n"),$3);}
                    ;


while_stmt          : WHILE PARENTESE_ESQUERDA 
                    valor PARENTESE_DIREITA
                    {   
                        escopo++;
                        contador_de_gotos++;
                        
                        fprintf(arquivo, "condicao%i:\nif(%s){\n",contador_de_gotos,$3); 
                    } stmts 
                    END_WHILE {
                            limpar_variaveis_do_escopo(escopo);
                            escopo--;
                            fprintf(arquivo,"\ngoto condicao%i;\n}\n",contador_de_gotos);
                            contador_de_gotos--;
                            if(contador_de_gotos%10 == 0)
                                contador_de_gotos+=10;
                        }
                    ;




for_stmt            : FOR PARENTESE_ESQUERDA 
                            decl PONTO_E_VIRGULA 
                            valor PONTO_E_VIRGULA 
                            atribuicoes PARENTESE_DIREITA 
                            {
                                escopo++;
                                contador_de_gotos++;
                                
                                fprintf(arquivo, "{\n%s;\n", $3);
                                fprintf(arquivo, "condicao%i:\nif(%s){\n",contador_de_gotos,$5); 

                            } 
                        stmts END_FOR  
                        {
                            limpar_variaveis_do_escopo(escopo);
                            escopo--;
                            fprintf(arquivo, "\n%s;\ngoto condicao%i;\n}\n}\n", $7, contador_de_gotos);
                            contador_de_gotos--;
                                if(contador_de_gotos%10 == 0)
                                    contador_de_gotos+=10;
                        }
                    ;                  
              


if_stmt             : IF PARENTESE_ESQUERDA valor PARENTESE_DIREITA THEN
                    {
                        escopo++;
                        fprintf(arquivo,"if(%s) {\n", $3);
                    } stmts {fprintf(arquivo,"\n}");} elses_opcoes END_IF 
                    {
                        limpar_variaveis_do_escopo(escopo);
                        escopo--;
                    }
                    ;

if_stmt_in_else     : IF PARENTESE_ESQUERDA valor PARENTESE_DIREITA THEN
                    {
                        fprintf(arquivo,"if(%s) {\n", $3);
                    } stmts {fprintf(arquivo,"\n}");} elses_opcoes {
                        
                    }

                    ;

elses_opcoes        : {}
                    | ELSE THEN 
                      {
                        fprintf(arquivo,"else {\n");
                      } stmts {
                        fprintf(arquivo,"\n}\n");
                      }
                    | ELSE {fprintf(arquivo," else ");} if_stmt_in_else {}
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

case                : CASE PARENTESE_ESQUERDA id PARENTESE_DIREITA DOIS_PONTOS 
                                { escopo++; }
                      stmts     { limpar_variaveis_do_escopo(escopo);
                                  escopo++; }
                    ;

/************ ATRIBUICOES *****/
atribuicoes         : atribuicao_simples                    {$$ = $1;}
                    | atribuicao_unaria                     {$$ = $1;}
                    | atribuicao_composta                   {$$ = $1;} 
                    | atribuicao_paralela                   {}
                    | atribuicao_struct_valor               {$$ = $1;}
                    
                    ;

                        
atribuicao_simples  : id ATRIBUICAO expressoes { printf("debug\n"); $$ = strcat(strcat($1, $2),$3);}
                    | id ATRIBUICAO id PARENTESE_ESQUERDA args PARENTESE_DIREITA 
                        {
                        printf("debug8\n");

                            $$ = strcat(strcat(strcat(strcat(strcat($1,"="),$3),"("),$5),")");
                        }
                    ;

atribuicao_struct_valor  : id PONTO id ATRIBUICAO expressoes 
                    { 

                        char *um = $1;
                        char *dois = $2;
                        char *tres = $3;
                        char *quatro = $4;
                        char *cinco = $5;
                        char *aux1=( char *)malloc( strlen(um) + 1 );
                        char *aux2=( char *)malloc( strlen(dois) + 1 );
                        char *aux3=( char *)malloc( strlen(tres) + 1 );
                        char *aux4=( char *)malloc( strlen(quatro) + 1 );
                        char *aux5=( char *)malloc( strlen(cinco) + 1 );
                        strcpy(aux1,um);
                        strcpy(aux2,dois);
                        strcpy(aux3,tres);
                        strcpy(aux4,quatro);
                        strcpy(aux5,cinco);
                        char *aux6 = strcat(aux1,".");
                        char *aux9 = strcat(aux6,$3);
                        char *aux7 = strcat(aux9,$2);
                        char *aux8 = strcat(aux7, $4);
                        strcat(aux8,aux5);
                        $$ = aux8;

                    }
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
                    | BARRA             {$$ = $1;}
                    | ASTERISCO         {$$ = $1;}
                    | MODULO            {$$ = $1;}
                    | EXPONENCIACAO     {$$ = $1;}
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
                    | registro      {$$ = $1;}  
                    ;

registro            : PONTO ID            {
printf("entrouuu\n");
                        $$ = $2;
                    }
                    ;                    
 
/*Colocar demais operadores*/


valor               : expressoes E_LOGICO expressoes    {$$ = strcat(strcat($1,$2),$3);}  
                    | expressoes OU_LOGICO expressoes   {$$ = strcat(strcat($1,$2),$3);}   
                    | expressoes                        {printf("ffffff\n");$$ = $1;}                          
                    ;

expressoes          : id                    {printf("debug3\n");$$ = $1;}
                    | id operador id        { printf("debug2\n");
                                            if (strcmp($2,"^") == 0){
                                                char teste[100];
                                                sprintf(teste,"pow(%s,%s)",$1,$3);
                                                $$ = teste;
                                            }
                                            else if (strcmp($2,"-") == 0){
                                                char teste[100];
                                                sprintf(teste,"%s-%s",$1,$3);
                                                $$ = teste;
                                            }
                                            else {
                                                $$ = strcat(strcat($1,$2),$3);}
                                            }
                    | id operador_comp id   {$$ = strcat(strcat($1,$2),$3);}

                    ;



            

expressoes_list      : expressoes VIRGULA expressoes { $$ = strcat(strcat($1,","),$3);}
                    ;                                        

vars                : ID VIRGULA ID     { $$ = strcat(strcat($1,","),$3); }
                    | ID VIRGULA vars   { $$ = strcat(strcat($1,","),$3); }
                    ;
//argumento
args                :                                                           { $$ = ""; }
                    | type ID                                                   {$$ = strcat(strcat($1, " "),$2);}
                    | id                                                        {$$ = $1;}
                    | type ID COLCHETE_ESQUERDA COLCHETE_DIREITA VIRGULA args   {char teste[15];sprintf(teste, "%s %s[], %s",$1,$2,$6); $$ = teste; }
                    | id VIRGULA args                                      
                    {
                        printf("debug22\n");
                        char teste[100]; 
                        sprintf(teste,"%s, %s",$1,$3); 
                        //printf(teste);
                        $$ = teste; 
                        //printf("debugfim\n");
                    }      
                    | type id VIRGULA args                                      
                    {
                        //printf("debug\n");
                        char teste[100]; 
                        sprintf(teste,"%s %s,%s",$1,$2,$4); 
                        //printf(teste);
                        $$ = teste; 
                        //printf("debugfim\n");
                    }
              
                    ;

funcao_main         : FUNC_MAIN IS TBEGIN {  escopo++; 
                                makeStmt("\n\n");
                                makeStmt( "int main(){ \n" );

                             } 
                        stmts END  
                             {
                                limpar_variaveis_do_escopo(escopo);
                                escopo--;
                                makeStmt("}\n\n"); 
                             }
                    ;

funcao              : FUNCAO ID  PARENTESE_ESQUERDA args PARENTESE_DIREITA RETURN type IS
                      TBEGIN {  escopo++; 
                                makeStmt("\n\n");

                                char *aux = (char *)malloc( strlen($6) + strlen($2) + 2 );
                                char *aux2 = (char *)malloc( strlen("(") + 1 );
                                char *aux3 = (char *)malloc( strlen("){\n") + 1 );
                                strcpy(aux, "");
                                strcat(aux, $7);
                                strcat(aux, " ");
                                strcat(aux, $2);
                                strcat(aux, "(");
                                strcat(aux, $4);
                                strcat(aux, "){\n");

                                makeStmt( aux ) ;
                                //makeStmt(strcat(strcat(strcat(strcat(strcat($7," "),$2),"("),$4),"){\n"));
                             } 
                        stmts END ID  
                             {
                                limpar_variaveis_do_escopo(escopo);
                                escopo--;
                                makeStmt("}\n\n"); }
                    ;

id                  : 
                     DIGITO                                            { char teste[10]; $$ = _itoa($1,teste,10);}
                    | NUMERO_REAL                                     { 
                        //printf( "%f", $1);
                                                                            char teste[10];
                                                                            //sprintf(teste, "%f", $1);
                                                                            $$ = $1;
                                                                        }
                    | ID COLCHETE_ESQUERDA expressoes COLCHETE_DIREITA COLCHETE_ESQUERDA expressoes COLCHETE_DIREITA  
                    { 
                        printf("matriz\n");
                        $$ = strcat(strcat(strcat(strcat(strcat($1,"["),$3),"]["),$6),"]");
                    }                    
                    | ID COLCHETE_ESQUERDA expressoes COLCHETE_DIREITA  { $$ = strcat(strcat(strcat($1,"["),$3),"]");}

                    | PARENTESE_ESQUERDA expressoes PARENTESE_DIREITA   { $$ = strcat(strcat(strcat($1,"("),$3),")");}
                    | LITERAL_QUALQUER                                  { $$ = $1; }
                    | ids                                                {$$=$1}
                    | MENOS_UNARIO DIGITO                               {
                                                                            char teste[10]; 
                                                                            _itoa($2,teste,10);
                                                                            $$ = strcat($1,teste);
                                                                        }
                    | MENOS_UNARIO ID                               {

                                                                            $$ = strcat($1,$2);
                                                                        } 
                    //| ID                                                { $$ = $1; }                                                                       
                    ;

ids : ID                                                { $$ = $1; }
    | ID APONTADOR ID                                       { 
                                                            char *aux = (char *)malloc( strlen($1) + strlen($2) + 20 );
                                                            strcpy(aux,strcat($1,"."));    
                                                            $$ = strcat(aux,$3); 
                                                        }
;

%%

int main (void) {

    arquivo = fopen("compilado.c", "w+");

    fprintf (arquivo, "#include <%s>\n#include <%s>\n","stdio.h","math.h");

    iniciaVetorVar();
    yyparse ( );

    fclose(arquivo);

    return 1;
}

void makeStmt(char* stmt){
    
    fprintf (arquivo, "%s",stmt);
}


int yyerror (char *msg) {
  fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
  exit(1);
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
