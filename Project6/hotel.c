#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "hotel.h"

void inicijalizirajHotel(Hotel* hotel) {
	if (hotel == NULL) {
		return;
	}

	hotel->brojSoba = 0;
}

void prikaziNaslov(void) {
	printf("=========================================\n");
	printf("      SUSTAV ZA UPRAVLJANJE HOTELOM\n");
	printf("=========================================\n\n");
}

void glavniIzbornik(Hotel* hotel) {
	int odabir = 0;

	do {
		printf("Glavni izbornik:\n");
		printf("1. Upravljanje sobama\n");
		printf("2. Upravljanje tipovima soba\n");
		printf("3. Izlaz iz programa\n");
		printf("Odabir: ");

		scanf("%d", &odabir);

		switch (odabir) {
		case 1:
			upravljanjeSobama(hotel);
			break;

		case 2:
			upravljanjeTipovima();
			break;

		case 3:
			printf("\nIzlaz iz programa.\n");
			break;

		default:
			printf("\nNeispravan odabir.\n\n");
			break;
		}

	} while (odabir != 3);
}

void upravljanjeSobama(Hotel* hotel) {
	int odabir = 0;

	do {
		printf("\n--- Upravljanje sobama ---\n");
		printf("1. Dodaj sobu\n");
		printf("2. Prikazi sobe\n");
		printf("3. Povratak\n");
		printf("Odabir: ");

		scanf("%d", &odabir);

		switch (odabir) {
		case 1:
			dodajSobu(hotel);
			break;

		case 2:
			prikaziSobe(hotel);
			break;

		case 3:
			printf("\nPovratak na glavni izbornik.\n\n");
			break;

		default:
			printf("\nNeispravan odabir.\n");
			break;
		}

	} while (odabir != 3);
}

void upravljanjeTipovima(void) {
	printf("\n--- Upravljanje tipovima soba ---\n");
	printf("Ovaj dio programa jos nije implementiran.\n\n");
}

void dodajSobu(Hotel* hotel) {
	Soba novaSoba;

	if (hotel == NULL) {
		return;
	}

	if (hotel->brojSoba >= MAX_BROJ_SOBA) {
		printf("\nDosegnut je maksimalan broj soba.\n");
		return;
	}

	printf("\n--- Dodavanje sobe ---\n");

	printf("Broj sobe: ");
	scanf("%d", &novaSoba.brojSobe);

	printf("Kat: ");
	scanf("%d", &novaSoba.kat);

	printf("Kapacitet: ");
	scanf("%d", &novaSoba.kapacitet);

	novaSoba.status = SLOBODNA;

	novaSoba.tip.id = 0;
	strcpy(novaSoba.tip.naziv, "Nije dodijeljen");
	strcpy(novaSoba.tip.opis, "Tip sobe jos nije definiran");
	novaSoba.tip.cijenaPoNoci = 0.0;

	hotel->sobe[hotel->brojSoba] = novaSoba;
	hotel->brojSoba++;

	printf("\nSoba je uspjesno dodana.\n\n");
}

void prikaziSobe(const Hotel* hotel) {
	int i;

	if (hotel == NULL) {
		return;
	}

	if (hotel->brojSoba == 0) {
		printf("\nNema evidentiranih soba.\n\n");
		return;
	}

	printf("\n--- Popis soba ---\n");

	for (i = 0; i < hotel->brojSoba; i++) {
		printf("\nSoba %d\n", i + 1);
		printf("Broj sobe: %d\n", hotel->sobe[i].brojSobe);
		printf("Kat: %d\n", hotel->sobe[i].kat);
		printf("Kapacitet: %d\n", hotel->sobe[i].kapacitet);
		printf("Status: %s\n", statusUTekst(hotel->sobe[i].status));
		printf("Tip sobe: %s\n", hotel->sobe[i].tip.naziv);
	}

	printf("\n");
}

const char* statusUTekst(StatusSobe status) {
	switch (status) {
	case SLOBODNA:
		return "Slobodna";

	case ZAUZETA:
		return "Zauzeta";

	case CISCENJE:
		return "Ciscenje";

	case ODRZAVANJE:
		return "Odrzavanje";

	default:
		return "Nepoznato";
	}
}