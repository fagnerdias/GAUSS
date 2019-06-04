/*
 * Descricao: Arquivo lex da linguagem GAUSS
 * Primeiro passo é:
 * Execute o comando: $ lex gauss.l
 * Após isso, se estiver tudo correto, o lex vai gerar um arquivo gauss.yy.c 
 * Faça o processo de compilação do código C gerado pelo lex: gcc -o gauss gauss.yy.c -ll 
 * As vezes tem que colocar -lfl não tenho ctz do motivo...
 * Agora pra executar é só rodar: ./gauss < arquivo_texto.txt
 */

/* Definições  C */
%{
    #include <stdio.h>
    #include "gauss.tab.h"
  
  	extern int yyerror (char *msg); 
  	int yylineno; 
%}


%%

"{" 			{ return (CHAVE_ESQUERDA); }
"}" 			{ return (CHAVE_DIREITA); }
"(" 			{ return (PARENTESE_ESQUERDA); }
")" 			{ return (PARENTESE_DIREITA); }
"[" 			{ return (COLCHETE_ESQUERDA); }
"]" 			{ return (COLCHETE_DIREITA); }
";" 			{ return (PONTO_E_VIRGULA); }
"," 			{ return (VIRGULA); }
\.				{ return (PONTO); }
":"				{ return (DOIS_PONTOS); }

"&&" 			{ return (E_LOGICO); }
"&" 			{ return (E_LOGICO_CURTO_CIRCUITO); }
"||"			{ return (OU_LOGICO); }
"|"				{ return (OU_LOGICO_CURTO_CIRCUITO); }
"!="			{ return (DIFERENTE_DE); }
"!" 			{ return (EXCLAMACAO); }


"*"				{ return (ASTERISCO); }
"%i"			{ return (PRINT_INT); }
"%."[0-9]*"f"	{ return (PRINT_FLOAT); }
"%c"			{ return (PRINT_CHAR); }
"%s"			{ return (PRINT_STRING); }
"%"				{ return (MODULO); }
"/" 			{ return (BARRA); }
"++"			{ return (INCREMENTO); }
"--"			{ return (DECREMENTO); }
"+" 			{ return (MAIS); }
"-" 			{ return (MENOS_UNARIO); }
"^" 			{ return (EXPONENCIACAO); }

"<" 			{ return (MENOR_QUE); }
">" 			{ return (MAIOR_QUE); }
"<="			{ return (MENOR_OU_IGUAL_A); }
">="			{ return (MAIOR_OU_IGUAL_A); }
"=="			{ return (IGUAL_A); }

"+="			{ return (MAIS_IGUAL); }
"-="			{ return (MENOS_IGUAL); }
"*="			{ return (VEZES_IGUAL); }
"/="			{ return (DIV_IGUAL); }
"^="			{ return (EXPONENCIACAO_IGUAL); }


"="				{ return (ATRIBUICAO); }

"?"				{ return (OPERADOR_TERNARIO); }

"JUMP" 			{ return (JUMP); }
"BREAK" 		{ return (BREAK); }
"NULL"			{ return (TNULL); }
"for"			{ return (FOR); }
"endfor"		{ return (END_FOR); }
"do"			{ return (DO); }
"while"			{ return (WHILE); }
"endwhile"		{ return (END_WHILE); }
"switch"		{ return (SWITCH); }
"endswitch"		{ return (END_SWITCH); }
"case"			{ return (CASE); }
"endcase"		{ return (END_CASE); }
"default"		{ return (DEFAULT); }
"if"			{ return (IF); }
"endif"			{ return (END_IF); }
"else"			{ return (ELSE); }
"elseif"		{ return (ELSEIF); }
"then"			{ return (THEN); }
"struct"		{ return (STRUCT); }
"endstruct"		{ return (ENDSTRUCT); }
"is"			{ return (IS); }
"end"			{ return (END); }
"func"			{ return (FUNCAO); }
"proc"			{ return (PROC); }
"return"		{ return (RETURN); }
"begin"			{ return (TBEGIN); }
"#const"		{ return (CONSTANTE); }
"printf"		{ return (PRINTF); }
"scanf"			{ return (SCANF); }



"char"			{ return (CARACTERE); }
"string"		{ return (STRING); }
"int"			{ return (INTEIRO); }
"float"			{ return (FLOAT); }
"double"		{ return (DOUBLE); }
"bool"			{ return (BOOLEANO); }
"void"			{ return (VOID); }
"true"			{ return (TRUE); }
"false"			{ return (FALSE); }
[0-9]+ 			{ return (DIGITO);}
[ \t\r]+        { /* Espaços em branco */; }
\n              { yylineno++; }
[a-zA-Z\_][a-zA-Z0-9\_]* { return (ID); }
\"(\\.|[^"])*\"	{ return (LITERAL_QUALQUER); }

"/*"((\*+[^/*])|([^*]))*\**"*/"		{ ; }	
 
 \/\/(.+)\n 			{ ; }	




%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif