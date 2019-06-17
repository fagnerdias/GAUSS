#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef TABELASIMBOLOS
#define TABELASIMBOLOS

int size_buffer_args_t = 25;

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
	char *tipoRetorno;
	char *tipoParams;
	int qntParams;
	Var parametros[25]; //tamanho maximo de parametros

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
int printFunc();
int parametros_passados_validos(Var *paramsFuncao, char *parametrosPassados);
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
		char *aux = " Variavel redeclarada\n";
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
			vetorVar[i] = temp;//adicionou a var com sucesso
			//printVars();
			//printf("sucesso: tipo '%s' e id '%s' - variavel foi declarada \n", temp.tipo, temp.id);
			return 0;
		}
	}
	//caso nao tenha inserido antes, e por consequencia finalizado, insere na proxima posicao do vetor
	vetorVar[sizeVectorVar] = temp;
	sizeVectorVar++;
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
        	}
        }
        free(tokens);
    }
	return 0; //Completou as declarações com sucesso
}

//seta as variaveis de um escopo para nao mais ocupadas ao sair desse escopo
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
int findFunc(char *id, int escopo, char *parametros_passados){
	int encontrou = 1;
	for( int i=0; i<sizeVectorFunc; i++ ) {
		if( strcmp(id, vetorFunc[i].id) == 0 ) { //encontrado equivalente no vetor
			encontrou = 0;
			//printFunc();

			if( parametros_passados_validos(vetorFunc[i].parametros, parametros_passados) == 1){ //chamada de funcao com parametros invalidos retorna erro
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
	//printFunc();
	return 0; //encontrou func, é valida
}
/* insere a funcao no vetor caso nao a encontre ja declarada */
int insertFunc(char *id, char *tipoRetorno, Var *tipoParams){
	
	int encontrou = 1;
	for( int i=0; i<sizeVectorFunc; i++ ) {
		if( strcmp(id, vetorFunc[i].id) == 0 ) { //encontrado equivalente no vetor
			encontrou = 0; //encontrou id, funcao declarada
		}
	}
	if( encontrou == 0){
		char *aux = "Erro: procedimento/funcao ja declarado previamente - ";
        char *aux2 = (char *)malloc( strlen(aux) + strlen(id) + 1 );
        strcpy(aux2, aux);
        strcat(aux2, id);
		yyerror(aux2);
		return 1; //erro na declaracao
	}

	Func temp;
	char *auxId = (char *)malloc( strlen(id)+1);
	strcpy(auxId, id);
	temp.id = auxId;
	
	char *auxTipo = (char *)malloc( strlen(tipoRetorno)+1);
	strcpy(auxTipo, tipoRetorno);
	temp.tipoRetorno = auxTipo;

	for (int i = 0; i < size_buffer_args_t; ++i){
		temp.parametros[i] = tipoParams[i];
	}
	
	vetorFunc[sizeVectorFunc] = temp;
	sizeVectorFunc++;
	//printFunc();

	//printf("sucesso: %s - funcao foi declarada \n", id);
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
		printf("( %s - %s )\n", vetorFunc[i].id, vetorFunc[i].tipoRetorno);
		for(int j = 0; j<size_buffer_args_t; j++){
			if(vetorFunc[i].parametros[j].ocupada==1){
				break;
			}
			//printf("varsdeclaradas( %s - %s )\n", vetorFunc[i].parametros[j].id, vetorFunc[i].parametros[j].tipo);
		}
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

        while (token){
            if( (idx < count)== 0) {
	            *(result + idx++) = strdup(token); //da seg fault aqui no win
	            token = strtok(0, delim);
	        }else{
	        	break;
	        }
        }
        //assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int parametros_passados_validos(Var *paramsFuncao, char *parametrosPassados){
	Var paramsPassados[size_buffer_args_t];
	for(int i=0; i<size_buffer_args_t; i++){
		paramsPassados[i].ocupada = 1;
	}

	int tamTkPassados = 0;
	char *p;
	p = strtok (parametrosPassados,",");
	while (p!= NULL)
	{
		int retorno = 1;
		for( int j = 0; j<sizeVectorVar; j++ ) {
			//printf("---IDS: %s \n", vetorVar[j].id);
			if( strcmp(p, vetorVar[j].id) == 0 && vetorVar[j].ocupada == 0 ) {
		    	paramsPassados[j] = vetorVar[j];
		    	retorno = 0; //encontrou
				//printf ("passados: %s\n",paramsPassados[j].tipo);
			}
		}
		if(retorno==1){	
			char *aux = " : Variavel nao declarada";
		    char *aux2 = (char *)malloc( strlen(aux) + strlen(p) + 4 );
		    strcpy(aux2, p);
		    strcat(aux2, aux);
			yyerror(aux2);
		}
		tamTkPassados+=1; //atualizando o tamanho a cada iteracao
		p = strtok (NULL, ",:");
	}

    int tamTkFuncao = 0;
	for(int i=0; i<size_buffer_args_t; i++){

		if(paramsFuncao[i].ocupada == 0){
			tamTkFuncao = i+1;
		}
	}

    int retorno = 0;
	if( tamTkPassados != tamTkFuncao ){
		yyerror("Quantidade de parametros passados invalida.");

	}else if( tamTkPassados == 0 && tamTkFuncao == 0 ){ //caso a quantidade de parametros seja zero, esta valido
		return 0;

	}else if(tamTkPassados == tamTkFuncao){
		for (int i = 0; i<tamTkFuncao; i++){
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

	return retorno;
}

//int main(){return 0;}

#endif