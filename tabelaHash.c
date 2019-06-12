#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"
 
int hashcode(char *key){
	return (atoi(key) % max);
}

/*
 *This function finds the given key in the Linked List
 *Returns it's index
 *Returns -1 in case key is not present
*/
int find(struct node *list, char *key)
{
	printf("iniciando find\n");
    int retval = 0;
    struct node *temp = list;
	printf("iniciando find1\n");
	if(list != NULL){
		printf("diferente\n");
		printf("temp -%s key \n",list->value.variavel.id);	
	}
	printf("temp -%s key \n",list->key);
    while (temp != NULL){
    	printf("iniciando find112\n");
        if (strcmp(temp->key, key)==0){
        	printf("iniciando find2\n");
            return retval;
        }
        printf("iniciando find3\n");
        temp = temp->next;
        retval++;
    }
    printf("iniciando find4\n");
    return -1;
} 

void insert(char *key, Valor value)
{
	printf("inciando a insercao\n");
	float n = 0.0;
	/*  n => Load Factor, keeps check on whether rehashing is required or not */

	int index = hashcode(key);
	printf("inciando a insercao1\n");
	/* Extracting Linked List at a given index */
	struct node *list = (struct node*) array[index].head;
	printf("inciando a insercao2\n");
	/* Creating an item to insert in the hash table */
	struct node *item = (struct node*) malloc(sizeof(struct node));
	printf("inciando a insercao3\n");
	item->key = key;

	item->value = value;

	item->next = NULL;

	item->prev = NULL;
	printf("inciando a insercao4\n");
	if (list == NULL) 
        {
		/* Absence of Linked List at a given index of Hash table */
		printf("\n  %s (key) and %d (value) has been inserted  \n", key, 1);
		array[index].head = item;
		array[index].tail = item;
		size++;
	}else{
		/* A Linked List is present at given index of Hash table */
		printf("inciando a insercao5\n");
		int find_index = find(list, key);
		printf("inciando a insercao6\n");
		if (find_index == -1) 
                {
		 	/*
			 *Key not found in existing Linked List
			 *Adding the key at the end of the Linked List
			*/
            printf("inciando a insercao7\n");
			item->prev = array[index].tail;

			array[index].tail->next = item;
			array[index].tail = item;

			size++;

			printf("\n %s (key) and %d (value) has been inserted \n", key, 1);

		}else {
			/*
			 *Key already present in Linked List
			 *Updating the value of already existing key
			*/
			printf("inciando a insercao8\n");
			struct node *element = get_element(list, find_index);

			element->value = value;
		       }
	}
	/* Calculating Load factor */

	n = (1.0 * size) / max;

	if (n >= 0.75) 
        {
		/* rehashing */
		printf("going to rehash\n");

		rehash();
	}
}
void rehash()
{
  struct arrayitem *temp = array;
  /* temp pointing to the current Hash table array */
  int i = 0, n=max;
  size = 0;
  max = 2 * max;

  /*
   *array variable is assigned with newly created Hash table
   *with double of previous array size
  */

  array = (struct arrayitem*) malloc(size * sizeof(struct node));

  init_array();

  for (i = 0; i < n; i++) {
    /* Extracting the Linked List at position i of Hash table array*/
    struct node* list = (struct node*) temp[i].head;

    if (list == NULL){
      /* if there is no Linked List, then continue */
      continue;
    }
    else {
     /*Presence of Linked List at i
       *Keep moving and accessing the Linked List item until the end.
       *Get one key and value at a time and add it to new Hash table array.
      */
      while (list != NULL){
        insert(list->key, list->value);

        list = list->next;
      }
    }
  }

  temp = NULL;

}

/* Returns the node (Linked list item) located at given find_index */
struct node* get_element(struct node *list, int find_index)
{
	int i = 0;
	struct node *temp = list;

	while (i != find_index)
        {
		temp = temp->next;
		i++;
	}

	return temp;
}

/* To remove an element from Hash table */
void remove_element(char * key)
{
	int index = hashcode(key);
	struct node *list = (struct node*) array[index].head;

	if (list == NULL){
		printf("\n This key does not exists \n");
	}
	else{
		int find_index = find(list, key);
		if (find_index == -1){
			printf("\n This key does not exists \n");
		}
		else {
			struct node *temp = list;
			if (strcmp(temp->key, key)==0){
				array[index].head = temp->next;
				array[index].head->prev = NULL;

				size--;
				printf("\n This key has been removed \n");
				return;
			}
			while (strcmp(temp->key, key)!=0){
				  temp = temp->next;
			}
			if (array[index].tail == temp){
				temp->prev->next = NULL;

				array[index].tail = temp->prev;

				size--;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;

				size--;
			}

 			free(temp);
			printf("This key has been removed\n");
		}
	}
}
 
/* To display the contents of Hash table */
void display()
{
	int i = 0;

	for (i = 0; i < max; i++)
        {
		struct node *temp = array[i].head;

		if (temp == NULL){
			printf("array[%d] has no elements \n", i);
		}
		else {
			printf("array[%d] has elements-: ", i);

			while (temp != NULL) 

                        {

				printf("key= %s  id= %s\t", temp->key, temp->value.variavel.id);

				temp = temp->next;

			}
			printf("\n");
		}
	}
}

/* For initializing the Hash table */
void init_array()
{
	if(array != NULL){
		printf("array nao nulo\n");
	}
	int i;
	for (i = 0; i < max; i++)
    {
		array[i].head = NULL;
		array[i].tail = NULL;
	}	
	printf("teste ini hash\n");
	
}

void liberaGeral(){
	int last;
	struct node *tmp;
	for(last = max; last > 0; last--){
		tmp = array->tail;
		array->tail = array->tail->prev;
		free(tmp);
	}
	free(tmp);
	free(array);
}

/* Returns size of Hash table */
int size_of_array()
{
	return size;
}


/*int main(void){
	array = (struct arrayitem*) malloc(max * sizeof(struct arrayitem*));
	init_array();

	Valor temp;
	temp.variavel.id = "teste";

	insert("teste",temp);
	liberaGeral();
}*/