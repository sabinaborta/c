
#include <stdio.h>
#include <stdlib.h>

/* Structura unei liste simplu inlantuite*/
struct node {
   int data;
  struct node *next;
} *LLOne, *LLTwo, *unionLL;

void initialize(){
    LLOne = LLTwo = NULL;
}

void insert(struct node **head, int num) {
    /* Se creaza un nou nod */
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    /* Urmatorul poinet al noului nod */
    newNode->next = *head;
    *head = newNode;
}

/* Se cauta un element in lista prin traversarea liniara a acesteia de la cap la coada */
int search(struct node *head, int num) {
    while (head != NULL) {
        if (head->data == num){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

/*
Returneaza uniunea celor doua liste
*/
struct node* findunion(struct node *LLOne, struct node *LLTwo) {
    unionLL = NULL;
    /* Adauga toate nodurile din prima lista */
    struct node *temp = LLOne;
    while(temp != NULL){
        insert(&unionLL, temp->data);
        temp = temp->next;
    }
    /* Se insereaza toata nodurile din a doua lista ce nu se afla in prima*/
    while(LLTwo != NULL){
        if(!search(LLOne, LLTwo->data)){
            insert(&unionLL, LLTwo->data);
        }
        LLTwo = LLTwo->next;
    }
    return unionLL;
}

/*
Afisarea listei de la cap la coada
*/
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
/*Returneaza cel mai mare element*/
int getMaxNode(struct node *stnode){
    if(stnode == NULL){
        printf(" User message : Invalid Input !!!\n");
        return 0;
    }
    int max = stnode->data;
    while(stnode != NULL){
        if(stnode->data > max){
            max = stnode->data;
        }
        stnode = stnode->next;
    }
    return max;
}
/*Returneaza cel mai mic element*/
int getMinNode(struct node *stnode){
    if(stnode == NULL){
    printf(" User message : Invalid Input !!!\n");
    return 0;
    }
    int min=stnode->data;
    while(stnode!=NULL){
        if(stnode->data<min){
            min=stnode->data;
        }
        stnode=stnode->next;
        }
    return min;
}

int main() {
    int i, LLOneCount, LLTwoCount, temp;
    initialize();
    /*Se creaza prima lista*/
    printf("Enter number of nodes in first Linked List\n");
    scanf("%d", &LLOneCount);
    printf("Enter %d integers\n", LLOneCount);
    for(i=0; i<LLOneCount; i++){
        scanf("%d", &temp);
        insert(&LLOne, temp);
    }
    printLinkedList(LLOne);
    /*Se creaza a doua lista*/
    printf("\nEnter number of nodes in second Linked List\n");
    scanf("%d", &LLTwoCount);
    printf("Enter %d integers\n", LLTwoCount);
    for(i=0; i<LLTwoCount; i++){
        scanf("%d", &temp);
        insert(&LLTwo, temp);
    }
    printLinkedList(LLTwo);
    /* Afisarea uniunii celor doua liste */
    findunion(LLOne, LLTwo);

    printf("\nUnion Linked List\n");
    printLinkedList(unionLL);
    printf("\n");
    printf("Biggest element in the union: %d\n",getMaxNode(unionLL));
    printf("Smallest element in the union: %d\n",getMinNode(unionLL));

    return 0;
}
