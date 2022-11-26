#include "projetofinal.h"

int main() {
	int N, M; // largura e comprimento
	scanf("%d%d", &N, &M);
    
    char sala[N][M];
    for (int linha = 0; linha < N; linha++) {
        for (int coluna = 0; coluna < M; coluna++) {
            sala[linha][coluna] = CHAO;
        }
    }

    int Xe, Ye;
    scanf("%d%d", &Xe, &Ye);
    sala[Xe - 1][Ye - 1] = ENTRADA;

    int Xs, Ys;
    scanf("%d%d", &Xs, &Ys);
    sala[Xs - 1][Ys - 1] = SAIDA;
    
    int Xp, Yp;
    while (Xp != -1 && Yp != -1) {
        scanf("%d%d", &Xp, &Yp);
        sala[Xp - 1][Yp - 1] = PAREDE;
    }

    resolver_labirinto(N, M, sala);
    
    return 0;
}
