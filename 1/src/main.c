#include "recursividade.h"
#include <stdio.h>

int main() {
	printf("3 x 7 e igual a %d.\n", multiSoma(3, 7, 0));
	printf("5^5 e igual a %d.\n", elevado(5, 5, 1));
	printf("O fatorial de 11 e igual a %d.\n", fatorial(11, 1));

	return 0;
}