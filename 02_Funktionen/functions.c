#pragma warning(disable: 4996)

#include <stdio.h>

const char* info_text = "Was wollen Sie tun?\n\
\t1 - Addieren von 2 Zahlen\n\
\t2 - Teilen von 2 Zahlen\n\
\t3 - Das Programm beenden\n";

int readTwoNumbersF(float* num1, float* num2) {
	printf("Geben Sie die erste Zahl ein.\n");
	int ret = scanf("%f", num1);
	if (ret != 1) {
		printf("Invalid input. Please insert a valid number\n");
		return -1;
	}

	printf("Geben Sie die zweite Zahl ein.\n");
	ret = scanf("%f", num2);
	if (ret != 1) {
		printf("Invalid input. Please insert a valid number\n");
		return -1;
	}
	return 0;
}

float divideF(float num, float divisor) {
	return num / divisor;
}

float addF(float num1, float num2) {
	return num1 + num2;
}

int main() {
	int choice = 0;
	float number1, number2 = 0;

	printf(info_text);
	int ret = scanf("%d", &choice);
	if (ret != 1) {
		printf("No valid input was provided\n");
		return;
	}

	switch (choice) {
	case 1:
		readTwoNumbersF(&number1, &number2);
		printf("The sum is %f\n", addF(number1, number2));
		break;
	case 2:
		printf("The first number is the divident, the second the devisor\n");
		readTwoNumbersF(&number1, &number2);
		printf("The result is: %f\n", divideF(number1, number2));
		break;
	case 3:
		break;
	default:
		printf("Please provide valid input");
		return;
	}
}