#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/**
 * @brief Função recursiva para trocar as letras de uma frase/palavra informada pelo terminal.
 * 
 * @param frase endereço da frase.
 * @param size tamanho da frase/palavra com o caracter terminador.
 * @param i posição da casa que sofrerá a troca simétrica.
 */
void reverser(char *frase, int size, int i);

int main(int argc, char *argv[]){

    int size=0;
    char *frase = NULL, *fraseTemp = NULL, c;

    printf("Escreva o que quiser para que seja invertido.\n");

    while(1)
    {
        scanf("%c", &c);
        if(c == '\n')
        {
            size++;
            fraseTemp = realloc(frase, sizeof(char)*size);
            if(fraseTemp != NULL)
            {
                frase = fraseTemp;
                fraseTemp = NULL;
                
                frase[size-1] = '\0';
            }

            break;
        }
        else
        {
            size++;
            fraseTemp =(char *) realloc(frase, sizeof(char)*size);
            if(fraseTemp != NULL)
            {
                frase = fraseTemp;
                fraseTemp = NULL;
                
                frase[size-1] = c;
            }
        }

    }

    reverser(frase, size, 0);

    printf("%s\n", frase);

    free(frase);

    return 0;
}

//implementação da função

void reverser(char *frase, int size, int i){
    char c;

    if(i < (size-2)/2.0)
    {
        c = frase[size-2-i];
        frase[size-2-i] = frase[i];
        frase[i] = c;
        reverser(frase, size, ++i);
    }
    else return;
}