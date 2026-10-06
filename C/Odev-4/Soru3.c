#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PrintJob {
    char fileName[50];
    struct PrintJob* next;
} PrintJob;

typedef struct Queue {
    PrintJob* front;
    PrintJob* rear;
} Queue;

void enqueuePrintJob(Queue* q, char* fileName) {
    PrintJob* newJob = (PrintJob*)malloc(sizeof(PrintJob));
    if (newJob == NULL) exit(1);
    
    strcpy(newJob->fileName, fileName);
    newJob->next = NULL;

    if (q->rear == NULL) {
        q->front = newJob;
        q->rear = newJob;
        return;
    }
    
    q->rear->next = newJob;
    q->rear = newJob;
}

void processNextJob(Queue* q) {
    if (q->front == NULL) {
        printf("Kuyruk bos, yazdirilacak dosya yok.\n");
        return;
    }
    
    PrintJob* temp = q->front;
    printf("Yazdiriliyor: %s\n", temp->fileName);
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
}

void showQueue(Queue q) {
    if (q.front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    
    PrintJob* current = q.front;
    printf("Bekleyen dosyalar: ");
    while (current != NULL) {
        printf("%s ", current->fileName);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    
    int secim;
    char dosyaAdi[50];

    while (1) {
        printf("\n1-Yeni dosya ekle\n2-Yazdir\n3-Kuyrugu goster\n4-Cikis\n> ");
        scanf("%d", &secim);

        if (secim == 1) {
            printf("Dosya adi: ");
            scanf("%s", dosyaAdi);
            enqueuePrintJob(&q, dosyaAdi);
        } else if (secim == 2) {
            processNextJob(&q);
        } else if (secim == 3) {
            showQueue(q);
        } else if (secim == 4) {
            break;
        } else {
            printf("Gecersiz secim.\n");
        }
    }
    
    return 0;
}