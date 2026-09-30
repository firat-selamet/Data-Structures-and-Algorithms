#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

//Bağlı listedeki ortadaki düğümü döndüren fonksiyon
Node *findMiddle(Node* head){

//Liste boş mu değil mi kontrolü
    if ( head == NULL){
        printf("Liste bos...\n\n");
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;

//fast 2 adım gittiğinden bir ve iki sonraki düğümler kontrol edilir
    while( fast != NULL && fast->next != NULL){

//slow → her adımda bir düğüm ilerler
        slow = slow->next;

//fast → her adımda iki düğüm ilerler
        fast = fast->next->next;

//fast sona ulaştığında slow ortadadır
    }

    return slow;
}

//Yeni düğüm ekleme fonksiyonu

void append(Node **head, int value){
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));

//Bellekte yer tahsis edilmiş mi kontrolü
    if ( newNode == NULL){
        printf("Yer tahsis edilemedi!");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

//Eğer newNode ilk düğümse    
    if ((*head) == NULL){
        (*head) = newNode;
        return;
    }

//İlk düğüm değilse
    Node *current = (*head);
    while ( current->next != NULL){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return;
    
}

//Listeyi ekrana yazdıran fonksiyon
void printList(Node* head){
//Liste boş mu değil mi kontrolü
    if ( head == NULL){
        printf("Liste bos...");
        return;
    }
    
//Döngü işlemi için current değişkeni oluşturulup içine head değeri tanımlandı
    Node *current = head;
    while (current != NULL){
        printf("%d", current->data);
        if(current->next != NULL)
        printf("->");

        current = current->next;
    }
}
//Listedeki tüm düğümleri serbest bırakır ve listeyi boşaltır
void clear(Node** head){
    Node *temp;

    while ((*head) != NULL){
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    }
}


int main(){
    Node *head = NULL;

    findMiddle(head);

    printf("Listenin ilk hali: ");
    printList(head);

    append(&head,12);
    append(&head,25);
    append(&head,21);
    append(&head,36);
    append(&head,23);
    append(&head,34);
    append(&head,45);
    append(&head,99);

    printf("\n\nListe: ");
    printList(head);

    printf("\n\nListenin ortanca terimi: %d",findMiddle(head)->data);


    append(&head,38);

    printf("\n\nListe guncellendi.\nGuncel liste: ");
    printList(head);

    printf("\n\nListenin ortanca terimi: %d", findMiddle(head)->data);

    clear(&head);
    printf("\n\nistenin son hali: ");
    printList(head);



    return 0;
}