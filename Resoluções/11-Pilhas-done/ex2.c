#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{

    char c;
    struct node *next;

}Node;


struct pilha{
    
    Node *topo;

    int tam;

};


int main(void){

    char palavra[25];

    int tam;

    struct pilha p;

    int i; //contadores

    Node *temp=NULL;
    
    p.topo = NULL;

    p.tam=0;
    
    printf("\nDigite uma palavra, com no maximo 25 caracteres, para ser empilhada: ");

    fgets(palavra, 25, stdin);

    tam = strlen(palavra);

    palavra[tam-1] = '\0';

    tam--;

    printf("\n");

    printf("Empilhando a palavra...\n");
    printf("\n");

    i=0;
    while(palavra[i] != '\0'){

        if(i == 0){

            temp = (Node *) malloc(sizeof(Node));

            if(temp != NULL){

                p.topo = temp;
                p.topo->c = palavra[i];
                p.topo->next = NULL;
                p.tam++;

            }else{
                printf("Falha na alocacao de um nodo.\n");
                exit(1);
            }

        }else{

            temp = (Node *) malloc(sizeof(Node));

            if(temp != NULL){

                temp->next = p.topo;
                p.topo = temp;

                p.topo->c = palavra[i];
                p.tam++;

            }else{
                printf("Falha na alocacao de um nodo.\n");
                exit(1);
            }

        }

        i++;

    }

    printf("Desempilhando a palavra...\n");
    printf("\n");

    while(p.topo != NULL){

        temp = p.topo;
        while(temp != NULL){
            printf("%c -> ", temp->c);

            temp = temp->next;
        }
        printf("\n");

        temp = p.topo;

        p.topo = p.topo->next;

        free(temp);

    }
    
    printf("\n");

    return 0;
}