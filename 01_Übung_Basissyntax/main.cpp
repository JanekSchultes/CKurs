#pragma warning(disable: 4996)
#include <stdio.h>

const char* help_text = "Was wollen Sie tun?\n\
\t1 - Die Zahlen von 1 bis 10 ausgeben\n\
\t2 - Die Zahlen von 10 bis 1 ausgeben\n\
\t3 - Die Zahlen zwischen 2 beliebigen Zahlen ausgeben\n\
\t4 - Die Summe der Zahlen zwischen 2 beliebigen Zahlen ausgeben\n\
\t5 - Das Programm beenden\n";

int sumNumbers(int begin, int end) {
	int ret = 0;
	if (begin < end) {
		for (int i = begin; i <= end; ++i) ret += i;
	}
	else {
		for (int i = begin; i >= end; --i) ret += i;
	}
	return ret;
}

void printNumberSequence(int begin, int end) {
	if (begin < end) {
		for (int i = begin; i < end; ++i) {
			printf("%d, ", i);
		}
		printf("%d", end);
	}
	else if (end < begin) {
		for (int i = begin; i > end; i--) {
			printf("%d, ", i);
		}
		printf("%d", end);
	}
	printf("\nFertig.\n");
}



int readTwoNumbers(int* num1, int* num2) {
	printf("Geben Sie die erste Zahl ein.\n");
	int ret = scanf("%d", num1);
	if (ret != 1) {
		printf("Invalid input. Please insert a valid number\n");
		return -1;
	}

	printf("Geben Sie die zweite Zahl ein.\n");
	ret = scanf("%d", num2);
	if (ret != 1) {
		printf("Invalid input. Please insert a valid number\n");
		return -1;
	}
	return 0;
}

int main() {
	printf(help_text);
	while (true) {
		int choice = 0;
		int first_number = 0;
		int second_number = 0;
		int v = 0;

		printf("Ihre Eingabe: ");

		int ret = scanf("%d", &choice);
		if (ret != 1) {
			printf("Invalid input. Please insert a valid number\n");
			continue;
		}
		printf("\n");

		switch (choice) {
		case 1:
			printNumberSequence(1, 10);
			break;
		case 2:
			printNumberSequence(10, 1);
			break;
		case 3:
			first_number = 0;
			second_number = 0;
			v = readTwoNumbers(&first_number, &second_number);
			if (v == -1) break;
			printNumberSequence(first_number, second_number);
			break;
		case 4:
			first_number = 0;
			second_number = 0;
			v = readTwoNumbers(&first_number, &second_number);
			if (v == -1) break;
			printf("Die Summe lautet: %d\n", sumNumbers(first_number, second_number));
			break;
		case 5:
			printf("Auf Wiedersehen\n");
			return 0;
		default:
			printf("Not a valid selection. Please choose a number between 1 and 5\n");
			break;
		}
	}
}