#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song{
    char name [50];
    struct Song *next;
    struct Song *prev;
}Song;

void addSongToEnd(Song** head, char* isim){
    Song *newSong;
    newSong = (Song*)malloc(sizeof(Song));

    if (newSong == NULL){
        printf("Bellek tahsis edilemedi");
        exit(1);
    }

    strcpy(newSong->name, isim);
    newSong->next = NULL;
    newSong->prev = NULL;

    if ((*head) == NULL){
        (*head) = newSong;
        return;
    }

    Song *current = (*head);

    while(current->next != NULL){
        current = current->next;
    }

    newSong->prev = current;
    newSong->next = current->next;
    current->next = newSong;
}

void removeSong(Song** head, char* isim){
    if ((*head) == NULL){
        printf("Liste bos...\n");
        return;
    }

    Song *current = (*head);

    while (current != NULL && strcmp(current->name, isim) != 0){
        current = current->next;
    }
    
    if (current == NULL){
        printf("Aradaginiz sarki bulunamadi...");
        return;
    }

    if ((*head) == current){
        if ( current->next == NULL){
        (*head) = NULL;
        free(current);
        return;
        }
        current->next->prev = NULL;
        (*head) = current->next;
        free(current);
        return;
    }

    if (current->next == NULL){
        current->prev->next = NULL;
        free(current);
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    
    free (current);
}

void playNext(Song **current){
    if ((*current) == NULL){
        printf("Liste bos...");
        return;
    }
    if((*current)->next != NULL){
    (*current) = (*current)->next;
    printf("Sonraki sarki: %s\n", (*current)->name);
    return;
    }
    else
    printf("Zaten son sarkidasiniz...\n");
}

void playPrevious(Song **current) {
    if ((*current) == NULL){
        printf("Liste bos...");
        return;
    }
    if((*current)->prev != NULL){
    (*current) = (*current)->prev;
    printf("Onceki sarki: %s\n", (*current)->name);
    return;
    }
    else
    printf("Zaten ilk sarkidasiniz...\n");
}

void displayPlaylist(Song* head){
    Song * current = head;

    while (current != NULL){
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main(){
    Song *head = NULL;
    Song *currentSong = NULL; // Müzik çalarda o an çalan şarkıyı tutacak pointer

    int secim;
    char isim[50]; // Switch içinde tanımlamak C'de hata verir, dışarı aldık.

    while (1){
        printf("\n1-Sarki ekle\n");
        printf("2-Sarki sil\n");
        printf("3-Sonraki sarkiyi cal\n");
        printf("4-Onceki sarkiyi cal\n");
        printf("5-Calma listesini goster\n");
        printf("6-Cikis\n");

        printf ("Lutfen yapmak istediginiz islemi seciniz: ");
        scanf("%d", &secim);

        switch (secim){

            case 1 :
                printf("Eklemek istediginiz sarkinin adini giriniz: ");
                scanf("%s", isim);
                addSongToEnd(&head, isim);
                // Eğer listeye ilk şarkı eklendiyse, o an çalan şarkı otomatik o olsun
                if (currentSong == NULL) {
                    currentSong = head;
                }
                break;

            case 2 :
                printf("Silmek istediginiz sarkinin adini giriniz: ");
                scanf("%s", isim);
                
                // Eğer o an çalan şarkıyı siliyorsak, pointer boşluğa düşmesin diye başa alıyoruz
                if (currentSong != NULL && strcmp(currentSong->name, isim) == 0) {
                    currentSong = head; 
                }
                
                removeSong(&head, isim);
                
                // Silme işleminden sonra liste tamamen boşaldıysa currentSong'u NULL yap
                if (head == NULL) {
                    currentSong = NULL;
                }
                break;

            case 3 :
                // head'i değil, o an çalan şarkıyı (currentSong) kaydırıyoruz!
                playNext(&currentSong);
                break;

            case 4 :
                playPrevious(&currentSong);
                break;

            case 5 :
                printf("\n--- Calma Listesi ---\n");
                displayPlaylist(head);
                break;
                
            case 6 :
                printf("Cikis yapiliyor...\n");
                return 0; // Çıkış seçeneğini buraya ekledik
                
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}