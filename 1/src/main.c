#include "recursividade.h"
#include <stdio.h>

int main() {
	printf("3 x 7 e igual a %d.\n", multiSoma(3, 7, 0));
	printf("5^5 e igual a %d.\n", elevado(5, 5, 1));
	printf("O fatorial de 11 e igual a %d.\n", fatorial(11, 1));
	
	printf("Os numeros pares de 0 a 31 sao: ");
	pares(31, 0);
    
    char* frase = "Sabendo disso ele foi logo correndo para o aeroporto";
    printf("A letra 'e' aparece %d vezes na frase \"%s\".\n", procurar(frase, 'e', 0, 0), frase); 

    int vec[] = {10, 5, 3, 7, 9, 1, 2, 6, 4, 8, 0};
    printf("A índice do número 4 na lista [10,5,3,7,9,1,2,6,4,8,0] é %d.\n", acharIndice(vec, 11, 4, 0));  

	return 0;
}
