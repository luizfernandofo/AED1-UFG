#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/**
 * @brief Calcula recursivamente o MDC entre dois números.
 * 
 * @param num1 Número 1.
 * @param num2 Número 2.
 * @param div Divisor. Deve começar em 2.
 * @param resp Reposta. Deve começar em 1.
 * @return Retorna resp (int).
 */
int MDC(int num1, int num2, int div, int resp);

int main(int argc, char *argv[]){

    int num1, num2, res;

    printf("Informe 2 (dois) numeros inteiros positivos para ser calculado o MDC:\n");

    scanf("%d %d", &num1, &num2);

    res = MDC(num1, num2, 2, 1);

    printf("MDC de %d e %d = %d\n", num1, num2, res);
    
    return 0;
}

//implementação das funções

int MDC(int num1, int num2, int div, int resp){

    //função não trata valores negativos para num1 e num2.

    int resto1, resto2;

    if(num1 == 1 && num2 == 1) return resp; //condição de parada.

    resto1 = num1 % div; //Recebe o valor do resto da divisão para poupar operações.
    resto2 = num2 % div;

    if(resto1 != 0 && resto2 != 0) return MDC(num1, num2, ++div, resp); //verifica se ambos números não sao mais multiplos de div e chama a função com um div maior.
    else
    {           
        if(resto1 == resto2)
        {
            num1 /= div;
            num2 /= div;

            resp *= div;

            return MDC(num1, num2, div, resp);

        }else if(resto1 == 0){
            num1 /= div;

            resp *= div;

            return MDC(num1, num2, div, resp);

        }else{
            num2 /= div;

            resp *= div;

            return MDC(num1, num2, div, resp);
        } 
    }
}