#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef TABELASIMBOLOS
#define TABELASIMBOLOS

typedef enum {
    Tint, Tfloat,Tdouble, Tbool, caractere, string, Tvoid
} tipo_t;

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


/************************************/
/***         Auxiliares           ***/
/************************************/
char** str_split(char* a_str, const char a_delim);
int printVar();

/************************************/
/***        Decl Variaveis        ***/
/************************************/

/*metodo para auxiliar a inserção de uma variavel na tabela de simbolos */
int findVarToInsert(char *id, int escopo, char *tipo) {
	for( int i=0; i<sizeVectorVar; i++ ) {
		if( strcmp(id, vetorVar[i].id) == 0 && strcmp(tipo, vetorVar[i].tipo) == 0 ) { //encontrado equivalente no vetor
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
		printf("%s %s : variavel ja declarada anteriormente\n", tipo, id);
		return 1;
	}

	Var temp;
	
	temp.escopo = escopo;
	
	char *auxId = (char *)malloc( strlen(id)+1);
	strcpy(auxId, id);
	temp.id = auxId;
	
	char *auxTipo = (char *)malloc( strlen(tipo)+1);
	strcpy(auxTipo, tipo);
	temp.tipo = auxTipo;

	vetorVar[sizeVectorVar] = temp;
	sizeVectorVar++;

	//printf("sucesso: tipo '%s' e id '%s' - variavel foi declarada \n", temp.tipo, temp.id);
	return 0; //inseriu a variavel com sucesso
}
/* insere a variavel no vetor caso nao a encontre ja declarada */
int insertVars(char *ids, int escopo, char *tipo){

    char** tokens;
    tokens = str_split(ids, ',');
    if (tokens)
    {
        for (int i = 0; *(tokens + i); i++){
        	if (insertVar( *(tokens + i), escopo, tipo) == 1){ //erro em alguma declaracao
	        	free(*(tokens + i));
        		free(tokens);
        		return 1;
        	}else{
	        	free(*(tokens + i));
        	}
        }
        free(tokens);
    }
	return 0; //Completou as declarações com sucesso
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

	temp.escopo = escopo;

	char *auxId = (char *)malloc( strlen(id)+1);
	strcpy(auxId, id);
	temp.id = auxId;
	
	char *auxTipo = (char *)malloc( strlen(tipoRetorno)+1);
	strcpy(auxTipo, tipoRetorno);
	temp.tipoRetorno = auxTipo;

	char *auxParans = (char *)malloc( strlen(tipoParams)+1);
	strcpy(auxParans, tipoParams);
	temp.tipoParams = auxParans;
	//temp.qntParams = qntParams; //lembrar de implementar, sepa

	vetorFunc[sizeVectorVar] = temp;
	sizeVectorFunc++;

	printf("sucesso: %s - funcao foi declarada \n", id);
	return 0; //inseriu a variavel com sucesso

}


/************************************/
/***            Outros            ***/
/************************************/

int printVar(){
	printf("[ \n");
	for(int i=0; i<sizeVectorVar; i++){
		printf("( %s - %i - %s )\n", vetorVar[i].id, vetorVar[i].escopo, vetorVar[i].tipo);
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

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

//int main(){return 0;}

#endif