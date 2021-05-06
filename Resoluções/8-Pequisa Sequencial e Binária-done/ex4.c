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

    printf("%d elementos na lista: <", list->size);
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

void searchList(lista *list, int search_value){

    node *tempNode=NULL;
    char found = 0;

    tempNode = list->headList;
    while(tempNode != NULL){

        if(tempNode->value == search_value){
            found = 1;
            break;
        }

        tempNode = tempNode->next;

    }
    
    if(found == 1) printf("Valor %d encontrado na lista no endereco %p.\n\n", search_value, tempNode);
    else printf("Valor nao encontrado na lista.\n\n");

    return ;
}

int main(void){

    int val, search_value;

    lista list;

    list = makeList();

    printf("Preencha a lista com numeros. Use -1 para encerrar.\n");

    while(1)
    {
        scanf("%d", &val);
        if(val == -1) break;

        addNode(&list, val);

    }

    printf("\n");

    printList(&list);

    printf("Insira o valor que deseja buscar na lista: ");
    scanf("%d", &search_value);

    printf("\n");
    searchList(&list, search_value);
    
    freeList(&list);

    return 0;
}
