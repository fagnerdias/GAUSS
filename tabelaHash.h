#ifndef TABELAHASH_H
#define TABELAHASH_H

/* Node for storing an item in a Doubly Linked List */
typedef struct infoVariavel{
	char *id;
	char *valor;
	char *escopo;
	char *tipo;
}InfoVariavel;

typedef struct valor
{
	InfoVariavel variavel;
	Func_t funcao;
}valor;

typedef struct func
{	
	char *id;
	char *retorno;
	int qntParams;
	char *tipoParams;
	Func_t *next;

}Func_t;

struct node 

{

	int key;

	valor value;

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

int max = 10;	      /* Determines the maximum capacity of Hash table array */


struct node* get_element(struct node *list, int find_index);

void remove_element(int key);

void rehash();

void init_array();

int find(struct node *list, int key);

void insert(int key, struct valor value);

void display();

int size_of_array();

int hashcode(int key);


#endif