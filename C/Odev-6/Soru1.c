#include <stdio.h>
#include <stdlib.h>

typedef struct Bst{
    struct Bst *left;
    struct Bst *right;
    int data;
} Bst;

// PDF'teki main fonksiyonu ile uyumlu olması için Node tanımı
typedef Bst* Node;

// Soru 1: BST'ye eleman ekleme fonksiyonu (Aynı değer kontrolü dahil)
Bst* insert(Bst *root, int value){
    if (root == NULL){
        Bst* newRoot = (Bst*)malloc(sizeof(Bst));
        if (newRoot == NULL) {
            printf("Bellek tahsis edilemedi!\n");
            exit(1);
        }
        newRoot->data = value;
        newRoot->left = NULL;
        newRoot->right = NULL;
        return newRoot;
    }

    if (value < root->data){
        root->left = insert(root->left, value);
    }
    else if (value > root->data){
        root->right = insert(root->right, value);
    }
    // Aynı değer verilirse yeni düğüm oluşturulmaz.

    return root;
}

// Soru 1: Küçükten büyüğe sıralı yazdıran inorder fonksiyonu
void inorder(Bst *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Soru 2: Ağaçta arama yapan fonksiyon (Bulunduysa 1, bulunamadıysa 0 döndürür)[cite: 3]
int search(Bst *root, int value){
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 1;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Soru 2: Ağuktaki en küçük değeri bulan fonksiyon (En soldaki düğüm)[cite: 3, 4]
int findMin(Bst *root){
    while (root->left != NULL){
        root = root->left;
    }
    return root->data;
}

// Soru 2'de istenen güncellenmiş main fonksiyonu[cite: 3, 4]
int main() {
    Node root = NULL;
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};
    
    for (int i = 0; i < 7; i++) {
        root = insert(root, numbers[i]);
    }

    if (search(root, 30))
        printf("30 agacta bulundu.\n");
    else
        printf("30 agacta bulunamadi.\n");

    if (search(root, 90))
        printf("90 agacta bulundu.\n");
    else
        printf("90 agacta bulunamadi.\n");

    if (root != NULL)
        printf("En kucuk eleman: %d\n", findMin(root));

    return 0;
}