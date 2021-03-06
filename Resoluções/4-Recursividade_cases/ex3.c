#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef unsigned long long int Uint64;

/**
 * @brief Calcula o n-ésimo termo da sequência de Fibonacci (a partir do 94º termo há overflow)
 * 
 * @param n1 Termo inicial.
 * @param n2 Termo inicial + 1.
 * @param n n-ésimo termo que será o resultado.
 * @return Uint64 
 */
Uint64 fifi(Uint64 n1, Uint64 n2, int n);

int main(int argc, char *argv[]){

    int n;

    printf("Informe qual termo da sequencia de Fibonacci voce deseja calcular:\n");

    scanf("%d", &n);

    printf("O %d termo da sequencia e: %llu\n", n, fifi(1,1, n));

    return 0;
}

//implementação das funções

Uint64 fifi(Uint64 n1, Uint64 n2, int n){
    Uint64 temp;

    if(n>2)
    {
        temp = n2;
        n2 += n1;
        n1 = temp;
        //printf("%lu\n", n2);
        fifi(n1,n2,--n);
        
    }else return n2;

}