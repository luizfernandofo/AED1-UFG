#include<stdio.h>
#include<stdlib.h>

//não verifica ano bissexto, nem se o mês é 30/31.

char const months[12][10] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

int main(int argc, char const *argv[])
{
    int d, m, y;

    if(argc != 4)
    {
        printf("Invalid arguments\nCorrect usage: .\\ex3 dd mm yyyy\n");
        return 0;
    }

    d = atoi(argv[1]);
    m = atoi(argv[2]);
    y = atoi(argv[3]);

    if(d > 31 || d < 1)
    {
        printf("Numero de dias informado e invalido!\n");
        return 0;
    }

    if(m > 12 || m < 1)
    {
        printf("Numero do mes informado e invalido!\n");
        return 0;
    }

    printf("%d de %s de %d\n", d, months[m-1], y);

    return 0;
}
