#ifndef TABELAHASH_H
#define TABELAHASH_H

/* Node for storing an item in a Doubly Linked List */
struct infoVariavel{
	char *id;
	char *escopo;
	char *tipo;
};

struct func
{	
	char *id;
	char *retorno;
	int qntParams;
	char *tipoParams;
	struct func *next;

};

typedef struct Valor
{
	struct infoVariavel variavel;
	struct func funcao;
}Valor;

struct node 
{
	char *key;

	Valor value;

	struct node *next;
	struct node *prev;
};

/* For storing a Linked List at each index of Hash table */
struct arrayitem 
{
	struct node *head;
	/* head pointing the first element of Linked List at an index of Hash table */
	struct node *tail;
	/* tail pointing the last element of Linked List at an index of Hash table */
};

 struct arrayitem *array;

int size = 0;         /* Determines the no. of elements present in Hash table */

int max = 999999;	      /* Determines the maximum capacity of Hash table array */


struct node* get_element(struct node *list, int find_index);

void remove_element(char *key);

void rehash();

void init_array();

int find(struct node *list, char *key);

void insert(char * key, Valor value);

void display();

int size_of_array();

int hashcode(char *key);


#endif