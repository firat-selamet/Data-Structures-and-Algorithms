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

    struct Node *head = node1;

    node1->data = 10;
    node1->next= node2;

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = NULL;

    struct Node *lastNode;
    lastNode = (struct Node*)malloc(sizeof(struct Node));

    lastNode->data = 40;
    lastNode->next = NULL;

    struct Node *current = head;

    while ( current->next != NULL){
        current = current->next;
    }

    current->next = lastNode;

    current = head;

    while ( current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    free(node1);
    free(node2);
    free(node3);
    free(lastNode);

    return 0;
}