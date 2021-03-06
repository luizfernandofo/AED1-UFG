#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/**
 * @brief Função que busca recursivamente por um caracter em uma frase. Ambos informados pelo usuário.
 * 
 * @param string Frase onde será buscado o caracter.
 * @param size Tamanho da string com '\0'.
 * @param c Caracter que será buscado.
 * @param i Contador que marca o início da busca.
 * @return A casa do caracter encontrado + 1. Caso não contrario retorna -1.
 */
int finder(char *string, int size, char c, int i);

int main(int argc, char *argv[]){

    int size=0;
    char *frase = NULL, *fraseTemp = NULL, c;

    printf("Digite uma frase e finalize com ENTER.\n");

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

    printf("Qual caracter gostaria de procurar na frase?\n");

    scanf("%c", &c);

    size = finder(frase, size, c, 0);//reutilizei a variável size para pegar o retorno da função

    if(size != -1) printf("Caracter '%c' encontrado na posicao %d da string.\n", c, size);
    else printf("Caracter '%c' nao encontrado na string.\n", c);

    free(frase);

    return 0;
}

//implementação da função

int finder(char *string, int size, char c, int i){

    if(i < size)
    {
        if(string[i] == c) return i+1;
        else finder(string, size, c, ++i);
    }else return -1;

}