#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void insertAt(Node **head, int value, int position){
    Node *newNode;
    (newNode) = (Node*)malloc(sizeof(Node));

//Malloc işlemi için kontrol
    if ((newNode) == NULL){
        printf("Bellekte yer tahsis edilemedi...");
        exit(1);
    }

//Yeni Node için değer ve next ataması  
    newNode->data = value;
    newNode->next = NULL;

/*İlk düğümün NULL ise veya girilen indis değeri pozitif değilse
baştaki düğümü yeni düğümü ata ve fonksiyondan çık*/
    if ((*head) == NULL || position <= 0){
        newNode->next = (*head);
        (*head) = newNode;
        
        return;
    }

//Düğümler arasında rahatça gezebilmek için current değişkeni tanımlandı
//Düğümü doğru pozisyona yerleştirmek için i değişkeni tanımlandı
    Node *current = (*head);
    int i = 0;

/*Bu döngü sonunda current her halükarda tam olarak istediğimiz indisi
gösteren düğümü gösterecektir */

/*Örneğin istediğimiz indis değeri anlık düğüm sayısından fazla ise
current-> next ile son düğümde duracağız. Ya da indis değerimiz anlık
düğüm sayısından az ise istediğiimiz indisi gösteren düğümü gösterecektir*/
    while( current->next != NULL && i < position - 1){
        i++;
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return;
}

//Girilen indis konumundaki düğümü silmek
void deleteAt(Node **head, int position){

    if ((*head) == NULL){
        printf("Liste bos...");
        return;
    }
//İndis ilk düğüm ise
    if (position <= 0){
        Node *temp = (*head);
        (*head) = (*head)->next;
        free(temp); 
        return;
    }

//İndis arada veya sondaysa

    Node *current = (*head);
    int i = 0;

//Yukarıdaki fonksiyonda yaptığımız gibi yaptık
    while ( current->next != NULL && i < position - 1){
        current = current->next;
        i++;
    }

//Olmayan vagonu silme işlemi yapılmasın diye bir if koyuyorum.
    if(current->next==NULL){
        return;
    }

/*temp değişkeni oluşturduk ve onu silmek istediğimiz düğüme tanımladık.
daha sonra silmek istediğimiz değişkenden önceki ve sonraki düğümleri 
birbirine bağladık*/ 
    Node *temp = current->next;
    current->next = temp->next;

    free(temp);
    return;
}

//Listeyi ekrana yazdırdığımız fonksiyon
void printList(Node *head){

//Liste boş mu dolu mu kontrolü
    if (head == NULL){
        printf("Liste bos...");
        return;
    }

//ilk düğümü current pointerına tanımladık ve döngüde kullandık
    Node *current = head;
    while ( current != NULL){
        printf("%d", current->data);

        if(current->next != NULL)
        printf(" -> ");

        current = current->next;
    }
    return;
}

//Listemizde bellekte yer tahsis ettiğimiz düğüğümleri serbest bırakıyoruz
void clear(Node **head){
    Node *temp;

    while( (*head) != NULL){
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    }
}
int main (){
    Node *head = NULL;

    insertAt(&head,13,4);
    insertAt(&head,23,3);
    insertAt(&head,3,0);
    insertAt(&head,33,4);
    insertAt(&head,44,7);
    insertAt(&head,6,1);
    insertAt(&head,93,4);

//Listeyi yazdır
    printf("Listenin ilk hali: ");
    printList(head);

//Bellir bir indisi sil
    printf("\n\nBazi indise sahip degerler siliniyor...");
    deleteAt(&head,3);
    deleteAt(&head,1);

/*Listenin ilk halinde 5. indisteki 33 değeri silinmez çünkü o silinene
kadar liste kaymıştır ve artık 5. indis yoktur*/
    deleteAt(&head,5);

    printf("\n\nListenin silme isleminden sonraki hali: \n");
    printList(head);

//Belleğe iade işlemi yapılıyor
    clear(&head);

//İade işlemi sonrası liste
    printf("\n\nListenin son hali: \n");
    printList(head);

    return 0;
}