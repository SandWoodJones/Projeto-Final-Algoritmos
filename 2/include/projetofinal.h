#ifndef PROJETOFINAL
#define PROJETOFINAL

#include <stdio.h>
#include <stdbool.h>

#define MURO '+'
#define CHAO '.'
#define SAIDA 'S'
#define ENTRADA 'E'
#define PAREDE 'P'

void printar_sala(int N, int M, char sala[N][M]);

void resolver_labirinto(int N, int M, char sala[N][M]);

#endif
