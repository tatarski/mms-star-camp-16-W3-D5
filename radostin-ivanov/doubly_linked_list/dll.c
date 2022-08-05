#include "dll.h"
#include <stdio.h>



void print_dll(DLL dll)
{
    Node *curr_node_pointer = dll.head;
    while (curr_node_pointer != NULL)
    {
        printf("prev: %p, timestamp:%lu, temp: %f, addr: %p, next:%p\n", 
        curr_node_pointer->prev,
        curr_node_pointer->data.timestamp,
        curr_node_pointer->data.temperature, 
        curr_node_pointer,
        curr_node_pointer->next);

        curr_node_pointer = curr_node_pointer->next;
    }
    
}

void push_back(DLL *dll, Data new_data)
{
    
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        perror("Malloc failed. \n");
        exit(-1);
    }
    
    new_node->data=new_data;
    new_node->next= NULL;
    new_node->prev= dll->tail;
    if (!dll->head && dll->tail)
    {
        dll->head = new_node;
        dll->tail = new_node;
        return ;
    }
    
    new_node->prev = dll-> tail;
    dll-> tail-> next =new_node;
    dll->tail= new_node;
    
    
}

void pop_front(DLL *dll)
{
    
}

void pop_back(DLL *dll)
{
}

void push_front(DLL *dll, Data new_data)
{
}
