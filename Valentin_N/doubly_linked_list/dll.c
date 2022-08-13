#include "dll.h"

void print_dll(DLL dll)
{
    if(!dll.head){
        perror("Empty dll\n");
        return;
    }
    Node *cur_node_pointer = dll.head;
    while (cur_node_pointer != NULL)
    {
        printf("prev: %15p  timestamp: %4lu  temp: %.3f  addr: %15p  next: %p\n",cur_node_pointer->prev,
        cur_node_pointer->data.timestamp,cur_node_pointer->data.temperature,
        cur_node_pointer,cur_node_pointer->next);
        cur_node_pointer = cur_node_pointer->next;
    }
    
}

void push_back(DLL *dll, Data new_data)
{
    Node *cur_node_p;
    Node *new_node = malloc(sizeof(Node));
   
    if(!new_node){
        printf("Could not allocate memory!\n");
        exit(-1);
    }
    
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = dll->tail;
    
    if(!dll->head && !dll->tail){
        dll->head =new_node;
        dll->tail = new_node;
    }

    dll->tail->next = new_node; 
    dll->tail = new_node;
}

void pop_front(DLL *dll)
{
    Node *del_node = dll->head;
    if(!dll->head && !dll->tail){
        perror("Empty dll\n");
        exit(-1);
    }

    if(dll->head == dll->tail){
        free(del_node);
        dll->head = NULL;
        dll->tail = NULL;
        return;
    }
     
   
    dll->head = dll->head->next;
    dll->head->prev = NULL;
    free(del_node);
}

void pop_back(DLL *dll)
{
}

void push_front(DLL *dll, Data new_data)
{
    Node *new_node = malloc(sizeof(Node));
   
    if(!new_node){
        printf("Could not allocate memory!\n");
        exit(-1);
    }
    
    new_node->data = new_data;
    new_node->next = dll->head;
    new_node->prev = NULL;
    dll->head->prev = new_node; 
    dll->head = new_node;

}
