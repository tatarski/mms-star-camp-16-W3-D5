#include "dll.h"

void print_dll(DLL dll)
{
	Node *cur=dll.head;

	while(cur!=NULL)
	{
		printf("temp:%lu data:%f prev:%p next:%p\n" ,cur->data.timestamp,cur->data.temperature,cur->prev,cur->next);
		cur=cur->next;
	}
}

void push_back(DLL *dll, Data new_data)
{
      Node *new_node=(Node*)malloc(sizeof(Node)*1);
      new_node->data=new_data;
      new_node->next=NULL;

      new_node->prev=dll->tail;

      if(dll->head==NULL)
      {
	 dll->head=new_node;
	 dll->tail=new_node;
      }
      else
      {
	new_node->prev=dll->tail;
	dll->tail=new_node;
      }
}

void pop_front(DLL *dll)
{
	Node* first=dll->head;

	if(dll->head==NULL)return;
	if(dll->head->next==NULL)
	{
		dll->head=NULL;
		dll->tail=NULL;
			//free (first);
		return;
	}
	dll->head=dll->head->next;
	dll->head->prev=NULL;

	//maybe free(first);
}

void pop_back(DLL *dll)
{

}

void push_front(DLL *dll, Data new_data)
{

}
