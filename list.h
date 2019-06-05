#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head;

node* create(int data, node* next)
{
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;
 
    return new_node;
}

node* prepend(node* head,int data)
{
    node* new_node = create(data,head);
    head = new_node;
    return head;
}

/*
struct node{
    int data;
    struct node* next;
};

struct node* head;

struct node* create(int data, struct node* next)
{
    struct node* new_node = (struct node*)malloc(sizeof( struct node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;
 
    return new_node;
}

struct node* prepend(struct node* head,int data)
{
    struct node* new_node = create(data,head);
    head = new_node;
    return head;
}


*/