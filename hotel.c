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
        printf("3. Spremi sobe u datoteku\n");
        printf("4. Izlaz iz programa\n");
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
            spremiSobeUDatoteku(hotel);
            break;

        case 4:
            printf("\nIzlaz iz programa.\n");
            break;

        default:
            printf("\nNeispravan odabir.\n\n");
            break;
        }

    } while (odabir != 4);
}

void upravljanjeSobama(Hotel* hotel) {
    int odabir = 0;

    do {
        printf("\n--- Upravljanje sobama ---\n");
        printf("1. Dodaj sobu\n");
        printf("2. Prikazi sobe\n");
        printf("3. Uredi sobu\n");
        printf("4. Obrisi sobu\n");
        printf("5. Sortiraj sobe po broju\n");
        printf("6. Pretrazi sobu po broju\n");
        printf("7. Povratak\n");
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
            urediSobu(hotel);
            break;

        case 4:
            obrisiSobu(hotel);
            break;

        case 5:
            sortirajSobePoBroju(hotel);
            break;

        case 6:
            pretraziSobuPoBroju(hotel);
            break;

        case 7:
            printf("\nPovratak na glavni izbornik.\n\n");
            break;

        default:
            printf("\nNeispravan odabir.\n");
            break;
        }

    } while (odabir != 7);
}

void upravljanjeTipovima(void) {
    printf("\n--- Upravljanje tipovima soba ---\n");
    printf("Ovaj dio programa je jos u irzadi.\n");
}

void spremiSobeUDatoteku(const Hotel* hotel) {
    FILE* datoteka;
    int i;

    if (hotel == NULL) {
        return;
    }

    datoteka = fopen(DATOTEKA_SOBA, "w");

    if (datoteka == NULL) {
        perror("\nGreska pri otvaranju datoteke za spremanje.\n\n");
        return;
    }

    fprintf(datoteka, "Broj evidentiranih soba: %d\n\n", hotel->brojSoba);

    for (i = 0; i < hotel->brojSoba; i++) {
        fprintf(datoteka, "Soba %d\n", i + 1);
        fprintf(datoteka, "Broj sobe: %d\n", hotel->sobe[i].brojSobe);
        fprintf(datoteka, "Kat: %d\n", hotel->sobe[i].kat);
        fprintf(datoteka, "Kapacitet: %d\n", hotel->sobe[i].kapacitet);
        fprintf(datoteka, "Status: %d\n", hotel->sobe[i].status);
        fprintf(datoteka, "------------------------------\n\n");
    }

    fclose(datoteka);

    printf("\nSobe su uspjesno spremljene u datoteku.\n\n");
}

void ucitajSobeIzDatoteke(Hotel* hotel) {
    FILE* datoteka;
    char redak[100];
    int brojSoba = 0;
    int i;

    if (hotel == NULL) {
        return;
    }

    datoteka = fopen(DATOTEKA_SOBA, "r");

    if (datoteka == NULL) {
        printf("Datoteka sa sobama jos ne postoji.\n");
        printf("Krece se s praznom evidencijom.\n\n");
        return;
    }

    if (fgets(redak, sizeof(redak), datoteka) != NULL) {
        sscanf(redak, "Broj evidentiranih soba: %d", &brojSoba);
    }

    if (brojSoba > MAX_BROJ_SOBA) {
        brojSoba = MAX_BROJ_SOBA;
    }

    hotel->brojSoba = 0;

    for (i = 0; i < brojSoba; i++) {
        Soba soba;
        int statusBroj = 1;

        while (fgets(redak, sizeof(redak), datoteka) != NULL) {
            if (strncmp(redak, "Soba", 4) == 0) {
                break;
            }
        }

        if (fgets(redak, sizeof(redak), datoteka) != NULL) {
            sscanf(redak, "Broj sobe: %d", &soba.brojSobe);
        }

        if (fgets(redak, sizeof(redak), datoteka) != NULL) {
            sscanf(redak, "Kat: %d", &soba.kat);
        }

        if (fgets(redak, sizeof(redak), datoteka) != NULL) {
            sscanf(redak, "Kapacitet: %d", &soba.kapacitet);
        }

        if (fgets(redak, sizeof(redak), datoteka) != NULL) {
            sscanf(redak, "Status: %d", &statusBroj);
        }

        soba.status = (StatusSobe)statusBroj;

        soba.tip.id = 0;
        strcpy(soba.tip.naziv, "Nije dodijeljen");
        strcpy(soba.tip.opis, "Tip sobe jos nije definiran");
        soba.tip.cijenaPoNoci = 0.0;

        hotel->sobe[hotel->brojSoba] = soba;
        hotel->brojSoba++;
    }

    fclose(datoteka);

    printf("Sobe su uspjesno ucitane iz datoteke.\n\n");
}
