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
    
    int ra;

    Fila list;

    makeList(&list);

    while(op != 0){

        system(CLS);
        printf("----------------- FILA DE REQUERIMENTOS -----------------\n\n");
        printQueue(&list);
        printf("------------------------------------------------------\n");
        printf("1 - Adicionar R.A. na fila.\n");
        printf("2 - Chamar proximo da fila.\n");
        printf("0 - Sair.\n");

        scanf("%d", &op);

        switch(op){
            case 1:
                
                printf("Registro academico para protocolar requerimento: ");
                while(scanf("%d", &ra) < 1){ // evita erros na leitura de um outro valor senão um int.
                    setbuf(stdin, NULL);
                    printf("Registro academico para protocolar requerimento: ");
                }

                enqueue(&list, ra); // insere o valor na fila com o devido tratamento para o descritor do final da fila

                break;

            case 2:

                dequeue(&list); // elimina o primeiro elemento (FI-FO)

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

    l->size = 0;

    return;
}

void enqueue(Fila *list, int value){

    node *tempNode=NULL;

    if(list->size == 0){ // condição para a fila vazia

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){
            
            list->headList = tempNode; // "seta" a cabeça da fila para o primeiro elemento alocado

            tempNode->next = tempNode; // o "next" do elemento alocado recebe ele mesmo

            tempNode->value = value; // recebe o valor informado na chamada da função


        }else{
            printf("Falha na alocacao de um nodo.\n");
            exit(1);
        }

        list->size++;
        
    }else{ // caso a fila já possua um elemento ou mais

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){

            tempNode->next = list->headList->next; // o elemento alocado tem seu "next" como o segundo elemento
            // já que o primeiro é o descritor do final da fila

            list->headList->next = tempNode; // o "next" do elemento "final" da fila recebe o elemento alocado, isso faz da fila uma lista circular

            list->headList = tempNode; // e a cabeça da fila passa a ser o novo último elemento

            tempNode->value = value;
            

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

        list->size = 0;

    }else if(list->size == 1){

        free(list->headList);

        list->headList = NULL;

        list->size = 0;

    }else if(list->size > 1){ // se a fila possuir mais de um elemento a desalocação sempre pula o primeiro
    // elemento que é o que armazena o final da fila

        tempNode = list->headList->next;

        list->headList->next = list->headList->next->next;

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

    int size = fila->size;

    unsigned char printed = 0;

    node *tempNode=NULL;

    tempNode = fila->headList;
    while(size != 0){

        printf("RA: %d", tempNode->value);
        
        if(printed == 0){ // booleano usado para indicar que o primeiro elemento que aparece na fila é o último
            printf("\t(descritor da posicao final)\n");
            printed = 1;
        }
        else printf("\n");

        tempNode = tempNode->next;

        size--;
    }
    
    return;
}