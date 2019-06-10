#include<stdio.h>

#include<stdlib.h>
#include "tabelaHash.h"
 
int hashcode(int key)
{
	return (key % max);
}

/*
 *This function finds the given key in the Linked List
 *Returns it's index
 *Returns -1 in case key is not present
*/

int find(struct node *list, int key)
{
    int retval = 0;
    struct node *temp = list;

    while (temp != NULL)
        {
        if (temp->key == key)
                {
            return retval;
        }

        temp = temp->next;
        retval++;
    }
    return -1;
} 

void insert(char *key, struct valor value)
{
	float n = 0.0;
	/*  n => Load Factor, keeps check on whether rehashing is required or not */

	int index = hashcode(key);
	/* Extracting Linked List at a given index */
	struct node *list = (struct node*) array[index].head;
	/* Creating an item to insert in the hash table */
	struct node *item = (struct node*) malloc(sizeof(struct node));

	item->key = key;

	item->value = value;

	item->next = NULL;

	item->prev = NULL;

	if (list == NULL) 
        {
		/* Absence of Linked List at a given index of Hash table */
		printf("\n  %d (key) and %d (value) has been inserted  \n", key, 1);
		array[index].head = item;
		array[index].tail = item;
		size++;
	}
        else
        {
		/* A Linked List is present at given index of Hash table */
		int find_index = find(list, key);

		if (find_index == -1) 
                {
		 	/*
			 *Key not found in existing Linked List
			 *Adding the key at the end of the Linked List
			*/

			item->prev = array[index].tail;

			array[index].tail->next = item;
			array[index].tail = item;

			size++;

			printf("\n %d (key) and %d (value) has been inserted \n", key, 1);

		}else {
			/*
			 *Key already present in Linked List
			 *Updating the value of already existing key
			*/
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

  for (i = 0; i < n; i++) 
        {
    /* Extracting the Linked List at position i of Hash table array*/
    struct node* list = (struct node*) temp[i].head;

    if (list == NULL)
                {
      /* if there is no Linked List, then continue */
      continue;
    }
    else 
      /*
       *Presence of Linked List at i
       *Keep moving and accessing the Linked List item until the end.
       *Get one key and value at a time and add it to new Hash table array.
      */
      while (list != NULL)
                        {
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

void remove_element(int key)

{

	int index = hashcode(key);

	struct node *list = (struct node*) array[index].head;

 

	if (list == NULL)

        {

		printf("\n This key does not exists \n");

 

	}

	else

        {

		int find_index = find(list, key);

 

		if (find_index == -1)

                {

			printf("\n This key does not exists \n");

 

		}

		else 

                {

			struct node *temp = list;

			if (temp->key == key)

                        {

 

				array[index].head = temp->next;

				array[index].head->prev = NULL;

				size--;

				printf("\n This key has been removed \n");

				return;

			}

 

			while (temp->key != key)

                        {

				  temp = temp->next;

			}

 

			if (array[index].tail == temp)

                        {

				temp->prev->next = NULL;

				array[index].tail = temp->prev;

				size--;

 

			}

                        else 

                        {

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

		if (temp == NULL)

                {

			printf("array[%d] has no elements \n", i);

 

		}

		else 

                {

			printf("array[%d] has elements-: ", i);

			while (temp != NULL) 

                        {

				printf("key= %d  id= %s\t", temp->key, temp->value.variavel.id);

				temp = temp->next;

			}

			printf("\n");

 

		}

	}

}

 

/* For initializing the Hash table */

void init_array()

{

	int i;

	for (i = 0; i < max; i++)

        {

		array[i].head = NULL;

		array[i].tail = NULL;

	}

 

}

 

/* Returns size of Hash table */

int size_of_array()
{
	return size;
}

 

int main()
{}
