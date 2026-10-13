#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word{
    char text [50];
    struct Word *next; 
}Word;

void pushWord(Word **top, char *text){

    Word *newWord = (Word*)malloc(sizeof(Word));

    if (newWord == NULL){
        printf("Bellek tahsis edilemedi");
        exit(1);
    }

    strcpy (newWord->text, text);
    newWord->next = (*top);
    (*top) = newWord;
    

}

void popWord(Word **top){

    if ((*top) == NULL){
        printf("undo edilecek kelime yoktur...\n");
        return;
    }

    Word *temp = (*top);
    
    (*top) = temp->next;
    
    free (temp);
}

void showWords(Word *top){

    if ((top) == NULL){
        printf("Gosterilecek kelime yoktur...\n");
        return;
    }

    printf("Kelimeler gosteriliyor:\n");

    Word *current = top;

    while ( current != NULL){
        printf("%s\n", current->text);
        current = current->next;
    }

}

int main(){

    Word *top = NULL;
    char text [50];
    
    char command [10];

    while(1){
        printf("Eleman eklemek icin 'add'\nEleman silmek icin 'undo'\nElemanlari gormek icin 'show'\nCikis yapmak icin 'exit' yazini:\n");
        scanf("%s", &command);

        if (strcmp(command, "add") == 0 ){
            printf("Kelime giriniz: ");
            scanf("%s", text);
            pushWord(&top, text);
        }

        if (strcmp(command, "undo") == 0 ){
            popWord(&top);
        }

        if (strcmp(command, "show") == 0 ){
            showWords(top);
        }

        if (strcmp(command, "exit") == 0 ){
            break;
        }
    }

    return 0;
}