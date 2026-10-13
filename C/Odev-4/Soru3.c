#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PrintJob{
    char fileName [50];
    struct PrintJob *next;
}PrintJob;

typedef struct Queue{
    PrintJob *front;
    PrintJob *rear;
}Queue;

void enqueuePrintJob(Queue *q, char *fileName){

    PrintJob *newPrint = (PrintJob*)malloc(sizeof(PrintJob));

    if (newPrint == NULL){
        printf("Bellek tahsis edilemedi\n");
        exit(1);
    }

    strcpy (newPrint->fileName, fileName);
    newPrint->next = NULL;

    if (q->rear == NULL){
        q->rear = newPrint;
        q->front = newPrint;
        return;
    }

    q->rear->next = newPrint;
    q->rear = newPrint;

}
void processNextJob(Queue *q){
    if (q->front == NULL){
        printf("Kuyruk bos...\n\n");
        return;
    }

    PrintJob *temp = q->front;

    printf("Yazdiriliyor: %s\n", temp->fileName);

    if (q->rear == q->front){
        q->rear = NULL;
    }

    q->front = q->front->next;

    free(temp);
     
}
void showQueue(Queue q){

    if (q.front == NULL){
        printf("Kuyruk tamamen bos...\n");
        return;
    }

        PrintJob *current = q.front;

        printf("Kuyruk gosteriliyor...\n");

        while (current != NULL){
            printf("%s\n", current->fileName);
            current = current->next;
        }
}

int main(){

    Queue q;

    q.front = NULL;
    q.rear = NULL;

    char fileName[50];

    int choise;

    while(1){
        printf("1- Yeni dosya ekle\n");
        printf("2- Yazdir\n");
        printf("3- Kuyrugu goster\n");
        printf("4- Cikis\n");

        printf("\nSeciminiz: ");
        scanf(" %d", &choise);

        switch(choise){
            case 1:
                printf("Eklemek istediginiz elemani giriniz: \n");
                scanf("%s", fileName);
                enqueuePrintJob(&q, fileName);
                break;
            case 2:
                processNextJob(&q);
                break;

            case 3:
                showQueue(q);
                break;

            case 4:
                printf("\n\nCikis yapiliyor...");
                return 0;
        };
    };

    return 0;
}