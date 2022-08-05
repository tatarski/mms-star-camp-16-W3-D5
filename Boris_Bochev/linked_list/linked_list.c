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

int length_linked_list(Node *head_p){
    int node_count=0;
    while(head_p)
    {
        node_count++;
        head_p=head_p->next;
    }
    return node_count;
}

void reverse(Node **head_pp) {
    int node_count=length_linked_list(*head_pp);
    Node **node_pointers=malloc(node_count*sizeof(Node*));
    Node *cur_node_pointer = *head_pp;
    int cnt=0;
    while(cur_node_pointer!=NULL)
    {
        node_pointers[cnt++]=cur_node_pointer;
        cur_node_pointer=cur_node_pointer->next;
    }
    *head_pp = node_pointers[cnt-1];
    for(int i = cnt-1; i>=0; i--)
    {
        node_pointers[i]->next = node_pointers[i-1];
    }
    node_pointers[0]->next=NULL;
    free(node_pointers);
}