#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//=======================================================================
//=======================================================================

//Tamanho da string
#define BUFF 100

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
    char nome[BUFF];
    int value;

}node;


typedef struct{

    node *headList;
    node *tailList;
    int size;

}Fila;

void makeList(Fila *l);

void enqueue(Fila *list, int value, char *nome);

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
    
    char string[BUFF];

    makeList(&list);

    while(op != 0){

        system(CLS);
        printf("----------------- SPOOL DE IMPRESSAO -----------------\n\n");
        printQueue(&list);
        printf("------------------------------------------------------\n");
        printf("1 - Adicionar documento na fila de impressao.\n");
        printf("2 - Iniciar impressao.\n");
        printf("0 - Sair.\n");

        scanf("%d", &op);

        switch(op){
            case 1:
                
                //zera a string 
                memset(string, 0, sizeof(char)*BUFF);

                printf("Informe o nome do documento: ");
                setbuf(stdin, NULL);
                fgets(string, BUFF, stdin); //lê a string
            
                string[strlen(string) - 1] = '\0'; //tira o caracter '\n'

                printf("Tempo que sera gasto para impressao: ");
                while(scanf("%d", &tempo) < 1){
                    setbuf(stdin, NULL);
                    printf("Tempo que sera gasto para impressao: ");
                }

                enqueue(&list, tempo, string);

                break;

            case 2:

                while(list.headList != NULL){
                    
                    system(CLS);
                    printf("   Iniciando impressao de [ %s ] ...\n", list.headList->nome);

                    sleep(2);
                    
                    while(list.headList->value != 0){

                        system(CLS);
                        printf("   Imprimindo [ %s ] ...\n", list.headList->nome);
                        printf("%4d segundos restantes.\n", list.headList->value);

                        list.headList->value--;

                        sleep(1);

                    }
                    
                    dequeue(&list);
                }
                
                _pause();

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

    l->headList = NULL;
    l->tailList = NULL;
    l->size = 0;

    return;
}

void enqueue(Fila *list, int value, char *nome){

    node *tempNode=NULL;

    if(list->size == 0){

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){
            
            tempNode->next = NULL;

            tempNode->value = value;

            strcpy(tempNode->nome, nome);

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

            strcpy(tempNode->nome, nome);
            
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

        printf("Tempo de impressao: %4d | Nome: %s\n", tempNode->value, tempNode->nome);
        
        tempNode = tempNode->next;
    }
    
    return;
}