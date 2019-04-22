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
%}


%%



"{" 			{ printf("CHAVE_ESQUERDA\n"); }
"}" 			{ printf("CHAVE_DIREITA\n"); }
"(" 			{ printf("PARENTESE_ESQUERDA\n"); }
")" 			{ printf("PARENTESE_DIREITA\n"); }
"[" 			{ printf("COLCHETE_ESQUERDA\n"); }
"]" 			{ printf("COLCHETE_DIREITA\n"); }
";" 			{ printf("PONTO_E_VIRGULA\n"); }
"," 			{ printf("VIRGULA\n"); }
\.				{ printf("PONTO\n"); }
"void"			{ printf("LITERAL_VOID");}

"&&" 			{ printf("E_LOGICO\n"); }
"&" 			{ printf("E_LOGICO_CURTO_CIRCUITO\n"); }
"||"			{ printf("OU_LOGICO\n"); }
"|"				{ printf("OU_LOGICO_CURTO_CIRCUITO\n"); }
"!" 			{ printf("EXCLAMACAO\n"); }


"*"				{ printf("ASTERISCO\n"); }
"%"				{ printf("MODULO\n"); }
"/" 			{ printf("BARRA\n"); }
"++"			{ printf("INCREMENTO\n"); }
"--"			{ printf("DECREMENTO\n"); }
"+" 			{ printf("MAIS\n"); }
"-" 			{ printf("MENOS_UNARIO\n"); }
"^" 			{ printf("EXPONENCIACAO\n"); }

"<" 			{ printf("MENOR_QUE\n"); }
">" 			{ printf("MAIOR_QUE\n"); }
"<="			{ printf("MENOR_OU_IGUAL_A\n"); }
">="			{ printf("MAIOR_OU_IGUAL_A\n"); }
"=="			{ printf("IGUAL_A\n"); }
"!="			{ printf("DIFERENTE_DE\n"); }


"="				{ printf("ATRIBUICAO\n"); }


"for"			{ printf("FOR\n"); }
"endfor"		{ printf("END_FOR\n"); }
"do"			{ printf("DO\n"); }
"while"			{ printf("WHILE\n"); }
"endwhile"		{ printf("END_WHILE\n"); }
"switch"		{ printf("SWITCH\n"); }
"endswitch"		{ printf("END_SWITCH\n"); }
"case"			{ printf("CASE\n"); }
"endcase"		{ printf("END_CASE\n"); }
"default"		{ printf("DEFAULT\n"); }
"if"			{ printf("IF\n"); }
"endif"			{ printf("END_IF\n"); }
"else"			{ printf("ELSE\n"); }
"elseif"		{ printf("ELSEIF\n"); }
"then"			{ printf("THEN\n"); }
"struct"		{ printf("STRUCT\n"); }
"is"			{ printf("IS\n"); }
"end"			{ printf("END\n"); }
"func"			{ printf("FUNCAO\n"); }
"return"		{ printf("RETURN\n"); }
"begin"			{ printf("BEGIN\n"); }
"#const"		{ printf("CONSTANTE\n"); }
"printf"		{ printf("PRINTF\n"); }
"scanf"			{ printf("SCANF\n"); }



"char"			{ printf("CARACTERE\n"); }
"string"		{ printf("STRING\n"); }
"int"			{ printf("INTEIRO\n"); }
"float"			{ printf("FLOAT\n"); }
"double"		{ printf("DOUBLE\n"); }
"bool"			{ printf("BOOLEANO\n"); }
"true"			{ printf("TRUE\n"); }
"false"			{ printf("FALSE\n"); }
[0-9]+ 			{ printf("LITERAL_INTEIRO\n");}
[ \t\r]+        { /* Espaços em branco */ }
\n              { yylineno++; }
[a-zA-Z\_][a-zA-Z0-9\_]* { printf("ID\n"); }
\"(\\.|[^"])*\"	{ printf("LITERAL_STRING\n"); }

%%


int main(int argc, char const *argv[])
{
	yylex();
	return 0;
}
