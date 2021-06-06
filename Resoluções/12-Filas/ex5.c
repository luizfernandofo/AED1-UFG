#include<stdio.h>
#include<stdlib.h>

//=======================================================================
//=======================================================================

#ifdef _WIN32 // Includes both 32 bit and 64 bit
    #define CLS "cls"
    	    
#elif __linux__
    #define CLS "clear"

#endif

//=======================================================================
//=======================================================================

typedef struct Node{

    struct Node *next;
    int value;

}node;


typedef struct{

    node *headList;
    int size;

}Fila;

void makeList(Fila *l);

void enqueue(Fila *list, int value);

void dequeue(Fila *list);

void freeList(Fila *list);

void _pause();

void printQueue(Fila *fila);

//=======================================================================
//=======================================================================


int main(void){

    int op=-1;
    
    int tempo;

    Fila list;

    makeList(&list);

    while(op != 0){

        system(CLS);
        printf("----------------- FILA DE REQUERIMENTOS -----------------\n\n");
        printQueue(&list);
        printf("------------------------------------------------------\n");
        printf("1 - Adicionar R.A. na fila.\n");
        printf("0 - Sair.\n");

        scanf("%d", &op);

        switch(op){
            case 1:
                
                printf("Registro academico para protocolar requerimento: ");
                while(scanf("%d", &tempo) < 1){
                    setbuf(stdin, NULL);
                    printf("Registro academico para protocolar requerimento: ");
                }

                enqueue(&list, tempo);

                break;

            case 0:
                system(CLS);
                printf("Limpando Fila...\n");
                op = 0;
                freeList(&list);
                break;

            default: 
                system(CLS);
                printf("Opcao invalida!\n");
                _pause();
                break;
        }
    }

    return 0;
}

//=======================================================================

void makeList(Fila *l){

    l->headList = (node *) malloc(sizeof(node));

    if(l->headList == NULL) exit(1);
    
    //adicionar os valores 

    l->size = 1;

    return;
}

void enqueue(Fila *list, int value){

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

    return ;
}

void dequeue(Fila *list){

    node *tempNode=NULL;

    if(list->size == 0){

        list->headList = NULL;
        list->tailList = NULL;

        list->size = 0;

    }else if(list->size == 1){

        free(list->headList);

        list->headList = NULL;
        list->tailList = NULL;

        list->size = 0;

    }else if(list->size > 1){

        tempNode = list->headList;

        list->headList = list->headList->next;

        free(tempNode);

        list->size--;

    }

    return;
}

void freeList(Fila *list){

    while(list->size != 0) dequeue(list);

    return;
}

void _pause(){

    setbuf(stdin, NULL);
    printf("\nPressione ENTER para continuar..."); //não pode ter "lixo" no stdin para ela funcionar
    getchar();

    return;
}

void printQueue(Fila *fila){

    node *tempNode=NULL;

    tempNode = fila->headList;
    while(tempNode != NULL){

        printf("RA: %d\n", tempNode->value);
        
        tempNode = tempNode->next;
    }
    
    return;
}