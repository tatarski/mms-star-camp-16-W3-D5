#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

void print_dll(DLL dll)
{
    Node *cur_n_p = dll.head;
    while(cur_n_p!=NULL)
    {
        printf("prev: %p, Temp: %f, date: %lu, current: %p next: %p\n", 
        cur_n_p->prev, cur_n_p->data.temperature, cur_n_p->data.timestamp, cur_n_p, cur_n_p->next);
        cur_n_p=cur_n_p->next;
    }
}

void push_back(DLL *dll, Data new_data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data=new_data;
    new_node->next=NULL;
    new_node->prev=dll->tail;
    dll->tail->next=new_node;
    dll->tail=new_node;
}

void pop_front(DLL *dll)
{
    Node *deleted_node=dll->head;
    if(!dll->head&&!dll->tail)
    {
        perror("Empty linked list\n");
        exit(-1);
    }
    if(dll->head==dll->tail)
    {
        free(deleted_node);
        dll->head=NULL;
        dll->tail=NULL;
        return;
    }
    dll->head=dll->head->next;
    dll->head->prev=NULL;
    free(deleted_node);
}

void pop_back(DLL *dll)
{
}

void push_front(DLL *dll, Data new_data)
{
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        perror("Malloc failed\n");
        exit(-1);
    }
    dll->head->prev=new_node;
    new_node->data = new_data;
    new_node->next = dll->head;
    dll->head = new_node;
}