#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int height;
    struct Node* right;
    struct Node* left;
}Node;

Node* createNode(int value){    
    Node* newNode = (Node*)malloc(sizeof(Node));
   
    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int height (Node* N){
    if (N == NULL)
        return 0;
    else
        return N->height;
}

int balanceFactor(Node *N){
    if (N == NULL)
        return 0;
    else
        return height(N->left) - height(N->right);
}

Node* rotateLeft(Node* y){
    Node* x = y->right;
    Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    int yleftH = height(y->left);
    int yrightH = height(y->right);

    int xleftH = height(x->left);
    int xrightH = height(x->right);
    
    y->height = (yleftH > yrightH) ? yleftH + 1 : yrightH + 1;
    x->height = (xleftH > xrightH) ? xleftH + 1 : xrightH + 1;
    
    return x;
}

Node* rotateRight(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    int yleftH = height(y->left);
    int yrightH = height(y->right);

    int xleftH = height(x->left);
    int xrightH = height(x->right);
    
    y->height = (yleftH > yrightH) ? yleftH + 1 : yrightH + 1;
    x->height = (xleftH > xrightH) ? xleftH + 1 : xrightH + 1;
    
    return x;
}

Node* insertAVL(Node* root, int value){
    if (root == NULL){
        return createNode(value);
    }

    if (root->data < value){
        root->right = insertAVL(root->right, value);
    }
    else if(root->data > value){
        root->left = insertAVL(root->left, value);
    }

    int rightH = height(root->right);
    int leftH = height(root->left);

    root->height = (rightH > leftH) ? rightH + 1 : leftH + 1;

    int balance = balanceFactor(root);

    if(balance < -1 && root->right->data < value){
        printf("\n\n\nRR dengesizligi, Sol rotasyon\n");
        return rotateLeft(root);
    }
    else if(balance > 1 && root->left->data > value){
        printf("\n\n\nLL dengesizligi, Sag rotasyon\n");
        return rotateRight(root);
    }
    else if(balance < -1 && root->right->data > value){
        printf("\n\n\nRL dengesizligi, Once Sag rotasyon Sonra Sol rotasyon\n");
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    else if(balance > 1 && root->left->data < value){
        printf("\n\n\nLR dengesizligi, Once Sol rotasyon Sonra Sag rotasyon\n");
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    return root;
}

void inOrder(Node* root){
    if (root == NULL)
    return;

    inOrder(root->left);

    printf("%d ", root->data);

    inOrder(root->right);
}

void preOrder(Node* root){
    if (root == NULL)
    return;

    printf("%d ", root->data);

    preOrder(root->left);

    preOrder(root->right);
}
int main(){
    Node* rootA = NULL;
    Node* rootB = NULL;
    Node* rootC = NULL;
    Node* rootD = NULL;

    //rootA için fonksiyon çağrımları-RR
    rootA = insertAVL(rootA,10);
    rootA = insertAVL(rootA,20);
    rootA = insertAVL(rootA,30);

    printf("Root: %d\n\n", rootA->data);

    inOrder(rootA);

    printf("\n\n");

    preOrder(rootA);

    //rootB için fonksiyon çağrımları-LL
    rootB = insertAVL(rootB,30);
    rootB = insertAVL(rootB,20);
    rootB = insertAVL(rootB,10);

    printf("Root: %d\n\n", rootB->data);

    inOrder(rootB);

    printf("\n\n");

    preOrder(rootB);

    //rootC için fonksiyon çağrımları-RL
    rootC = insertAVL(rootC,10);
    rootC = insertAVL(rootC,30);
    rootC = insertAVL(rootC,20);

    printf("Root: %d\n\n", rootA->data);

    inOrder(rootC);

    printf("\n\n");

    preOrder(rootC);

    //rootD için fonksiyon çağrımları-LR
    rootD = insertAVL(rootD,30);
    rootD = insertAVL(rootD,10);
    rootD = insertAVL(rootD,20);

    printf("Root: %d\n\n", rootD->data);

    inOrder(rootD);

    printf("\n\n");

    preOrder(rootD);   

    return 0;
}