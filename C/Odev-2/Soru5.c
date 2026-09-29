#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    int count = 0;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    struct Node *current = head;

    while (current != NULL){
        count ++;
        current = current->next;
    }

    printf("%d adet Node vardir", count);

    free(head);
    free(second);
    free(third);
    free(fourth);
   
    return 0;
}