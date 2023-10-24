#pragma warning(disable: 4996)
#include <stdio.h>

int main() {
	printf("Anzahl der Bytes einer Int-Variablen: %d\n", (int)sizeof(short));

	int signedNumber = 0;
	unsigned int unsignedNumber = 0;

	int numbers[100000000];
	int numbers1[100000000];
	int numbers2[100000000];
	int numbers3[100000000];
	printf("Element 1: %d\n", numbers[1]);

	scanf("%d", &numbers[0]);

	printf("%d\n", numbers[1]);

	return 0;
}