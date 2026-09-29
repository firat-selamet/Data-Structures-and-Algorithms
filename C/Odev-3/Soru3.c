#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Ortadaki dugumu bulan fonksiyon (Slow ve Fast pointer mantigi)
Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    // fast her adimda 2, slow her adimda 1 ilerler. 
    // fast sona ulastiginda slow tam ortada kalir.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Listeyi ekrana yazdirma
void printList(Node *head) {
    Node *current = head;
    printf("Liste durumu: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
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

// Test etmek icin hizlica sona eleman ekleme fonksiyonu (Yardimci)
void append(Node **head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    Node *head = NULL;

    // 1. Durum: Tek sayida eleman (Ortadaki tam olarak 30 olmali)
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printList(head);
    
    Node *middle = findMiddle(head);
    if (middle != NULL) {
        printf("Ortadaki eleman: %d\n\n", middle->data);
    }

    // 2. Durum: Cift sayida eleman (Ortadaki ikiliden ikincisi, yani 40 olmali)
    append(&head, 60); 
    printList(head);
    
    middle = findMiddle(head);
    if (middle != NULL) {
        printf("Ortadaki eleman: %d\n", middle->data);
    }

    clear(&head);

    return 0;
}