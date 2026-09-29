#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
int main(){
    struct Node *node1;
    struct Node *node2;
    struct Node *node3;

    node1 = (struct Node*)malloc(sizeof(struct Node));
    node2 = (struct Node*)malloc(sizeof(struct Node));
    node3 = (struct Node*)malloc(sizeof(struct Node));

    node1->data = 10;
    node1->next= node2;

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = NULL;

    struct Node *head = node1;
    
    struct Node *newNode; 
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = 5;
    newNode->next = head;

    head = newNode;

    struct Node *current = head;

    while ( current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }

    free(node1);
    free(node2);
    free(node3);
    free(newNode);

    return 0;
}