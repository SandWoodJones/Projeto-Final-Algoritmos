#include "projetofinal.h"

void printar_sala(int N, int M, char sala[N][M]) {
    // muro de cima
    for (int i = 0; i < M + 2; i++) { printf("%c", MURO); }
    printf("\n");
    
    for (int linha = 0; linha < N; linha++) {
        printf("%c", MURO); // muro da esquerda
        for (int coluna = 0; coluna < M; coluna++) {
            printf("%c", sala[linha][coluna]); // objetos
        }
        printf("%c\n", MURO); // muro da direita
    }
    // muro de baixo
    for (int i = 0; i < M + 2; i++) { printf("%c", MURO); }
    printf("\n");
}
