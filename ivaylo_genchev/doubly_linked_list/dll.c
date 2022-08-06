#include <stdio.h>
#include <stdlib.h>

#include "dll.h"


void print_dll(DLL dll)
{
    Node *inode = dll.head; 
    while (NULL != inode) {
        printf("%ld %f", inode->data.timestamp, inode->data.temperature);
        putchar('\n');
        inode = inode->next;
    }

    putchar('\n');
}

void push_back(DLL *dll, Data new_data)
{
    Node *new_node = malloc(sizeof(Node));
    if (NULL == new_node)
        return;

    new_node->prev = dll->tail;
    new_node->next = NULL;
    new_node->data = new_data;

    dll->tail->next = new_node;
}

void pop_front(DLL *dll)
{
    if (NULL == dll->head)
        return;

    Node *old_head = dll->head;
    dll->head = old_head->next;

    if (NULL != dll->head)
        dll->head->prev = NULL;

    free(old_head);
}

void pop_back(DLL *dll)
{
    if (NULL == dll->tail)
        return;

    Node *old_tail = dll->tail;
    dll->tail = old_tail->prev;

    if (NULL != dll->tail)
        dll->tail->next = NULL;

    free(old_tail);
}

void push_front(DLL *dll, Data new_data)
{
    Node *new_node = malloc(sizeof(Node));
    if (NULL == new_node)
        return;

    new_node->next = dll->head;
    new_node->prev = NULL;
    new_node->data = new_data;

    dll->head = new_node;
}
