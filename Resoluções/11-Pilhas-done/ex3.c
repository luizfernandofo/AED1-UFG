#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{

    int tombo;
    struct node *next;

}Node;


struct pilha{
    
    Node *topo;

    int tam;

};


int main(void){

    int tombo=0;

    struct pilha p;

    int i; //contadores

    Node *temp=NULL, *anterior=NULL;

    unsigned char removeu = 0;
    
    p.topo = NULL;

    p.tam=0;

    printf("\nInsira os \"tombos\" e finalize com -1.\n");

    while(1){

        scanf("%d", &tombo);

        if(tombo == -1) break;

        if(p.tam == 0){

            temp = (Node *) malloc(sizeof(Node));

            if(temp != NULL){

                p.topo = temp;
                p.topo->tombo = tombo;
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

                p.topo->tombo = tombo;
                p.tam++;

            }else{
                printf("Falha na alocacao de um nodo.\n");
                exit(1);
            }

        }

        i++;

    }

    printf("\nPilha antes da eliminacao:\n");

    //imprime a pilha
    temp = p.topo;
    while(temp != NULL){
        printf("%d -> ", temp->tombo);

        temp = temp->next;
    }
    printf("\n\n");

    printf("Informe um \"tombo\" para ser removido: ");
    scanf("%d", &tombo);
    printf("\n");

    //remove o tombo informado
    temp = p.topo;
    while(temp != NULL){

        if(temp->tombo == tombo){

            if(temp == p.topo) p.topo = p.topo->next;

                else if(temp->next != NULL) anterior->next = temp->next;
            
                    else anterior->next = NULL;
            
            free(temp);

            p.tam--;

            removeu = 1;

            break;
        }

        anterior = temp;
        temp = temp->next;
    }
    
    if(removeu == 0) printf("\"Tombo\" nao encontrado!\n\n");
    else{

        printf("Pilha apos a eliminacao:\n");

        //imprime a pilha
        temp = p.topo;
        while(temp != NULL){
            printf("%d -> ", temp->tombo);

            temp = temp->next;
        }
        printf("\n");

    }

    //limpa a pilha
    while(p.topo != NULL){

        temp = p.topo;

        p.topo = p.topo->next;

        free(temp);

    }

    return 0;
}