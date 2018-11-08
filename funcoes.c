///Autores:
/// Pablo Miranda Batista          3482
///Lucas Ranieri Oliveira Martins  3479
///João Victor Magalhães Souza     3483

#include "funcoes.h"
#include <stdio.h>


void verifica_menor_rota(int *menor_rota,int vetor[],int n,int matriz_rota[n+1][n+1],int x,int vetor_rota[], int *distancia){
    //x = numero referente a cidade de partida
    int i, j, distancia_rota=0;
    for (i = 1; i<n; i++){
        distancia_rota += matriz_rota[vetor[i-1]][vetor[i]];
    }
    distancia_rota += matriz_rota[x][vetor[0]];
    distancia_rota += matriz_rota[vetor[n-1]][x];

    if(distancia_rota < *menor_rota){
        *menor_rota = distancia_rota;
        for(i=0; i<n; i++){
            vetor_rota[i] = vetor[i];
        }
    }
    *distancia = distancia_rota;
}

void preenche_vetor(int vetor[], int n, int x){                /// Gerando os numeros das cidades.
    int i, aux=0;
    for (i=0; i<n+1; i++){
        if (i != x){
            vetor[aux] = i;
            aux++;
        }
    }
}


void troca(int vetor[], int i, int j)       ///Trocando posicoes do Vetor.
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup, int n, int matriz_rota[n+1][n+1], int x, int *menor_rota, int vetor_rota[])
{
    int distancia=0;
    if(inf == sup)
    {
        printf("%d ",x);
        for(int i = 0; i <= sup; i++){
            printf("%d ", vetor[i]);
        }
        printf("%d ",x);

        verifica_menor_rota(menor_rota, vetor, n, matriz_rota, x, vetor_rota, &distancia); //funcao que compara a combinacao atual do
        // "vetor", calcula distancia e compara com o menor_rota, se for menor, ele entra no lugar dela.
        printf(" - distancia: %d\n", distancia);
    }
    else
    {
        for(int i = inf; i <= sup; i++)
        {
            troca(vetor, inf, i);
            permuta(vetor, inf + 1, sup, n, matriz_rota, x, menor_rota, vetor_rota);
            troca(vetor, inf, i); // backtracking
        }
    }
}

int matricula (char *m1, char *m2, char *m3, int n){
    int x1, x2, x3, final;
    x1 = (((m1[0] - '0')*1) + ((m1[1] - '0')*1) + ((m1[2] - '0')*1) + ((m1[3] - '0')*1));
    x2 = (((m2[0] - '0')*1) + ((m2[1] - '0')*1) + ((m2[2] - '0')*1) + ((m2[3] - '0')*1));
    x3 = (((m3[0] - '0')*1) + ((m3[1] - '0')*1) + ((m3[2] - '0')*1) + ((m3[3] - '0')*1));
    final = (x1 + x2 + x3) % n;
    return final;
}
