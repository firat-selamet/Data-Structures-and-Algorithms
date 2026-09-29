#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Pozisyona gore ekleme yapan fonksiyon
void insertAt(Node **head, int value, int position) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsis edilemedi!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *current = *head;
    int i = 0;
    while (current->next != NULL && i < position - 1) {
        current = current->next;
        i++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Pozisyona gore silme yapan fonksiyon
void deleteAt(Node **head, int position) {
    if (*head == NULL) {
        printf("Liste bos, silinecek eleman yok.\n");
        return;
    }

    if (position == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *current = *head;
    int i = 0;
    while (current->next != NULL && i < position - 1) {
        current = current->next;
        i++;
    }

    if (current->next == NULL) {
        return;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Listeyi ekrana yazdirma
void printList(Node *head) {
    Node *current = head;
    printf("Liste durumu:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
}

// Bellegi temizleme
void clear(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;

    insertAt(&head, 12, 0);  // Basa ekler (12)
    insertAt(&head, 25, 1);  // 1. indise ekler (12 25)
    insertAt(&head, 29, 5);  // Pozisyon buyuk oldugu icin sona ekler (12 25 29)
    insertAt(&head, 15, 1);  // 1. indise araya ekler (12 15 25 29)
    
    printList(head);

    deleteAt(&head, 0); // 0. indistekini (12) siler (15 25 29)
    deleteAt(&head, 2); // 2. indistekini (29) siler (15 25)
    deleteAt(&head, 7); // Gecersiz indis, islem yapilmaz
    
    printList(head);

    clear(&head);

    return 0;
}