#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TABELASIMBOLOS
#define TABELASIMBOLOS

typedef enum {
    Tint, Tfloat,Tdouble, Tbool, caractere, string, Tvoid
} tipo_t;

typedef struct Var
{
	char *id;
	int escopo;
	tipo_t tipo;
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


int findVarToInsert(char *id, int escopo){
	for(int i=0; i<sizeVectorVar; i++){
		if(strcmp(id, vetorVar[i].id)==0){
			return 1;
		}
	}
	return 0;
}
int findVar(char *id, int escopo){
	if(findVarToInsert(id, escopo)==0){
		printf("%s : variavel nao declarada\n", id);
		return 1;
	}
	return 0;
}
int findFuncToInsert(char *id, int escopo){
	for(int i=0; i<sizeVectorFunc; i++){
		if(strcmp(id, vetorFunc[i].id)==0){
			return 1;
		}
	}
	return 0;
}

int findFunc(char *id, int escopo){
	if(findFuncToInsert(id, escopo)==0){
		printf("%s : procedimento nao declarado\n", id);
	}
	return 0;
}

Var getVarInfo(char *id, int escopo){
	Var tmp;
	if(findVar(id,escopo) == 0){
		for(int i=0; i<sizeVectorVar; i++){
			if(strcmp(id, vetorVar[i].id)==0){
				return vetorVar[i];
			}
		}	
	}
	else
		return tmp;
}

char* getTipo(tipo_t tipo){
	switch(tipo){
        case Tint:
            return "int";
        case Tfloat:
            return "float";
        case Tdouble:
            return "double";
        case caractere:
            return "caractere";
        case string:
            return "string";
        case Tvoid:
            break;
	}
}

char* makePrint(char *id, int escopo){
	Var tmp = getVarInfo(id,escopo);
	char* str = "printf(\"";
	if (strcmp(getTipo(tmp.tipo),"Tint")==0)
		str = strcat(str, "%i");
	if (strcmp(getTipo(tmp.tipo),"Tfloat")==0)
		str = strcat(str, "%f");
	if (strcmp(getTipo(tmp.tipo),"Tdouble")==0)
		str = strcat(str, "%d");
	if (strcmp(getTipo(tmp.tipo),"caractere")==0)
		str = strcat(str, "%c");
	if (strcmp(getTipo(tmp.tipo),"string")==0)
		str = strcat(str, "%s");
	str = strcat(str,"\", ");
	str = strcat(str,id);

	return str;

}

int insertVar(char *id, int escopo, char *tipo){

	if(findVarToInsert(id, escopo)==1){
		printf("%s : variavel ja declarada antes\n", id);
		return 0;
	}else{
		printf("%s : var salva na tabela \n", id);
	}

	Var temp;
	temp.id = id;
	temp.escopo = escopo;
	if (strcmp(tipo,"Tint")==0)
		temp.tipo = 0;
	if (strcmp(tipo,"Tfloat")==0)
		temp.tipo = 1;
	if (strcmp(tipo,"Tdouble")==0)
		temp.tipo = 2;
	if (strcmp(tipo,"caractere")==0)
		temp.tipo = 3;
	if (strcmp(tipo,"string")==0)
		temp.tipo = 4;

	vetorVar[sizeVectorVar] = temp;
	sizeVectorVar++;
	return 1;
}
int insertFunc(char *id, int escopo, char *tipoRetorno, char *tipoParams){
	
	if(findFuncToInsert(id, escopo)==1){
		printf("%s : procedimento ja declarado antes\n", id);
		return 0;
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
	return 1;

}

//int main(){return 0;}

#endif