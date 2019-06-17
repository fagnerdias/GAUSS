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
    #include <string.h>
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
";" 			{ yylval.sValue = strdup(";");return (PONTO_E_VIRGULA); }
"," 			{ return (VIRGULA); }
\.				{ return (PONTO); }
":"				{ return (DOIS_PONTOS); }

"&&" 			{ yylval.sValue = strdup("&&");return (E_LOGICO); }
"&" 			{ yylval.sValue = strdup("&");return (E_LOGICO_CURTO_CIRCUITO); }
"||"			{ yylval.sValue = strdup("||");return (OU_LOGICO); }
"|"				{ yylval.sValue = strdup("|");return (OU_LOGICO_CURTO_CIRCUITO); }
"!="			{ yylval.sValue = strdup("!=");return (DIFERENTE_DE); }
"!" 			{ yylval.sValue = strdup("!");return (EXCLAMACAO); }


"*"				{ yylval.sValue = strdup("*");return (ASTERISCO); }
"%i"			{ yylval.sValue = strdup("%i");return (PRINT_INT); }
"%."[0-9]*"f"	{ yylval.sValue = strdup("%.4f");return (PRINT_FLOAT); }
"%c"			{ yylval.sValue = strdup("%c");return (PRINT_CHAR); }
"%s"			{ yylval.sValue = strdup("%s");return (PRINT_STRING); }
"%"				{ yylval.sValue = strdup("%");return (MODULO); }
"/" 			{ yylval.sValue = strdup("/");return (BARRA); }
"++"			{ yylval.sValue = strdup("++");return (INCREMENTO); }
"--"			{ yylval.sValue = strdup("--");return (DECREMENTO); }


"<="			{ yylval.sValue = strdup("<=");return (MENOR_OU_IGUAL_A); }
">="			{ yylval.sValue = strdup(">=");return (MAIOR_OU_IGUAL_A); }
"=="			{ yylval.sValue = strdup("==");return (IGUAL_A); }

"+="			{ yylval.sValue = strdup("+=");return (MAIS_IGUAL); }
"-="			{ yylval.sValue = strdup("-=");return (MENOS_IGUAL); }
"*="			{ yylval.sValue = strdup("*=");return (VEZES_IGUAL); }
"/="			{ yylval.sValue = strdup("/=");return (DIV_IGUAL); }
"^="			{ yylval.sValue = strdup("^=");return (EXPONENCIACAO_IGUAL); }


"="				{ yylval.sValue = strdup("=");return (ATRIBUICAO); }

"?"				{ yylval.sValue = strdup("?");return (OPERADOR_TERNARIO); }

"->" 			{ yylval.sValue = strdup("->");return (APONTADOR); }

"<" 			{ yylval.sValue = strdup("<");return (MENOR_QUE); }
">" 			{ yylval.sValue = strdup(">");return (MAIOR_QUE); }
"+" 			{ yylval.sValue = strdup("+");return (MAIS); }
"-" 			{ yylval.sValue = strdup("-");return (MENOS_UNARIO); }
"^" 			{ yylval.sValue = strdup("^");return (EXPONENCIACAO); }

"main"			{ yylval.sValue = strdup("main");return (FUNC_MAIN); }
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
"return"		{ yylval.sValue = strdup("return");return (RETURN); }
"begin"			{ return (TBEGIN); }
"#const"		{ return (CONSTANTE); }
"printf"		{ return (PRINTF); }
"scanf"			{ return (SCANF); }



"char"			{ yylval.sValue = strdup("caractere");return (CARACTERE); }
"string"		{ yylval.sValue = strdup("char*");return (STRING); }
"int"			{ yylval.sValue = strdup("int");return (INTEIRO); }
"float"			{ yylval.sValue = strdup("float");return (FLOAT); }
"double"		{ yylval.sValue = strdup("double");return (DOUBLE); }
"bool"			{ yylval.sValue = strdup("bool");return (BOOLEANO); }
"void"			{ yylval.sValue = strdup("void");return (VOID); }
"true"			{ yylval.sValue = strdup("true");return (TRUE); }
"false"			{ yylval.sValue = strdup("false");return (FALSE); }
[0-9]*\.[0-9]+  { yylval.sValue = strdup(yytext); return(NUMERO_REAL);}
[0-9]+ 			{ yylval.sValue = strdup(yytext);return (DIGITO);}
[ \t\r]+        { /* Espaços em branco */; }
\n              { yylineno++; }
[a-zA-Z\_][a-zA-Z0-9\_]* { yylval.sValue = strdup(yytext);return (ID); }
\"(\\.|[^"])*\"	{ yylval.sValue = strdup(yytext); return (LITERAL_QUALQUER); }

"/*"((\*+[^/*])|([^*]))*\**"*/"		{ ; }	
 
 \/\/(.+)\n 			{ ; }	




%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif
