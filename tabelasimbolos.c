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
	int ocupada;
}Var;

typedef struct Func
{
	char *id;
	int escopo;
	char *tipoRetorno;
	char *tipoParams;
	int qntParams;
	Var parametros[25];

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
int parametros_passados_validos(char *parametrosFuncao, char *parametrosPassados);
extern int yyerror (char *msg);

/************************************/
/***        Decl Variaveis        ***/
/************************************/

/* método para verificar se uma variavel é valida no determinado escopo*/
void iniciaVetorVar(){
	for( int i=0; i<100; i++ ) {
		vetorVar[i].ocupada = 1; //seta todas as posicoes para nao serem ocupadas
	}
}
/* método para verificar se uma variavel é valida no determinado escopo*/
int findVar(char *id, int escopo, char *tipo){
	for( int i=0; i<sizeVectorVar; i++ ) {
		if( vetorVar[i].ocupada == 0 && //espaco do vetor esta sendo usado para uma variavel (caso tenha sido liberado em alguma saída de escopo)
			strcmp(id, vetorVar[i].id) == 0 && //encontrado id igual
			strcmp(tipo, vetorVar[i].tipo) == 0 && //encontrada var do mesmo tipo
			escopo <= vetorVar[i].escopo ){ //encontrada var declarada no mesmo escopo ou escopo anterior
			return 0; //encontrou id, var declarada
		}
	}
	return 1; //nao encontrou, var nao declarada
}
/* insere a variavel no vetor caso nao a encontre ja declarada */
int insertVar(char *id, int escopo, char *tipo){
	if( findVar(id, escopo, tipo) == 0 ){
		char *aux = "variavel ja declarada anteriormente\n";
        char *aux2 = (char *)malloc( strlen(aux) + strlen(id) + strlen(tipo) + 5 );
        strcat(aux2, tipo);
        strcat(aux2, " ");
        strcat(aux2, id);
        strcpy(aux2, aux);
		yyerror(aux2);
		return 1;
	}
	Var temp;

	temp.ocupada = 0; //variavel do vetor sendo utilizada
	temp.escopo = escopo;
	
	char *auxId = (char *)malloc( strlen(id)+1 );
	strcpy(auxId, id);
	temp.id = auxId;
	
	char *auxTipo = (char *)malloc( strlen(tipo)+1 );
	strcpy(auxTipo, tipo);
	temp.tipo = auxTipo;

	for( int i=0; i<sizeVectorVar; i++ ) { //para caso tenha variaveis nao utilizadas no meio do vetor util
		if( vetorVar[i].ocupada == 1 ){ //primeira variavel nao sendo utilizada
			vetorVar[i] = temp;
			//printVar();
			return 0; //adicionou a var com sucesso e finaliza
		}
	}
	
	//caso nao tenha inserido antes, e por consequencia finalizado, insere na proxima posicao do vetor
	vetorVar[sizeVectorVar] = temp;
	sizeVectorVar++;
	
	printVar();
	//printVar();
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

void limpar_variaveis_do_escopo(int escopo){
	for( int i=0; i<sizeVectorVar; i++ ){
		if( vetorVar[i].escopo == escopo ){
			vetorVar[i].ocupada = 1; //variavel nao mais ocupada
		}
	}
}

/************************************/
/***     Funcao/Procedimento      **/
/***********************************/

/* método para verificar se a chamada de um procedimento/funcao é valida */
int findFunc(char *id, int escopo, char *parametros){
	int encontrou = 1;
	for( int i=0; i<sizeVectorFunc; i++ ) {
		if( strcmp(id, vetorFunc[i].id) == 0 ) { //encontrado equivalente no vetor
			encontrou = 0;
			if( parametros_passados_validos(vetorFunc[i].tipoParams, parametros) == 1){ //chamada de funcao com parametros invalidos retorna erro
				encontrou = 2; //nunca vai chegar aqui pq se for 1, vai ser invalido e dar exit no yyerror 
			}
			encontrou = 0; //encontrou id, funcao declarada
		}
	}
	if( encontrou == 1){ //se procedimento/funcao não foi encontrado, não é válida
		char *aux = "Erro: funcao/procedimento nao declarado - ";
        char *aux2 = (char *)malloc( strlen(aux) + strlen(id) + 1 );
        strcpy(aux2, aux);
        strcat(aux2, id);
		yyerror(aux2);
	}

	return 0; //encontrou func, é valida
}
/* insere a funcao no vetor caso nao a encontre ja declarada */
int insertFunc(char *id, int escopo, char *tipoRetorno, char *tipoParams){
	
	int encontrou = 1;
	for( int i=0; i<sizeVectorFunc; i++ ) {
		if( strcmp(id, vetorFunc[i].id) == 0 ) { //encontrado equivalente no vetor
			encontrou = 0; //encontrou id, funcao declarada
		}
	}
	if( encontrou == 1){
		char *aux = "erro: procedimento/funcao ja declarado previamente - .";
        char *aux2 = (char *)malloc( strlen(aux) + strlen(id) + 1 );
        strcpy(aux2, aux);
        strcat(aux2, id);
		yyerror(aux2);
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
		printf("( %s - %i - %s - %i )\n", vetorVar[i].id, vetorVar[i].escopo, vetorVar[i].tipo, vetorVar[i].ocupada);
	}
	printf(" ]\n");
	return 0;
}
int printFunc(){
	printf("[ ");
	for(int i=0; i<sizeVectorFunc; i++){
		printf("( %s - %i - %s - %s)\n", vetorFunc[i].id, vetorFunc[i].escopo, vetorFunc[i].tipoRetorno, vetorFunc[i].tipoRetorno);
	}
	printf(" ]\n");
	return 0;
}

Var getVarInfo(char *id, int escopo, char *tipo){
	Var tmp;
	if(findVar(id,escopo, tipo) == 0){ //encontrou
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

int parametros_passados_validos(char *parametrosFuncao, char *parametrosPassados){

	Var paramsPassados[20];
    char** tokensPassados = str_split(parametrosPassados, ',');
    int tamTkPassados = 0;
    if (tokensPassados) {
        for (int i = 0; *(tokensPassados + i); i++){
			for( int j = 0; j<sizeVectorVar; j++ ) {
				if( strcmp(*(tokensPassados + i), vetorVar[j].id) == 0 ) {
		        	paramsPassados[i] = vetorVar[j];
				}
			}

        	tamTkPassados = i; //atualizando o tamanho a cada iteracao
        	printf("tk ---- %s\n", *(tokensPassados + i));
        }
    }

	Var paramsFuncao[20];
    char** tokensFuncao = str_split(parametrosFuncao, ',');
    int tamTkFuncao = 0;
    if (tokensFuncao) {
        for (int i = 0; *(tokensFuncao + i); i++){
        	Var temp;
        	temp.id = *(tokensFuncao + i);
        	temp.tipo = *(tokensFuncao + i);
        	temp.ocupada = 0;
        	paramsFuncao[i] = temp;

        	tamTkFuncao = i; //atualizando o tamanho a cada iteracao
        	printf("tk ---- %s\n", *(tokensFuncao + i));
        }
    }

    int retorno = 0;

    if(tamTkPassados == tamTkFuncao){
		for (int i = 0; i<tamTkFuncao; i++){
			printf("tss ---- %s\n");
			//se os tipos nao baterem, passagem de parametro invalida
			if ( strcmp( paramsFuncao[i].tipo, paramsPassados[i].tipo) == 1 && //tipos diferentes
					paramsFuncao[i].ocupada == 1 && paramsPassados[i].ocupada == 1 ){ //se as posicoes do vetor possuem variaveis sendo usadas
				retorno = 1;

				char *aux = "Passagem de parametro invalida. Esperado: ";
				char *aux2 = " . Passado: ";
		        char *temp = (char *)malloc( strlen(aux) + strlen(aux2) + strlen(paramsFuncao[i].tipo) + strlen(paramsPassados[i].tipo) + 5 );
		        strcpy(temp, aux);
		        strcat(temp, paramsFuncao[i].tipo);
		        strcat(temp, aux2);
		        strcat(temp, paramsPassados[i].tipo);
				yyerror(temp);
			}
		}
    }else{
    	retorno = 1; //nao sao validos
		yyerror("Quantidade de parametros passados invalida.");
    }

    /*limpar tokens*/
    if (tokensFuncao) {
        for (int i = 0; *(tokensFuncao + i); i++){
	        free(*(tokensFuncao + i));
        }
        free(tokensFuncao);
    }
    if (tokensPassados) {
        for (int i = 0; *(tokensPassados + i); i++){
	        free(*(tokensPassados + i));
        }
        free(tokensPassados);
    }

	return retorno;
}

//int main(){return 0;}

#endif