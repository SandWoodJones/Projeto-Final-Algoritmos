#include "recursividade.h"

int multiSoma(int a, int b, int res) {
	if (b == 0) return res;
	res = res + a;
	return multiSoma(a, b - 1, res);
}

int elevado(int a, int b, int res) {
	if (b == 0) return res;
	res = res * a;
	return elevado(a, b - 1, res);
}

int fatorial(int n, int res) {
	if (n == 0) return res;
	res = res * n;
	fatorial(n - 1, res);
}
