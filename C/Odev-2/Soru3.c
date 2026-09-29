#include <stdio.h>
struct Node{
    int data;
    struct Node *next;
};

int main(){
    struct Node head;
    struct Node second;
    struct Node third;

    head.data = 10;
    head.next = &second;

    second.data = 20;
    second.next = &third;

    third.data = 30;
    third.next = NULL;

    struct Node *current = &head;

    while ( current != NULL){
        printf("Data: %d\n", current->data);
        current = current->next;
    }
    
    return 0;
}