///Autores:
/// Pablo Miranda Batista          3482
///Lucas Ranieri Oliveira Martins  3479
///João Victor Magalhães Souza     3483

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <time.h>

int main() {
    clock_t inicio, fim;
    double tempo_exe;
    int n, x, menor_rota = 99999999, aux_while, i, j;
    char m1[10], m2[10], m3[10], arquivo[50];

    printf("======================================\n"
           "MODO INTERATIVO => 1\n"
           "MODO POR ARQUIVO => 2\n"
           "ENCERRAR PROGRAMA => 0\n"
           "======================================\n");
    printf("Digite a operacao desejada: ");
    scanf("%d", &aux_while);

    while (aux_while != 0) {

        if (aux_while == 1) {

            printf("Quantidade de cidades: ");
            scanf("%d", &n); //numero de cidades

            //cidade de partida
            printf("Digite a 1 matricula: ");
            scanf("%s", m1);
            printf("Digite a 2 matricula: ");
            scanf("%s", m2);
            printf("Digite a 3 matricula: ");
            scanf("%s", m3);
            x = matricula(m1, m2, m3, n);
            n = n - 1;

            printf("\n\n======================================\n"
                   "MATRICULA 1 => %s\n"
                   "MATRICULA 2 => %s\n"
                   "MATRICULA 3 => %s\n"
                   "======================================\n", m1, m2, m3);

            printf("======================================\n"
                   "QUANTIDADE DE CIDADES => %d\n"
                   "======================================\n"
                   "======================================\n"
                   "CIDADE INICIAL => %d\n"
                   "======================================\n", n+1, x);

            inicio = clock();

            int v[n], matriz_rota[n + 1][n + 1], vetor_rota[n];
            preenche_vetor(v, n, x); //entra 5--> 0,1,2,3,4 entra no vetor, para ser permutado

            // preenchendo a matriz de rotas
            srand(time(NULL));
            for (i = 0; i < (n + 1); i++) {
                for (j = 0; j < (n + 1); j++) {
                    if (i != j) {
                        matriz_rota[i][j] = rand() % 100;

                    } else {
                        matriz_rota[i][j] = 0;
                    }
                }
            }

            //arranjando as combinacoes
            int tam_v = sizeof(v) / sizeof(int);
            printf("======================================\n");
            permuta(v, 0, tam_v - 1, n, matriz_rota, x, &menor_rota, vetor_rota); //4 ultimos parametros foram p/ calculo da distancia
            printf("======================================\n");

            printf("======================================\n"
                   "MATRIZ DISTANCIA\n");
            for (i = 0; i < n + 1; i++) {
                for (j = 0; j < n + 1; j++) {
                    if (j == 0 & i != 0) {
                        printf("|");
                        printf("\n");
                    }
                    if (matriz_rota[i][j] < 10) {
                        printf("| 0%d ", matriz_rota[i][j]);
                    } else {
                        printf("| %d ", matriz_rota[i][j]);
                    }
                }
            }
            printf("|");
            printf("\n======================================\n");

            printf("======================================\n");
            printf("Menor rota => %d\n", menor_rota);
            printf("======================================\n");
            //fim do arranjo de combinacoes

            //mostrar arranjo com menor rota
            printf("======================================\n"
                   "Combinacao da menor rota => ");
            for (i = 0; i < n; i++) {
                if (i == 0)
                    printf("%d ", x);
                printf("%d ", vetor_rota[i]);
                if (i == n - 1)
                    printf("%d ", x);
            }
            printf("\n======================================\n");
            fim = clock();
            tempo_exe = ((double) (fim - inicio) / (((double) CLOCKS_PER_SEC)));
            printf("======================================\n"
                   "Tempo de Execucao => %.3lf s.\n"
                   "======================================\n\n", tempo_exe);

        }
        if (aux_while == 2){

            FILE *ptr_arq;

            printf("Digite o nome do arquivo (com a extencao): ");
            scanf("%s", arquivo);

            ptr_arq = fopen(arquivo, "r");

            if ((ptr_arq = fopen(arquivo, "r")) == NULL){
                printf("Erro na abertura do arquivo\n");
            }
            else{
                printf("Arquivo aberto com sucesso\n");
            }

            //cidade de partida
            fscanf(ptr_arq, "%s", m1);
            fscanf(ptr_arq, "%s", m2);
            fscanf(ptr_arq, "%s", m3);
            fscanf(ptr_arq, "%d", &n); //numero de cidades
            x = matricula(m1, m2, m3, n);
            n = n - 1;

            printf("\n\n======================================\n"
                   "MATRICULA 1 => %s\n"
                   "MATRICULA 2 => %s\n"
                   "MATRICULA 3 => %s\n"
                   "======================================\n", m1, m2, m3);

            printf("======================================\n"
                   "QUANTIDADE DE CIDADES => %d\n"
                   "======================================\n"
                   "======================================\n"
                   "CIDADE INICIAL => %d\n"
                   "======================================\n", n+1, x);

            inicio = clock();

            int v[n], matriz_rota[n + 1][n + 1], vetor_rota[n];
            preenche_vetor(v, n, x); //entra 5--> 0,1,2,3,4 entra no vetor, para ser permutado

            // preencher matriz de rotas


            srand(time(NULL));
            for (i = 0; i < (n + 1); i++) {
                for (j = 0; j < (n + 1); j++) {
                    if (i != j) {
                        fscanf(ptr_arq, "%d", &matriz_rota[i][j]);

                    } else {
                        matriz_rota[i][j] = 0;
                    }
                }
            }

            //arranjando as combinacoes
            int tam_v = sizeof(v) / sizeof(int);
            printf("======================================\n");
            permuta(v, 0, tam_v - 1, n, matriz_rota, x, &menor_rota,
                    vetor_rota); //4 ultimos parametros foram p/ calculo da distancia
            printf("======================================\n");

            printf("======================================\n"
                   "MATRIZ DISTANCIA\n");
            for (i = 0; i < n + 1; i++) {
                for (j = 0; j < n + 1; j++) {
                    if (j == 0 & i != 0) {
                        printf("|");
                        printf("\n");
                    }
                    if (matriz_rota[i][j] < 10) {
                        printf("| 0%d ", matriz_rota[i][j]);
                    } else {
                        printf("| %d ", matriz_rota[i][j]);
                    }
                }
            }
            printf("|");
            printf("\n======================================\n");

            printf("======================================\n");
            printf("Menor rota => %d\n", menor_rota);
            printf("======================================\n");
            //fim do arranjo de combinacoes

            //mostrar arranjo com menor rota
            printf("======================================\n"
                   "Combinacao da menor rota => ");
            for (i = 0; i < n; i++) {
                if (i == 0)
                    printf("%d ", x);
                printf("%d ", vetor_rota[i]);
                if (i == n - 1)
                    printf("%d ", x);
            }
            printf("\n======================================\n");
            fim = clock();
            tempo_exe = ((double) (fim - inicio) / ((double) CLOCKS_PER_SEC));
            printf("======================================\n"
                   "Tempo de Execucao => %.3lf s.\n"
                   "======================================\n\n", tempo_exe);

        }

        printf("======================================\n"
               "MODO INTERATIVO => 1\n"
               "MODO POR ARQUIVO => 2\n"
               "ENCERRAR PROGRAMA => 0\n"
               "======================================\n");
        printf("Digite a operacao desejada: ");
        scanf("%d", &aux_while);
    }
    system("pause");
    return 0;
}