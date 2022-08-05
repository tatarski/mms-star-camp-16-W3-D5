#include "linked_list.h"
void print_ll(Node *head) {
    if(!head) {
        printf("Empty linked list\n");
        return;
    }
    Node *curNode = head;
    while(curNode) {
        printf("addr: %p,  data: %ld,   next: %p\n",
            curNode, curNode->data, curNode->next);
        curNode = curNode->next;
    }
}
// Make head pointer to pointer so that
// We can change fields of NODE struct
// We can change value of pointer to first element
void push_back(Node **head, long new_data) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        perror("Push_back: Could not malloc\n");
        exit(-1);
    }
    new_node -> data = new_data;
    new_node -> next = NULL;

    // If linked list is empty - then adress of first element is NULL
    if(*head == NULL) {
        *head = new_node;
        return;
    }

    Node *last_node = *head;
    while(last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node -> next = new_node;
}

void pop_front(Node **head_pp) {
    // Error is linked list is empty
    if(!(*head_pp)) {
        perror("Pop_front: Linked list is empty\n");
        return;
    }
    Node *deleted_node = *head_pp;
    *head_pp = (*head_pp)->next;
    free(deleted_node);
}
// Add new node at the front of linked list
void push_front(Node **head_pp, long new_data) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        perror("Malloc failed\n");
        exit(-1);
    }
    new_node->data = new_data;
    new_node->next = *head_pp;
    *head_pp = new_node;
}
void pop_back(Node **head_pp) {
    Node *second_to_last_node, *last_node;
    // Load addresses into second_to_last_node and last_node
    second_to_last_node->next = NULL;
    free(last_node);
}
void reverse(Node **head_pp) {
	Node ** newhead = NULL;
	Node *a = *head_pp;
	Node *reverse_last = NULL;
	if(*head_pp == NULL){return;}
	if(a->next == NULL){return;}
	while(a->next != NULL){
		a = a->next;
	}
	newhead = &a;
	reverse_last = a;
	reverse_last->next = NULL;
	while(reverse_last != *head_pp){
		Node *a = *head_pp;
		while(a->next != reverse_last){
			a = a->next;
		}
		reverse_last->next = a;
		reverse_last = a;
		reverse_last->next = NULL;
	}
	*head_pp = *newhead;
}
