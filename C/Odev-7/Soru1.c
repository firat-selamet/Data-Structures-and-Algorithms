#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* insert(Node *root, int value){
    if ( root == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Bellek tahsis edilemedi...");
            exit(1);
        }
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (root->data > value){
        root->left = insert(root->left, value);
        return root;
    }
    else if (root->data < value){
        root->right = insert(root->right, value);
        return root;
    }

    return root;
}

int search (Node *root, int value){
    if (root == NULL){
        return 0;
    }

    printf("Su an %d dugumune bakildi...\n", root->data);

    if (root->data == value){
        return 1;
    }
    if (root->data > value){
        return search(root->left, value);
    }
    if (root->data < value){
        return search(root->right, value);
    }
}

int main(){

    Node *root = NULL;

    int numbers[] = {5,9,2,4,1};
    int i;
    int tahmin;

    for(i = 0 ; i < 5 ; i++){
        root = insert(root, numbers[i]);
    }

    printf("Aramak istedigin hazine degerini gir\n");
    scanf("%d", &tahmin);

    if (search(root, tahmin) == 1){
        printf("Tebrikler... Hazineyi buldun!!!\n\n");
    }
    else{
        printf("Hazineyi bulamadin...\n\n");
    }

    return 0;
}