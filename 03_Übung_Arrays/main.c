#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

const char* info_text = "\n\nWas wollen Sie tun?\n\
\t1 - neue Noten eingeben\n\
\t2 - alle Noten ausgeben\n\
\t3 - die beste Note ausgeben\n\
\t4 - den Notendurchschnitt ausgeben\n\
\t5 - Programm beenden\n\n\n";

struct NotenListe {
	int* noten;
	int size;
};

struct NotenListe create_noten_liste() {
	struct NotenListe ret;
	ret.noten = malloc(1);
	ret.size = 0;
	return ret;
}

void insert_new_note(struct NotenListe* list, int note) {
	++list->size;
	list->noten = realloc(list->noten, list->size * sizeof(int));
	list->noten[list->size - 1] = note;
}

void print_notes(struct NotenListe list) {
	if (list.size == 0) {
		printf("Es sind noch keine Noten vorhanden!\n");
		return;
	}
	printf("Deine Noten sind: ");
	for	(int i = 0; i < list.size - 1; ++i) {
		printf("%d, ", list.noten[i]);
	}
	printf("%d\n", list.noten[list.size - 1]);
}

int find_greatest(struct NotenListe list) {
	if (list.size == 0) {
		printf("Es sind noch keine Noten vorhanden!\n");
		return -1;
	}

	int best = 0;
	for (int i = 0; i < list.size; ++i) {
		if (list.noten[i] > best) best = list.noten[i];
	}
	return best;
}

float calculate_average(struct NotenListe list) {
	if (list.size == 0) {
		printf("Es sind noch keine Noten vorhanden!\n");
		return -1.0f;
	}

	int sum = 0;
	for (int i = 0; i < list.size; ++i) {
		sum += list.noten[i];
	}
	return (float)sum / (float)list.size;
}

void delete_noten_liste(struct NotenListe* list) {
	free(list->noten);
	list->size = 0;
}


int main() {
	struct NotenListe noten_liste = create_noten_liste();

	int stop = 0;

	do {
		int eingabe = 0;
		int note = 0;
		float average = 0.0f;
			
		printf(info_text);
		printf("Ihre Eingabe: ");
		int ret = scanf("%d", &eingabe);
		if (ret != 1)continue;

		switch (eingabe) {
		case 1:
			while (1) {
				printf("Bitte geben Sie ihre Note in Punkten ein oder 20 zum Abbrechen: ");
				note = 0;
				ret = scanf("%d", &note);
				if (ret != 1)continue;
				if (note >= 0 && note <= 15) {
					insert_new_note(&noten_liste, note);
				}
				else if (note == 20) {
					printf("\n alle Noten eingegeben.\n");
					break;
				}
				else {
					printf("\n keine valide Eingabe.\n");
				}
			}
			break;
		case 2:
			print_notes(noten_liste);
			break;
		case 3:	
			note = find_greatest(noten_liste);
			if(note >= 0) printf("Deine beste Note ist: %d\n", note);
			break;
		case 4:
			average = calculate_average(noten_liste);
			if(note >= 0.0f) printf("Dein Notendurchschnitt ist: %f\n", average);
			break;
		case 5:
			stop = 1;
			break;
		default:
			printf("Please provide valid input!\n");
		}
	} while (!stop);

	delete_noten_liste(&noten_liste);
	return 0;
}