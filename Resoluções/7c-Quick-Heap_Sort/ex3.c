#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void quickSort(char *vet[], int began, int tam){

    int i, j;
    char pivo[75];
    char tempS[75];

    i = began;
    j = tam - 1;

    memset(pivo, 0, 75);
    strcpy(pivo, vet[(began + tam) / 2]); //pivô é uma das strings dentro de **vet;

    while (i <= j){
        while (strcmp(vet[i], pivo) > 0 && i < tam) i++; //compara o retorno do strcmp da string e do pivô

        while (strcmp(vet[j], pivo) < 0 && j > began) j--;
        
        if (i <= j){
            memset(tempS, 0, 75);

            strcpy(tempS, vet[i]);
            strcpy(vet[i], vet[j]);
            strcpy(vet[j], tempS);

            i++;
            j--;
            
        }
        
    }
    if (j > began) quickSort(vet, began, j + 1);
    
    if (i < tam) quickSort(vet, i, tam);

    return;
    
}

//=======================================================

int main(void){

    char **nomes=NULL, **nomeTemp=NULL, 
    tempC[74+1]; //buffer para salvar o nome lido
    int tam=0, i, j; //contadores
    

    printf("Digite um nome e confirme com ENTER\nPara finalizar a leitura use o indicador de fim de leitura do seu sistema operacional (ex.: CTRL + Z) e de ENTER:\n");

    while(1){

        memset(tempC, 0, 75);
        if(scanf("%74[^\n]", tempC) == EOF) break; //CTRL + Z no windows indica fim da leitura
        setbuf(stdin, NULL);

        tam++;

        nomeTemp = (char**) realloc(nomes, sizeof(char *)*tam); //aloca endereço para mais um nome
        if(nomeTemp != NULL){
            nomes = nomeTemp; 
            nomeTemp = NULL;

        }else{
            for(i=0; i<tam; i++) free(nomes[i]);
            free(nomes);
        }
        
        nomes[tam-1] = (char *) calloc(75, sizeof(char)); //aloca memória para comportar o nome referente ao endereço alocado acima

        strcpy(nomes[tam-1], tempC);

        //Transforma todos caracteres em letras minúsculas para as comparações
        for(i=0; i<75; i++){
            if(nomes[tam-1][i] > 64 && nomes[tam-1][i] < 91) nomes[tam-1][i] += 32;
        }
    }
    
    quickSort(nomes, 0, tam);

    //Transforma os caracteres iniciais dos nomes em letras maiúsculas
    for(i=0; i<tam; i++){
        nomes[i][0] -= 32;
        for(j=1; j<74; j++){
            if(nomes[i][j] == 32 && nomes[i][j+1] > 96 && nomes[i][j+1] < 123){
                nomes[i][j+1] -= 32;
                j++;
            }
        } 
    }
    
    i = tam;

    //Imprime o resultado
    printf("\nNomes em ordem crescente:\n\n");
    while(i>0)
    {
        printf("%s\n", nomes[i-1]);
        i--;
    }
    printf("\n");

    //limpa a memória alocada
    for(i=0; i<tam; i++) free(nomes[i]);  
    free(nomes);

    return 0;
}

