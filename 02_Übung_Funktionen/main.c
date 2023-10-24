#pragma warning(disable: 4996)

#include <stdio.h>

#define EURO_TO_DOLLAR_COURSE 1.0609

const char* info_text = "Was wollen Sie tun?\n\
\t1 - Euro in Dollar umrechnen\n\
\t2 - Dollar in Euro umrechnen\n\
\t3 - Das Idealgewicht berechnen\n\
\t4 - Das Programm beenden\n";

const char* gender_text = "Bitte geben Sie ihr Geschlecht an\n\
\t1 - Mann\n\
\t2 - Frau\n";

enum Gender {
	MALE,
	FEMALE
};

float euroToDollar(float val) {
	if (val < 0) return(float)(val / EURO_TO_DOLLAR_COURSE);
	return (float)(val * EURO_TO_DOLLAR_COURSE);
}

float dollarToEuro(float val) {
	if (val < 0) return(float)(val * EURO_TO_DOLLAR_COURSE);
	return (float)(val / EURO_TO_DOLLAR_COURSE);
}

float idealWeight(int val, enum Gender gen) {
	float weight = 0.0f;
	switch (gen) {
	case MALE:
		weight = (float)val - 100.0f;
		break;
	case FEMALE:
		weight = 0.8f * ((float)val - 100.0f);
		break;
	}
	return weight;
}

int main() {
	printf(info_text);

	while (1) {
		int choice = 0;
		printf("Your input: ");
		int ret = scanf("%d", &choice);

		if (ret != 1) {
			printf("Please insert a valid integer.\n");
			continue;
		}

		switch (choice) {
			float val = 0.0f;
			int height = 0;
			int gen = 0;
		case 1:
			printf("Bitte geben Sie einen Euro-Wert an\n");
			ret = scanf("%f", &val);
			if (ret != 1) {
				printf("Bitte geben Sie eine gültige Kommazahl mit Punkt-Trennung ein.\n");
				break;
			}
			printf("%f Euro entsprechen %f Dollar\n", val, euroToDollar(val));
			break;
		case 2:
			printf("Bitte geben Sie einen Dollar-Wert an\n");
			ret = scanf("%f", &val);
			if (ret != 1) {
				printf("Bitte geben Sie eine gültige Kommazahl mit Punkt-Trennung ein.\n");
				break;
			}
			printf("%f Dollar entsprechen %f Euro\n", val, dollarToEuro(val));
			break;
		case 3:
			printf("Bitte geben Sie ihre Groesse in Zentimetern an.\n");
			ret = scanf("%d", &height);
			if (ret != 1) {
				printf("Bitte geben Sie eine gültige ganze Zahl a\n");
				break;
			}
			printf(gender_text);
			ret = scanf("%d", &gen);
			if (ret != 1) {
				printf("Bitte geben Sie eine gültige ganze Zahl a\n");
				break;
			}
			switch (gen) {
			case 1:
				printf("Das Idealgewicht ist: %f\n", idealWeight(height, MALE));
				break;
			case 2:
				printf("Das Idealgewicht ist: %f\n", idealWeight(height, FEMALE));
				break;
			default:
				break;
			}
			break;
		case 4:
			printf("Auf Wiedersehen\n");
			return 0;
		default:
			printf("Invalid input provided.\n");
			break;
		}
	}
}