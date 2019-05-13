%{
	#include<stdio.h>

	typedef struct node
	{
		struct node *left;
    	struct node *right;
    	int tokcode;
    	char *token;
  	} node;


  int yylex();
  int yyerror(char *s);
  extern int yylineno;
  extern char * yytext; 

  node *mknode(node *left, node *right, int tokcode, char *token);
  void printtree(node *tree);
  void generate(node *tree);

%}

%start prog


%token CHAVE_ESQUERDA CHAVE_DIREITA PARENTESE_ESQUERDA PARENTESE_DIREITA COLCHETE_ESQUERDA COLCHETE_DIREITA 
%token PONTO_E_VIRGULA VIRGULA PONTO
%token E_LOGICO E_LOGICO_CURTO_CIRCUITO OU_LOGICO OU_LOGICO_CURTO_CIRCUITO EXCLAMACAO
%token BARRA INCREMENTO DECREMENTO MAIS MENOS_UNARIO EXPONENCIACAO ATRIBUICAO
%token MENOR_QUE MAIOR_QUE MENOR_OU_IGUAL_A MAIOR_OU_IGUAL_A IGUAL_A DIFERENTE_DE
%token FOR END_FOR DO WHILE END_WHILE SWITCH END_SWITCH CASE END_CASE DEFAULT IF END_IF ELSE ELSEIF THEN STRUCT IS END FUNCAO RETURN BEGIN CONSTANTE PRINTF SCANF
%token CARACTERE STRING INTEIRO FLOAT DOUBLE
%token BOOLEANO TRUE FALSE
%token DIGITO
%token ID
%token LITERAL_QUALQUER


%%





%%



