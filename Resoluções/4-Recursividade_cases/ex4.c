#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//conversao binaria

/**
 * @brief Função recursiva para converter números de base decimal inteiros positivos em base binária.
 * 
 * @param n Número que será convertido.
 * @param i Contador para posicionar os 0s e 1s no vetor.
 * @param bin Vetor do tipo char para armazenar os 0s e 1s.
 * @return Retorna o indice utilizado no vetor.
 */
int conversor(int n, int i, char *bin);

int main(int argc, char *argv[]){

    int i, max; //contadores
    int n;
    char bin[64]; //tamanho do vetor que recebera cada bit da divisão, pensando em um sistema 64 bits.

    printf("CONVERSOR DECIMAL -> BINARIO\n\n");
    printf("Digite um numero inteiro:\n");

    scanf("%d", &n);

    max = conversor(n, 0, bin);

    printf("\nDecimal: %d\nBinario: ", n);

    for(i=max; i>=0; i--)
    {
        printf("%d", bin[i]);
    }
    printf("\n");

    return 0;
}

//implementação das funções

int conversor(int n, int i, char *bin){
    int resto;

    if(n <= 0)
    {
        bin[0] = 0;
        return 0;
    } 

    if(n == 1)
    {
        bin[i] = 1;
        return i;
    }
    
    resto = n%2;

    bin[i] = resto;

    if(resto == 0) n /= 2;
    else n = (n-1)/2;

    conversor(n, ++i, bin);
}