#include<stdio.h>
#include<string.h>

struct pilha{
    
    char p[25];
    int topo;
    int tam;

}Pilha;


int main(void){

    char palavra[25];

    int tam;

    struct pilha p;

    int i,j; //contadores
    
    printf("\nDigite uma palavra, com no maximo 25 caracteres, para ser empilhada: ");

    fgets(palavra, 25, stdin);

    tam = strlen(palavra);

    palavra[tam-1] = '\0';

    tam--;

    p.tam = tam;

    printf("\n");

    printf("Empilhando a palavra.\n");

    j=0;
    for(i=tam-1; i>=1; i--){
        printf("%c ->", palavra[i]);

        p.p[j] = palavra[i];
        j++;
    }
    printf("%c\n", palavra[i]);
    p.p[j] = palavra[i];
    p.p[j+1] = '\0';

    p.topo = 0;

    printf("\n");

    printf("Desempilhando a palavra.\n");

    while(p.topo != p.tam){

        for(i=p.topo; i<p.tam-1; i++){
            printf("%c ->", p.p[i]);
        }
        printf("%c\n", p.p[i]);

        p.topo++;
    }
    
    return 0;
}