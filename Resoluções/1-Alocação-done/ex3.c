#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void readMatrix(int *matrix, int *l, int *c);
void printMatrix(int *matrix, int *l, int *c);

int main(int argc, char *argv[]){

    int l, c, *matriz=NULL;
    int i; //contadores

    printf("Informe a quantidade de linhas da matriz: \n");
    scanf("%d", &l);

    printf("Informe a quantidade de colunas da matriz: \n");
    scanf("%d", &c);

    matriz = (int *) malloc(sizeof(int)*(l*c));
    if(matriz == NULL)
    {
        printf("Falha na malloc da matriz!\n");
        return 0;
    }

    readMatrix(matriz, &l, &c);
    printMatrix(matriz, &l, &c);

    free(matriz);

    return 0;
}

//implementação das funções

void readMatrix(int *matrix, int *l, int *c){

    int i, j=(*c); //contadores
    int row = (*l), col = (*c); 
    int linha=0;

    
    for(i=0; i<row*col; i++)
    {
        
        if(j == col) 
        {
            printf("Insira os %d valores da linha %d:\n", col, linha);
            j = 0;
            linha++;
        }
        
        scanf("%d", &matrix[i]);    

        j++;
    }

}

void printMatrix(int *matrix, int *l, int *c){

    int i, j=0; //contadores
    int row = (*l), col = (*c); 
       
    printf("Matriz %dx%d:\n", row, col);

    for(i=0; i<row*col; i++)
    {
        if(j == col) 
        {
            printf("\n");
            j = 0;
        }
         
        printf("%d ", matrix[i]);    

        j++;
    }

}