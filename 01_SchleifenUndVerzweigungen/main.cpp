#pragma warning(disable: 4996)
#include <stdio.h>

void printValues(int start, int step, int max) {
	for	(int i = start; i <= max; i += step) {
		printf("%d.", i);
	}
	printf("\nFertig.\n");
}

int main() {
	int selection = 0;
	printf("Was wollen Sie tun?\n\t1 - alle geraden Zahlen zwischen 1 und 10 ausgeben\n\t2 - alle ungeraden Zahlen zwischen 1 und 10 ausgeben\n\t3 - das Programm beenden\n");

	while (true) {
		printf("Ihre Eingabe: ");
		int ret = scanf("%d", &selection);
		if (ret != 1) {
			printf("An error occurred. Please provide valid input");
			continue;
		}
		switch (selection) {
		case 1:
			printf("Alle geraden Zahlen zwischen 1 und 10\n");
			printValues(2, 2, 10);
			break;
		case 2:
			printf("Alle ungeraden Zahlen zwischen 1 und 10\n");
			printValues(1, 2, 10);
			break;
		case 3:
			printf("Tschüss");
			return 0;
		default:
			continue;
		}
	}
	return 0;
}	