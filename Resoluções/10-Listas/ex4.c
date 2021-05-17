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

void remove_value(lista *list, int val);

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
    
    printf("Qual a posicao do valor que deseja remover da lista? (1 para o primeiro elemento, 2 para o segundo...) ");
    scanf("%d", &val);

    printf("\n");

    remove_value(&list, val);

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

void remove_value(lista *list, int val){

    node *tempNode=NULL, *nodeAnterior=NULL;

    char removed = 0;

    tempNode = list->headList;

    if(val <= 1){

        if(list->headList->next != NULL){ //verifica se há algum elemento depois da cabeça da lista

            list->headList = list->headList->next;

            list->size--;

            free(tempNode); //libera o elemento

            removed = 1;
            
        }
        else{ //caso não haja ele irá remover a cabeça que também era a cauda e setar a lista.

            list->headList = NULL;
            list->tailList = NULL;
            list->size=0;

            free(tempNode); //libera o elemento

            removed = 1;

        }

    }else if(val <= list->size){

        while(tempNode != NULL){
            
            nodeAnterior = tempNode;
            tempNode = tempNode->next;

            val--;

            if(val == 1){

                if(tempNode->next == NULL){ //verifica se o elemento possui outro na frente ou se é o último
                    nodeAnterior->next = NULL;
                    list->tailList = nodeAnterior;

                }else nodeAnterior->next = tempNode->next;

                list->size--;

                val = tempNode->value;

                free(tempNode); //libera o elemento

                removed = 1; //sinaliza que o valor foi removido

                break;
                
            }

        }

    }

    if(removed == 1) printf("Valor %d removido da lista.\n\n", val);
    else printf("Posicao informada e invalida.\n\n");

    return ;
}