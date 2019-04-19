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

"{" 	{ return CHAVE_ESQUERDA; }
"}" 	{ return CHAVE_DIREITA; }
"(" 	{ return PARENTESE_ESQUERDA; }
")" 	{ return PARENTESE_DIREITA; }
"[" 	{ return COLCHETE_ESQUERDA; }
"]" 	{ return COLCHETE_DIREITA; }
";" 	{ return PONTO_E_VIRGULA; }
"," 	{ return VIRGULA; }
\. 		{ return PONTO; }

&{2} 	{ return E_LOGICO; }
"&" 	{ return E_LOGICO_CURTO_CIRCUITO; }
|{2}	{ return OU_LOGICO; }
"|"		{ return OU_LOGICO_CURTO_CIRCUITO; }
"!" 	{ return EXCLAMASCAO; }


"*"		{ return ASTERISCO; }
"%"		{ return MODULO; }
"/" 	{ return BARRA; }
"\" 	{ return CONTRA_BARRA; }
"+" 	{ return MAIS; }
"-" 	{ return MENOS; }

"<" 	{ return MENOR_QUE; }
">" 	{ return MAIOR_QUE; }
"<="	{ return MENOR_OU_IGUAL_A; }
">="	{ return MAIOR_OU_IGUAL_A; }
={2}	{ return IGUAL_A; }
"!="	{ return DIFERENTE_DE; }


+{2}       { return INCREMENTO; }
-{2}       { return DECREMENTO; }
"="        { return ATRIBUICAO; }










%%


int main(int argc, char const *argv[])
{
	yylex();
	return 0;
}