#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/**
 * @brief Calcula recursivamente o mínimo divisor comum entre dois números.
 * 
 * @param num1 Número 1.
 * @param num2 Número 2.
 * @param div Divisor. Deve começar em 2, caso contrário retornará 1.
 * @return Retorna (int) -1 se não houver minDC diferente de 1 ou div caso exista.
 */
int minDivCom(int num1, int num2, int div);

int main(int argc, char *argv[]){

    int num1, num2, res;

    printf("\nInforme 2 (dois) numeros inteiros positivos para ser calculado\no minimo divisor comum entre eles:\n");

    scanf("%d %d", &num1, &num2);

    res = minDivCom(num1, num2, 2);

    if(res != -1) printf("MinDC de %d e %d = %d\n", num1, num2, res);
    else printf("Nao ha divisor minimo comum diferente de 1 entre os numeros %d e %d\n", num1, num2);

    return 0;
}

//implementação das funções

int minDivCom(int num1, int num2, int div){

    if(div > num1 || div > num2) return -1;

    if(num1%div == 0 && num2%div == 0) return div;
    else return minDivCom(num1, num2, ++div);

}