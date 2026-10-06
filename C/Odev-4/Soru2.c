#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word {
    char text[50];
    struct Word* next;
} Word;

void pushWord(Word** top, char* text) {
    Word* newWord = (Word*)malloc(sizeof(Word));
    if (newWord == NULL) exit(1);
    strcpy(newWord->text, text);
    newWord->next = *top;
    *top = newWord;
}

void popWord(Word** top) {
    if (*top == NULL) return;
    Word* temp = *top;
    *top = (*top)->next;
    free(temp);
}

void printReverse(Word* top) {
    if (top == NULL) return;
    printReverse(top->next);
    printf("%s ", top->text);
}

void showWords(Word* top) {
    if (top == NULL) {
        printf("Bos\n");
        return;
    }
    printReverse(top);
    printf("\n");
}

int main() {
    Word* top = NULL;
    char command[20];
    char text[50];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s", text);
            pushWord(&top, text);
        } else if (strcmp(command, "undo") == 0) {
            popWord(&top);
        } else if (strcmp(command, "show") == 0) {
            printf("-> ");
            showWords(top);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Gecersiz komut.\n");
        }
    }
    return 0;
}