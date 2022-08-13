#include "dll.h"

void create_example_dll()
{
    test_data[0] = (Data){100, 12.3};
    test_data[1] = (Data){126, 12.3};
    test_data[2] = (Data){305, 12.3};
    test_data[3] = (Data){23, 12.3};
    test_data[4] = (Data){55, 12.3};
    test_nodes[0] = (Node){test_data[0], NULL, test_nodes + 1};
    test_nodes[1] = (Node){test_data[1], test_nodes, test_nodes + 2};
    test_nodes[2] = (Node){test_data[2], test_nodes + 1, test_nodes + 3};
    test_nodes[3] = (Node){test_data[3], test_nodes + 2, test_nodes + 4};
    test_nodes[4] = (Node){test_data[4], test_nodes + 3, NULL};
    test_DLL.head = test_nodes;
    test_DLL.tail = test_nodes + 4;
}

void print_dll(DLL dll)
{	if(NULL == dll.head){printf("empty list\n");return;}
	Node *it = dll.head;
	for(;it!=NULL;it=it->next){
		printf("curr: %15p  next: %15p  prev: %15p  time: %4lu  temp: %f\n", it, it->next, it->prev, it->data.timestamp, it->data.temperature);
	}
}

void push_back(DLL *dll, Data new_data)
{	Node *a = malloc(sizeof(Node));
	a->data = new_data;
	a->next = NULL;
	if(dll->head == NULL){
		dll->head = a;
		dll->tail = a;
		a->prev = NULL;
		return;
	}
	dll->tail->next = a;
	a->prev = dll->tail;
	dll->tail = a;
	return; 
}

void pop_front(DLL *dll)
{
	if(NULL == dll->head){return;}
	if(NULL == dll->head->next){
		free(dll->head);
		dll->head = NULL;
		dll->tail = NULL;
	}
	Node * a = dll->head;
	dll->head = dll->head->next;
	dll->head->prev = NULL;
	free(a);
	
}

void pop_back(DLL *dll)
{
	if(NULL == dll->head){return;}
	if(NULL == dll->head->next){
		free(dll->head);
		dll->head = NULL;
		dll->tail = NULL;
	}
	Node * a = dll->tail;
	dll->tail = dll->tail->prev;
	dll->tail->next = NULL;
	free(a);
	
}

void push_front(DLL *dll, Data new_data)
{	
	Node *a = malloc(sizeof(Node));
	a->data = new_data;
	a->prev = NULL;
	if(dll->head == NULL){
		dll->head = a;
		dll->tail = a;
		a->next = NULL;
		return;
	}
	dll->head->prev = a;
	a->next = dll->head;
	dll->head = a;
	return;
}
