#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

//Eklenen Node'u sıralama fonksiyonu
void addOrdered(Node **head, int value){
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL){
        printf("Bellekte yer tutulamadı...");
        exit(1);
    }
    
    newNode->data = value;
    newNode->next = NULL;

//Değer baştakinden küçükse eğer
    if ( *head == NULL || (*head)->data > value){
        newNode->next = (*head);
        (*head) = newNode;
        return;
    }

//Değer baştakinden büyükse eğer
    Node *current = *head;
    while ( current->next != NULL && current->next->data < value){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

}

//Node sayısı fonksiyonu
int count(Node *head){
    Node *current = head;
    int adet = 0;
    while (current != NULL){
        adet++;
        current = current->next;
    }
    return adet;
}

//Belleği temizleme fonksiyonu
void clear(Node **head){
    Node *temp;
    while ( (*head) != NULL ){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

//Belirli bir Node'u silme
void removeNode ( Node **head, int value){
//Liste boşsa
    if ((*head) == NULL){
        printf("Liste bos...");
        return;
    }
//Silinecek eleman en baştaysa
    if((*head)->data == value){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
//Silinecek eleman başta değilse
    Node *current = *head;
    while ( current->next != NULL && current->next->data != value){
        current = current->next;
    }
    if ( current->next == NULL){
        printf("Sayi listede yok!");
        return;
    }
    Node *temp;
    temp = current->next;
    current->next = temp->next;
    free(temp);
}

//Listenin elemanlarını baştan sona ekrana yazdırma
void printList(struct Node *head){
    struct Node *current = head;
    printf("Liste gosteriliyor...\n");
    while ( current != NULL){
        printf("%d\n\n", current->data);
        current = current->next;
    }
}

int main(){
    Node *head = NULL;

    addOrdered(&head, 12);
    addOrdered(&head, 9);
    addOrdered(&head, 13);
    addOrdered(&head, 6);
    addOrdered(&head, 2);
    addOrdered(&head, 1);

// Ekleme sonrası tam listeyi gör
    printList(head); 
    printf("Eleman sayisi: %d\n", count(head));

    // Silme fonksiyonunu test et
    printf("\n9 (aradan) ve 1 (bastan) siliniyor\n");
    removeNode(&head, 9);  
    removeNode(&head, 1);  
    
    printf("\nOlmayan 99 sayisi silinmeye calisiliyor\n");
    removeNode(&head, 99); 

    printf("\nSon Durum:\n");
    printList(head);
    printf("Kalan eleman sayisi: %d\n", count(head));

    // Temizlik testi
    clear(&head);
    printf("\nTemizlik sonrasi eleman sayisi: %d\n", count(head));
    


    return 0;
}