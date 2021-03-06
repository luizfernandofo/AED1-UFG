#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[]){

    int l, c, **matrix=NULL;
    int i,j; //contadores

    printf("Informe a quantidade de linhas da matriz: \n");

    scanf("%d", &l);

    matrix = (int **) malloc(sizeof(int *) * l);
    if(matrix == NULL)
    {
        printf("Falha na malloc das linhas da matriz!\n");
        return 0;
    }

    printf("Informe a quantidade de colunas da matriz: \n");

    scanf("%d", &c);

    for(i=0; i<l; i++)
    {
        matrix[i] = (int *) malloc(sizeof(int) * c);
        if(matrix[i] == NULL)
        {
            printf("Falha na malloc das colunas da linha %d!\n", i+1);

            i--;

            for(; i>=0; i--) //desaloca as linhas já alocadas
            {
                free(matrix[i]);
            }

            free(matrix);

            return 0;
        }
    }

    for(i=0; i<l; i++)
        for(j=0; j<c; j++)
        {
            matrix[i][j] = rand() % 10; //preenche a linha i aleatoriamente;
        }
    

    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++) printf("%d ", matrix[i][j]); //imprime a matriz
            
        printf("\n");
    }
        
    for(i=0; i<l; i++)
        for(j=0; j<c; j++) free(matrix[i]); //limpa a malloc da matriz
        
    free(matrix);
    
    return 0;
}