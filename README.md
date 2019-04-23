
# Linguagem de Programação GAUSS

Projeto da disciplina de engenharia de linguagens do curso de Engenharia de Software da UFRN. O projeto consiste no desenvolvimento de uma linguagem de programação tendo como  público-alvo matemáticos, em particular, estatísticos. 




## Como testar o lex?

 1. Primeiro passo:

	1.1.  Execute o comando: $ lex lexico.l

	1.2. Após isso, se estiver tudo correto, o lex vai gerar um arquivo lex.yy.c

 2. Segundo passo:

	2.1. Faça o processo de compilação do código C gerado pelo lex: gcc -o gauss lex.yy.c -ll (ou -lfl)

 3. Terceiro passo:

	3.1 Agora pra executar é só rodar: ./gauss < arquivo_texto.txt

# Equipe	


|  Alunos                       |Curso|
|-------------------------------|-----|
| Adelino Avelino			    | BES |
| Fagner Dias 					| BES |
| Ester Bárbara 				| BES |



|  Professor                    |             	Email				|
|-------------------------------|-----------------------------------|
|  Umberto Costa				|  umberto@dimap.ufrn.br 			|
|  Departamento 				|  DIMAp - UFRN 					|
