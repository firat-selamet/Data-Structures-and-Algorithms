#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hasta{
    int id;
    char durum[20];
    char isim[30];
    struct Hasta *next;
}Hasta;

typedef struct Queue{
    struct Hasta *rear;
    struct Hasta *front;
}Queue;

typedef struct Stack{
    struct Hasta *top;
}Stack;

typedef struct List{
    struct Hasta *head;
}List;

void enqueue(Queue *q, char *isim, int id){
    Hasta *newHasta = (Hasta*)malloc(sizeof(Hasta));

    if (newHasta == NULL){
        printf("Bellek tahsis edilemedi...");
        exit(1);
    }

    newHasta->id = id;
    strcpy(newHasta->isim, isim);
    strcpy(newHasta->durum, "bekliyor");
    newHasta->next = NULL;
    
    if (q->rear == NULL){
        q->rear = newHasta;
        q->front = newHasta;
        return;
    }

    q->rear->next = newHasta;
    q->rear = newHasta;
}

Hasta* dequeue(Queue *q){
    if (q->front == NULL){
        printf("\nSirada hasta yok...\n\n");
        return NULL;
    }

    Hasta *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL){
        q->rear = NULL;
    }

    return temp;
}

void printQueue(Queue q){
    Hasta *current = q.front;

    if (q.front == NULL){
        printf("\nSirada hasta yok...\n\n");
        return;
    }

    printf("\nSirada bekleyen hastalar getiriliyor...\n\n");

    while(current != NULL){
        printf("Hasta Adi: %s --- Hasta ID: %d --- Hasta Durumu: %s\n\n", current->isim, current->id, current->durum);
        current = current->next;
    }
}

void push(Hasta *h, Stack *m){

    strcpy(h->durum, "muayenede");

    if (m->top == NULL){
        m->top = h;
        h->next = NULL;
        return;
    }

    h->next = m->top;
    m->top = h;

}

Hasta* pop(Stack *m){
    if (m->top == NULL){
        printf("Muayenede hasta yok...\n");
        return NULL;
    }

    Hasta *temp = m->top;

    m->top = m->top->next;

    return temp;
}

void printStack(Stack m){
    Hasta *current = m.top;
    
    if (m.top == NULL){
        printf("\nMuayenede hasta yok...\n\n");
        return;
    }

    printf("\nMuayenedeki hastalar getiriliyor...\n\n");

    while(current != NULL){
        printf("Hasta Adi: %s --- Hasta ID: %d --- Hasta Durumu: %s\n\n", current->isim, current->id, current->durum);
        current = current->next;
    }
}

void addList(Hasta *h, List *g){

    strcpy(h->durum,"tamamlandi");

    if (g->head == NULL){
        g->head = h;
        h->next = NULL;
        return;
    }

    Hasta *current = g->head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = h;
    h->next = NULL;
}

void printList(List g){
    Hasta *current = g.head;

    if (g.head == NULL){
        printf("\nListede hasta yok...\n\n");
        return;
    }

    printf("\nMuayenesi bitmis hastalar getiriliyor...\n\n");

    while(current != NULL){
        printf("Hasta Adi: %s --- Hasta ID: %d --- Hasta Durumu: %s\n\n", current->isim, current->id, current->durum);
        current = current->next;
    }
}

int main(){

    Queue hastaSirasi;
    hastaSirasi.front = NULL;
    hastaSirasi.rear = NULL;

    Stack muayeneOdasi;
    muayeneOdasi.top = NULL;

    List gecmis;
    gecmis.head = NULL;

    Hasta* temp;

    printQueue(hastaSirasi);
    printStack(muayeneOdasi);
    printList(gecmis);

    enqueue(&hastaSirasi, "Ahmet", 100);
    enqueue(&hastaSirasi, "Mehmet", 101);
    enqueue(&hastaSirasi, "Muhammed", 102);
    enqueue(&hastaSirasi, "Mustafa", 103);
    enqueue(&hastaSirasi, "Firat", 104);
    enqueue(&hastaSirasi, "Suleyman", 105);
    enqueue(&hastaSirasi, "Yigit", 106);
    enqueue(&hastaSirasi, "Enes", 107);
    enqueue(&hastaSirasi, "Ali", 108);

    printQueue(hastaSirasi);
    printStack(muayeneOdasi);
    printList(gecmis);

    temp = dequeue(&hastaSirasi);
    push(temp, &muayeneOdasi);

    printQueue(hastaSirasi);
    printStack(muayeneOdasi);
    printList(gecmis);

    temp = dequeue(&hastaSirasi);
    push(temp, &muayeneOdasi);

    temp = dequeue(&hastaSirasi);
    push(temp, &muayeneOdasi);

    temp = dequeue(&hastaSirasi);
    push(temp, &muayeneOdasi);

    temp = dequeue(&hastaSirasi);
    push(temp, &muayeneOdasi);

    temp = dequeue(&hastaSirasi);
    push(temp, &muayeneOdasi);

    printQueue(hastaSirasi);
    printStack(muayeneOdasi);
    printList(gecmis);

    temp = pop(&muayeneOdasi);
    addList(temp, &gecmis);

    printQueue(hastaSirasi);
    printStack(muayeneOdasi);
    printList(gecmis);

    temp = pop(&muayeneOdasi);
    addList(temp, &gecmis);

    temp = pop(&muayeneOdasi);
    addList(temp, &gecmis);

    printQueue(hastaSirasi);
    printStack(muayeneOdasi);
    printList(gecmis);

    return 0;
}