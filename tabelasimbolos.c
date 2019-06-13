#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TABELASIMBOLOS
#define TABELASIMBOLOS

typedef struct Var
{
	char *id;
	int escopo;
	char *tipo;
}Var;

typedef struct Func
{
	char *id;
	int escopo;
	char *tipoRetorno;
	char *tipoParams;
	int qntParams;

}Func;

Var vetorVar[100];
int sizeVectorVar = 0;

Func vetorFunc[100];
int sizeVectorFunc = 0;

int printVar(){
	printf("[ ");
	for(int i=0; i<sizeVectorVar; i++){
		printf("%s - %i - %s ", vetorVar[i].id, vetorVar[i].escopo, vetorVar[i].tipo);
	}
	printf(" ]\n");
	return 0;
}
int printFunc(){
	printf("[ ");
	for(int i=0; i<sizeVectorFunc; i++){
		printf("( %s - %i - %s )", vetorFunc[i].id, vetorFunc[i].escopo, vetorFunc[i].tipoRetorno);
	}
	printf(" ]\n");
	return 0;
}

/*metodo para auxiliar a inserção de uma variavel na tabela de simbolos */
int findVarToInsert(char *id, int escopo) {
	for( int i=0; i<sizeVectorVar; i++ ) {
		if( strcmp(id, vetorVar[i].id) == 0 ) { //encontrado equivalente no vetor
			return 0; //encontrou id, var declarada
		}
	}
	return 1; //nao encontrou, funcao nao declarada
}
/* método para verificar se a chamada de uma variavel é valida */
int findVar(char *id, int escopo){
	if( findVarToInsert(id, escopo) == 1 ) {
		printf("erro: %s - variavel nao declarada\n", id);
		return 1; // erro
	}
	return 0; //encontrou var
}

/* insere a variavel no vetor caso nao a encontre ja declarada */
int insertVar(char *id, int escopo, char *tipo){

	if( findVarToInsert(id, escopo) == 0 ){ //encontrada declarada
		printf("erro: %s - variavel ja declarada previamente\n", id);
		return 1; //erro
	}

	Var temp;
	temp.id = id;
	temp.escopo = escopo;
	temp.tipo = tipo;

	vetorVar[sizeVectorVar] = temp;
	sizeVectorVar++;
	
	printf("sucesso: %s - variavel foi declarada \n", id);
	return 0; //inseriu a variavel com sucesso
}

/*metodo para auxiliar a inserção de uma funcao/procedimento na tabela de simbolos */
int findFuncToInsert(char *id, int escopo) {
	for( int i=0; i<sizeVectorFunc; i++ ) {
		if( strcmp(id, vetorFunc[i].id) == 0 ) { //encontrado equivalente no vetor
			return 0; //encontrou id, funcao declarada
		}
	}
	return 1; //nao encontrou, funcao nao declarada
}

/* método para verificar se a chamada de um procedimento/funcao é valida */
int findFunc(char *id, int escopo) {
	if( findFuncToInsert(id, escopo) == 1 ) { //se procedimento/funcao não foi encontrado, não é válida
		printf("erro: %s - procedimento nao declarado\n", id);
		return 1; //erro
	}
	return 0; //encontrou func, é valida
}

/* insere a funcao no vetor caso nao a encontre ja declarada */
int insertFunc(char *id, int escopo, char *tipoRetorno, char *tipoParams) {
	
	if( findFuncToInsert(id, escopo) == 0 ){ //encontrada declarada
		printf("erro: %s - procedimento/funcao ja declarado previamente\n", id);
		return 1; //erro
	}

	Func temp;
	temp.id = id;
	temp.escopo = escopo;
	temp.tipoRetorno = tipoRetorno;
	temp.tipoParams = tipoParams;
	//temp.qntParams = qntParams; //lembrar de implementar, sepa

	vetorFunc[sizeVectorVar] = temp;
	sizeVectorFunc++;
	return 1;

	printf("sucesso: %s - procedimento/funcao foi declarado(a) \n", id);
	return 0; //inseriu o procedimento/funcao com sucesso
}

//int main(){return 0;}

#endif