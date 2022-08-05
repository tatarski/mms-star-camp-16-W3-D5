#include "dll.h"

void print_dll(DLL dll)
{
    if(!dll.head && !dll.tail) {
        printf("Empty double linked list\n");
        return;
    }
    Node *cur_node_pointer = dll.head;
    while(cur_node_pointer != NULL){
        printf("prev: %15p, timestamp:%4lu, temp:%f, addr: %15p, next: %p\n",
            cur_node_pointer->prev, cur_node_pointer->data.timestamp,
            cur_node_pointer->data.temperature, cur_node_pointer, cur_node_pointer->next);
        cur_node_pointer = cur_node_pointer->next;
    }
}

void push_back(DLL *dll, Data new_data)
{
    // Allocate memory for new node
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {perror("Malloc failed\n"); exit(-1);}
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    // Linked list had 0 elements
    if(!dll->head && !dll->tail) {
        dll->head = new_node;
        dll->tail = new_node;
        return;
    }

    new_node->prev = dll->tail;
    dll->tail->next = new_node;
    dll->tail = new_node;
}

void pop_front(DLL *dll)
{
    Node* deleted_node = dll->head;
    if(!dll->head && !dll->tail) {
        perror("Empty linked list\n");
        exit(-1);
    }
    // Linked list has 1 element
    if(dll->head == dll->tail) {
        free(deleted_node);
        dll->head = NULL;
        dll->tail = NULL;
        return;
    }
    dll->head = dll->head->next;
    dll->head->prev = NULL;
    free(deleted_node);
}

void pop_back(DLL *dll)
{
}

void push_front(DLL *dll, Data new_data)
{
}
