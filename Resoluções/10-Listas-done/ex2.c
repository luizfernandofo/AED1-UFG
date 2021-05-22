#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

    struct Node *next;
    int value;

}node;


typedef struct{

    node *headList;
    node *tailList;
    int size;

}lista;

lista makeList();

void addNode(lista *list, int value);

void printList(lista *list);

void freeList(lista *list);


int main(void){

    int qtd, val, i;

    lista list;

    list = makeList();

    printf("Qual o tamanho da lista?\n");
    scanf("%d", &qtd);

    for(i=0; i<qtd; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &val);
        addNode(&list, val);

    }

    printf("\n");

    printList(&list);
    
    freeList(&list);

    return 0;
}


lista makeList(){

    lista l;

    l.headList = NULL;
    l.tailList = NULL;
    l.size = 0;

    return l;
}

void addNode(lista *list, int value){

    node *tempNode=NULL;

    if(list->size == 0){

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){
            tempNode->next = NULL;
            tempNode->value = value;

            list->headList = list->tailList = tempNode;

        }else{
            printf("Falha na alocacao de um nodo.\n");
            exit(1);
        }

        list->size++;
        
    }else{

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){
            tempNode->next = NULL;
            tempNode->value = value;
            
            list->tailList->next = tempNode;

            list->tailList = tempNode;

        }else{
            printf("Falha na alocacao de um nodo.\n");
            exit(1);
        } 

        list->size++;

    }

    printf("Node %d adicionado.\n", list->size);

    return ;
}

void printList(lista *list){

    node *tempNode=NULL;

    tempNode = list->headList;

    printf("%d elemento(s) na lista: <", list->size);
    while(tempNode != NULL){
        printf("%d, ", tempNode->value);

        tempNode = tempNode->next;
    }
    printf(">\n\n");
    return ;
}

void freeList(lista *list){

    node *tempNode=NULL;

    
    while(list->headList != NULL){
        
        tempNode = list->headList;
        
        list->headList = list->headList->next;
        
        free(tempNode);

        list->size--;
    }


}

