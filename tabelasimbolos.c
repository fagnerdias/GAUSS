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
	char *tipoExtenso;
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


/************************************/
/***         Auxiliares           ***/
/************************************/
//char** split(char *vars);
int split (char *str, char c, char ***arr);
int printVar();

/************************************/
/***        Decl Variaveis        ***/
/************************************/

/*metodo para auxiliar a inserção de uma variavel na tabela de simbolos */
int findVarToInsert(char *id, int escopo, char *tipo) {
	for( int i=0; i<sizeVectorVar; i++ ) {
		if( strcmp(id, vetorVar[i].id) == 0 && strcmp(tipo, vetorVar[i].tipoExtenso) == 0 ) { //encontrado equivalente no vetor
			return 0; //encontrou id, var declarada
		}
	}
	return 1; //nao encontrou, funcao nao declarada
}
/* método para verificar se a chamada de uma variavel é valida */
int findVar(char *id, int escopo, char *tipo){
	if( findVarToInsert(id, escopo, tipo) == 1 ) {
		printf("erro: %s - variavel nao declarada\n", id);
		return 1; // variavel nao encontrada
	}
	return 0; //encontrou var
}
/* insere a variavel no vetor caso nao a encontre ja declarada */
int insertVar(char *id, int escopo, char *tipo){
	if(findVarToInsert(id, escopo, tipo)==0){
		printf("%s %s : variavel ja declarada antes\n", tipo, id);
		return 1;
	}

	Var temp;
	temp.id = id;
	temp.escopo = escopo;
	char *aux = (char *)malloc( strlen(tipo)+1);
	strcpy(aux, tipo);
	temp.tipoExtenso = aux;

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

	printf("sucesso: tipo '%s' e id '%s' - variavel foi declarada \n", temp.tipoExtenso, temp.id);

	return 0; //inseriu a variavel com sucesso
}
/* insere a variavel no vetor caso nao a encontre ja declarada */
int insertVars(char *ids, int escopo, char *tipo){
	int i;
    int c = 0;
    char **arr = NULL;

    c = split(ids, ',', &arr);

    for (i = 0; i < c; i++){
    	insertVar(arr[i], escopo, tipo);
    }

	return 0;
}

/************************************/
/***     Funcao/Procedimento      **/
/***********************************/

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
int findFunc(char *id, int escopo){
	if( findFuncToInsert(id, escopo) == 1){ //se procedimento/funcao não foi encontrado, não é válida
		printf("erro: %s - procedimento nao declarado\n", id);
	}
	return 0; //encontrou func, é valida
}
/* insere a funcao no vetor caso nao a encontre ja declarada */
int insertFunc(char *id, int escopo, char *tipoRetorno, char *tipoParams){

	if( findFuncToInsert(id, escopo) == 0){
		printf("erro: %s - procedimento/funcao ja declarado previamente\n", id);
		return 1; //erro na declaracao
	}

	Func temp;
	temp.id = id;
	temp.escopo = escopo;
	temp.tipoRetorno = tipoRetorno;
	temp.tipoParams = tipoParams;
	//temp.qntParams = qntParams; //lembrar de implementar, sepa

	vetorFunc[sizeVectorVar] = temp;
	sizeVectorFunc++;

	printf("sucesso: %s - variavel foi declarada \n", id);
	return 0; //inseriu a variavel com sucesso

}


/************************************/
/***            Outros            ***/
/************************************/

int printVar(){
	printf("[ \n");
	for(int i=0; i<sizeVectorVar; i++){
		printf("( %s - %i - %s )\n", vetorVar[i].id, vetorVar[i].escopo, vetorVar[i].tipoExtenso);
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

Var getVarInfo(char *id, int escopo, char *tipo){
	Var tmp;
	if(findVar(id,escopo, tipo) == 0){
		for(int i=0; i<sizeVectorVar; i++){
			if(strcmp(id, vetorVar[i].id)==0){
				return vetorVar[i];
			}
		}	
	}
	else{
		return tmp;
	}
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

char* makePrint(char *id, int escopo, char *tipo){
	Var tmp = getVarInfo(id,escopo, tipo);
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

int split (char *str, char c, char ***arr)
{
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
            count++;
        p++;
    }

    *arr = (char**) malloc(sizeof(char*) * count);
    if (*arr == NULL)
        exit(1);

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
        {
            (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*arr)[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*arr)[i] == NULL)
        exit(1);

    i = 0;
    p = str;
    t = ((*arr)[i]);
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*arr)[i]);
        }
        p++;
    }

    return count;
}

//int main(){return 0;}

#endif