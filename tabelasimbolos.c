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

int findVar(char *id, int escopo){
	for(int i=0; i<sizeVectorVar; i++){
		printf("%i\n", strcmp(id, vetorVar[i].id));
		if(strcmp(id, vetorVar[i].id)==0){
			return 1;
		}
	}
	//printf("%s : variavel nao declarada\n", id);
	return 0;
}
int findFunc(char *id, int params){
	for(int i=0; i<sizeVectorFunc; i++){
		if(strcmp(id, vetorFunc[i].id)){
			return 1;
		}
	}
	//printf("%s : procedimento nao declarada\n", id);
	return 0;
}
int printVar(){
	printf("[ ");
	for(int i=0; i<sizeVectorVar; i++){
		printf("%s - %i - %s ", vetorVar[i].id, vetorVar[i].escopo, vetorVar[i].tipo);
	}
	printf(" ]\n");
	return 0;
}

void insertVar(char *id, int escopo, char *tipo){

	//printVar();
	//printf("---\n");
	if(findVar(id, escopo)==1){
		printf("%s : variavel ja declarada antes\n", id);
		return;
	}

	Var temp;
	temp.id = id;
	temp.escopo = escopo;
	temp.tipo = tipo;

	vetorVar[sizeVectorVar] = temp;
	sizeVectorVar++;
	//printVar();
	printf("%i\n", sizeVectorVar);
}
void insertFunc(char *id, int escopo, char *tipoRetorno, char *tipoParams){
	
	if(findFunc(id, escopo)==1){
		printf("%s : procedimento ja declarada antes\n", id);
		return;
	}else{
		printf("%s : procedimento salvo na tabela \n", id);
	}

	Func temp;
	temp.id = id;
	temp.escopo = escopo;
	temp.tipoRetorno = tipoRetorno;
	temp.tipoParams = tipoParams;
	//temp.qntParams = qntParams; //lembrar de implementar, sepa

	vetorFunc[sizeVectorVar] = temp;
	sizeVectorFunc++;

}

//int main(){return 0;}

#endif