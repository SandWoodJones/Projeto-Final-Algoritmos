#include "projetofinal.h"

typedef struct {
    int x;
    int y;
    int n;
} Coord;

// Usando o algoritmo encontrado em https://en.wikipedia.org/wiki/Pathfinding#Sample_algorithm
void resolver_labirinto(int N, int M, char sala[N][M]) {
    int Xs, Ys;
    // Precisamos achar as coordenadas da saída:
    for (int l = 0; l < N; l++) {
        for (int c = 0; c < M; c++) {
            if (sala[l][c] == SAIDA) {
                Xs = l + 1;
                Ys = c + 1;
            }
        }
    }

    // Primeiro criamos uma lista de coordenadas, cada uma com uma variável contadora anexada.
    // Esta lista tem o tamanho máximo de N*M e começa com uma única coordenada, a coordenada da saída:
    int tamanho = N*M;
    Coord lista[tamanho];
    lista[0] = (Coord){Xs, Ys, 0};
    int index = 1; // Variável indexadora da lista.
    
    bool entrada_encontrada = false;
    // Para cada elemento na lista
    for (int i = 0; i < tamanho; i++) {
        if (entrada_encontrada) break; // Se ja encontramos a entrada, saimos do loop.

        Coord elemento = lista[i];

        // Crie uma nova lista com as 4 células adjacentes ao elemento adicionado 1 ao contador:
        Coord adj[4] = {
            {elemento.x - 1, elemento.y, elemento.n + 1}, // Esquerda
            {elemento.x + 1, elemento.y, elemento.n + 1}, // Direita
            {elemento.x, elemento.y - 1, elemento.n + 1}, // Cima  
            {elemento.x, elemento.y + 1, elemento.n + 1} // Baixo  
        };

        // Checamos todas as celulas na lista das adjacentes:
        for (int j = 0; j < 4; j++) {
            Coord celula = adj[j];
            
            if (celula.x < 0 || celula.x > N) continue; // Não queremos células que estão fora do quarto pelos lados.
            if (celula.y < 0 || celula.y > M) continue; // Não queremos células que estão fora do quarto por cima ou por baixo.
            if (sala[celula.x][celula.y] == PAREDE) continue; // Não queremos paredes.

            // Não queremos células que ja estão na lista
            bool esta_na_lista = false;
            for (int k = 0; k < tamanho; k++) {
                if (lista[k].x == celula.x && lista[k].y == celula.y) esta_na_lista = true;
            }

            // Restaram apenas células válidas, logo adicionamos elas no fim da lista de coordenadas:
            if (!esta_na_lista) {
                lista[index] = celula;
                index++;
                if (sala[celula.x][celula.y] == ENTRADA) entrada_encontrada = true; // Encontramos a entrada.
            }
        }
    }

    // Temos agora a lista de todos os passos da saída até chegarmos a entrada. Agora, desses passos precisamos escolher o caminho mais curto:
    tamanho = lista[index - 1] + 1;
    Coord menorCaminho[tamanho];
    menorCaminho[0] = lista[index - 1];
    printf("menorCaminho[0]=%d %d %d\n", menorCaminho[0].x, menorCaminho[0].y, menorCaminho[0].n);

    for (int i = 0; i < index; i++) {
        printf("lista[%d]=%d %d %d\n", i, lista[i].x, lista[i].y, lista[i].n);
        //sala[lista[i].x][lista[i].y] = lista[i].n + '0';
    }
}
