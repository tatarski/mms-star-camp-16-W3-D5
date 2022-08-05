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

int length_linked_list(Node *head){
    int node_count = 0;
    
    while(head){
        node_count++;
        head = head->next;
    }

    return node_count;
}

void reverse(Node **head_pp) {
    
    int count = length_linked_list(*head_pp);
    Node *node_pointers[count];
    Node *curr_node = *head_pp;
    int i = 0;
    while(curr_node){
        node_pointers[i++] = curr_node;
        curr_node = curr_node->next;
    }
    *head_pp = node_pointers[i - 1];
    for (int j = i - 1; j > 0; j--){
        node_pointers[j]->next = node_pointers[j - 1];
    }

    node_pointers[0]->next = NULL;
}