#include "dll.h"
#include <stdio.h>



void print_dll(DLL dll)
{

    if (dll.head ==NULL){
        perror("Empty DLL!\n");
        exit(-1);
    }

    Node *curr_node = dll.head;

    while (curr_node){
        printf("prev: %15p, timestamp: %4lu, temperature: %f, addrr: %15p, next: %15p\n", 
        curr_node->prev, 
        curr_node->data.timestamp, 
        curr_node->data.temperature, 
        &curr_node, 
        curr_node->next);

        curr_node = curr_node->next;
    }
}

void push_back(DLL *dll, Data new_data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = dll->tail;

    if (dll->head == NULL){
        dll->head = new_node;
        dll->tail = new_node;
        return;
    }
    
    dll->tail->next = new_node;
    dll->tail = new_node;
}

void pop_front(DLL *dll)
{
    if (dll->head ==NULL){
        perror("Empty DLL!\n");
        exit(-1);
    }
    if (dll->head == dll->tail){
        dll->head = NULL;
        dll->tail = NULL;
        return;
    }

    Node *deleted_node = dll->head;
    dll->head = dll->head->next;
    dll->head->prev = NULL;
    free(deleted_node);
}

void pop_back(DLL *dll)
{
    if (dll->head ==NULL){
        perror("Empty DLL!\n");
        exit(-1);
    }
    if (dll->head == dll->tail){
        dll->head = NULL;
        dll->tail = NULL;
        return;
    }
    Node *deleted_node = dll->tail;
    dll->tail = dll->tail->prev;
    dll->tail->next = NULL;
    free(deleted_node);
}

void push_front(DLL *dll, Data new_data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = dll->head;
    new_node->prev = NULL;

    if (dll->head == NULL){
        dll->head = new_node;
        dll->tail = new_node;
        return;
    }
    
    dll->head->prev = new_node;
    dll->head = new_node;
}
