#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define MAX 5

float * alocador(int tamanho);

int main(int argc, char *argv[]){

    float *vetor[MAX];
    int tamanho[MAX];
    int i,j; //contadores

    for(i=0; i<MAX; i++)
    {
        printf("Informe o tamanho do vetor %d: \n", i+1);
        scanf("%d", &tamanho[i]);

        vetor[i] = alocador(tamanho[i]);

        if(vetor[i] == NULL)
        {
            printf("Falha na alocacao de memoria do vetor %d.\n", i+1);

            i--; //subtrai uma unidade de i para limpar a malloc dos outros vetores alocados
                 //já que a casa i é nula.

            for(; i>=0; i--) free(vetor[i]);

            return 0;
        }

        printf("Informe o(s) %d valor(es) do vetor %d:\n", tamanho[i], i+1);

        for(j=0; j<tamanho[i]; j++) scanf("%f", &vetor[i][j]);
        
    }

    for(i=0; i<MAX; i++)
    {
        printf("Vetor %d: ", i+1);

        for(j=0; j<tamanho[i]; j++) printf("%.2f ", vetor[i][j]);
        
        printf("\n");
    }
        
    for(i=0; i<MAX; i++) free(vetor[i]); //limpa a malloc dos vetores antes de fechar o programa

    return 0;
}

//implementação das funções

float * alocador(int tamanho){

   return (float *) malloc(sizeof(float)*tamanho); 

}