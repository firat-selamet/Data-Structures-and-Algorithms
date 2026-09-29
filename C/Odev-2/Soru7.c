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

    int arananSayi;
    printf("Lutfen aramak istediginiz sayiyi giriniz: ");
    scanf("%d", &arananSayi);

    int flag = 0;

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
        if ( current->data == arananSayi){
            printf("\nAranan sayi bulundu!");
            flag = 1;
            break;
        }
        current = current->next;
    }

    if ( flag == 0 )
        printf("\nAranan sayi listede bulunamadi!");

    free(head);
    free(second);
    free(third);
    free(fourth);

   
    return 0;
}