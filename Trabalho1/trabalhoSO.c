#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int jogador_vez;
int vitoria = 0;
int empate = 0;
int tamanho;


void *vencedor_horizontal(void *arg_tabuleiro) {
    int **tabuleiro = (int **)arg_tabuleiro;
    for (int linha = 0; linha < tamanho; linha++) {
        int index_vencer = 0;
        for (int coluna = 0; coluna < tamanho; coluna++) {
            if (((tabuleiro[linha][coluna] == tabuleiro[linha][coluna+1])
            && (tabuleiro[linha][coluna] == jogador_vez))
            || (tabuleiro[linha][coluna] == tabuleiro[linha][coluna-1])
            && (tabuleiro[linha][coluna] == jogador_vez)){
                index_vencer++;
            }
            else {
            index_vencer = index_vencer;
            }

        }
        if (index_vencer >= tamanho/2) {
            printf("\nJogador %d é o vencedor!\n", jogador_vez);
            vitoria = 1;
        }
    }
    return NULL;
}

void *vencedor_vertical(void *arg_tabuleiro) {
    int **tabuleiro = (int **)arg_tabuleiro;
    for (int linha = 0; linha < tamanho; linha++) {
        int index_vencer = 0;
        for (int coluna = 0; coluna < tamanho; coluna++) {
            if (tabuleiro[coluna][linha] == jogador_vez) {
                index_vencer++;
            }
        }
        if (index_vencer >= tamanho/2) {
            printf("\nJogador %d é o vencedor!!\n", jogador_vez);
            vitoria = 1;
        }
    }
    return NULL;
}

void *test_venceu_diagonal(void *arg_tabuleiro) {
    int **tabuleiro = (int **)arg_tabuleiro;
    for (int i = 0; i < tamanho; i++) {
        int index_vencer = 0;
        for (int j = 0; j < tamanho; j++) {
            if (tabuleiro[i][j] == jogador_vez) {
                index_vencer++;
            }
        }
        if (index_vencer >= tamanho/2) {
            printf("\nJogador %d é o vencedor!\n", jogador_vez);
            vitoria = 1;
        }
    }
    return NULL;
}


int main() {

    int numero_pecas;
    printf("Digite o numero de peças para ganhar o jogo: \n");
    scanf("%d", &numero_pecas);
    tamanho = numero_pecas*2;

    //cria uma matriz com largura = tamanho e altura = tamanho
    int **tabuleiro = (int **)malloc(tamanho * sizeof(int *));
    for (int i=0; i<tamanho; i++)
         tabuleiro[i] = (int *)malloc(tamanho * sizeof(int));

    //preenche o tabuleiro com 0
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    }


    //imprime o tabuleiro
    printf("\n  |");
    for (int i = 0; i < tamanho; i++) {
        printf("%d  ", i);
    }
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("---");
    }
    printf("-\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d |", i);
        for (int j = 0; j < tamanho; j++) {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    //terminou de imprimir


    //gera aleatoriamente um primeiro jogador
    srand(time(NULL));
    jogador_vez = (rand() % 2) + 1;

    //fica num loop até ou alguem ganhar ou empatar
    while(vitoria == 0 && empate == 0) {

        printf("\nVez do jogador %d\n\n", jogador_vez);

        //usuário joga
        int sucesso = 0;
        do {
            printf("Digite a linha e a coluna:\n");
            int linha, coluna;
            scanf("%d %d", &linha, &coluna);
	    //checa se os valores inseridos estão dentro do tabuleiro e também se é uma casa vazia
            if ((linha < tamanho && coluna < tamanho) && tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = jogador_vez;
                sucesso = 1;
            } else {
                printf("Digite coordenadas válidas\n");
            }
        } while (sucesso == 0);


        //imprime o tabuleiro
        printf("\n  |");
        for (int i = 0; i < tamanho; i++) {
            printf("%d  ", i);
        }
        printf("\n");
        for (int i = 0; i < tamanho; i++) {
            printf("---");
        }
        printf("-\n");
        for (int i = 0; i < tamanho; i++) {
            printf("%d |", i);
            for (int j = 0; j < tamanho; j++) {
                printf("%d  ", tabuleiro[i][j]);
            }
            printf("\n");
        }
        //terminou de imprimir


        //identificadores das threads
        pthread_t checa_horiz;
        pthread_t checa_vertical;
        pthread_t checa_diagonal;

        //criação de threads
        pthread_create(&checa_horiz, NULL, vencedor_horizontal, tabuleiro);
        pthread_create(&checa_vertical, NULL, vencedor_vertical, tabuleiro);
        pthread_create(&checa_diagonal, NULL, test_venceu_diagonal, tabuleiro);

        //join das threads
        pthread_join(checa_horiz, NULL);
        pthread_join(checa_vertical, NULL);
        pthread_join(checa_diagonal, NULL);

        //avança pro próximo jogador
        jogador_vez = (jogador_vez % 2) + 1;
    }


    return 0;
}
