#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int minDivCom(int num1, int num2, int div);

int main(int argc, char *argv[]){

    int num1, num2;

    printf("Informe 2 (dois) numeros inteiros positivos para ser calculado\no minimo divisor comum entre eles:\n");

    scanf("%d %d", &num1, &num2);

    minDivCom(num1, num2, 2);

    return 0;
}

//implementação das funções

int minDivCom(int num1, int num2, int div){

}