#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
    int main(){

        int arananSayi;
        int flag = 0;
        printf("Lutfen silmek istediginiz sayiyi giriniz:\n");
        scanf("%d", &arananSayi);

    struct Node *node1;
    struct Node *node2;
    struct Node *node3;
    struct Node *node4;

    node1 = (struct Node*)malloc(sizeof(struct Node));
    node2 = (struct Node*)malloc(sizeof(struct Node));
    node3 = (struct Node*)malloc(sizeof(struct Node));
    node4 = (struct Node*)malloc(sizeof(struct Node));

    struct Node *head = node1;

    node1->data = 10;
    node1->next = node2;

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = node4;

    node4->data = 40;
    node4->next = NULL;

    struct Node *current = head;
    struct Node *previous = NULL;

    while ( current != NULL){
        if ( arananSayi == current->data){
            flag = 1;
            if ( current == head){
                head = current->next;
                free(current);
                break;
            }
            previous->next = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    if ( flag == 1)
    printf("Girdiginiz sayi silinmistir.\n");
    else
    printf("Sayi bulunamadi!\n");

    current = head;
    printf("Guncel liste: \n");
    while( current != NULL){
        printf("%d\n", current->data);
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
        return 0;
}