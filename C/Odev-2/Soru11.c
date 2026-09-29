#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* InsertBeginning(struct Node *head, int data){
    struct Node *yeniDugum;
    yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    
    yeniDugum->data = data;
    yeniDugum->next = head;
    return yeniDugum;
}
void Display(struct Node *head){
    struct Node *current = head;
    printf("Liste gosteriliyor...\n");
    while ( current != NULL){
        printf("%d\n\n", current->data);
        current = current->next;
    }
}

void Search(struct Node *head){
    int aranan;
    int flag = 0;
    printf("Aramak istediginiz sayiyi giriniz: \n");
    scanf("%d", &aranan);
    
    struct Node *current = head;

    while( current != NULL){
        if ( current->data == aranan){
            flag = 1;
        break;
        }            
        current = current->next;
    }
    if (flag == 1)
    printf("Aradiginiz sayi bulundu.\n\n");
    else
    printf("Aradiginiz sayi bulunamadi.\n\n");
}
int main(){
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

    head = InsertBeginning(head, 9);
    Display(head);
    Search(head);

    struct Node *current = head;
    struct Node *temp;

    while ( current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}