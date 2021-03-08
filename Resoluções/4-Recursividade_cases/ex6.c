#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double my_sqrt(double n, double x);

double modulo(double x);

int main(int argc, char *argv[]){

    double n, resp;

    printf("Qual numero voce deseja calcular a raiz quadrada?\n");

    scanf("%lf", &n);

    resp = my_sqrt(n, 1); //retorno está dando errado: 1.#NAN

    printf("Raiz quadrada de %.3lf = %lf\n", n, resp);

    return 0; 
}

//implementação das funções

double my_sqrt(double n, double x){

    double error = 0.0001;

    printf("%.15lf\n", x);
    if(modulo(n - (x*x)) <= error) return x; //condição de parada

    x = (x/2.0) + (n/(2.0*x));
    
    //system("pause");
    my_sqrt(n, x);
    
    printf("pos: %.15lf\n", x);
}

double modulo(double x){

    if(x > 0) return x;
    else return -x;

}