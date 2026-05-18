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
        printf("5. Povratak\n");
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
            printf("\nPovratak na glavni izbornik.\n\n");
            break;

        default:
            printf("\nNeispravan odabir.\n");
            break;
        }

    } while (odabir != 5);
}

void upravljanjeTipovima(void) {
    printf("\n--- Upravljanje tipovima soba ---\n");
    printf("Ovaj dio programa jos nije implementiran.\n");
    
}

void dodajSobu(Hotel* hotel) {
    Soba novaSoba;
    int i;

    if (hotel == NULL) {
        return;
    }

    if (hotel->brojSoba >= MAX_BROJ_SOBA) {
        printf("\nDosegnut je maksimalan broj soba.\n\n");
        return;
    }

    printf("\n--- Dodavanje sobe ---\n");

    printf("Broj sobe: ");
    scanf("%d", &novaSoba.brojSobe);

    for (i = 0; i < hotel->brojSoba; i++) {
        if (hotel->sobe[i].brojSobe == novaSoba.brojSobe) {
            printf("\nSoba s tim brojem vec postoji.\n\n");
            return;
        }
    }

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

void urediSobu(Hotel* hotel) {
    int brojSobe;
    int i;
    int pronadena = 0;
    int noviStatus;

    if (hotel == NULL) {
        return;
    }

    if (hotel->brojSoba == 0) {
        printf("\nNema soba za uredjivanje.\n\n");
        return;
    }

    printf("\nUnesite broj sobe koju zelite urediti: ");
    scanf("%d", &brojSobe);

    for (i = 0; i < hotel->brojSoba; i++) {
        if (hotel->sobe[i].brojSobe == brojSobe) {
            pronadena = 1;

            printf("\n--- Uredjivanje sobe %d ---\n", brojSobe);

            printf("Novi kat: ");
            scanf("%d", &hotel->sobe[i].kat);

            printf("Novi kapacitet: ");
            scanf("%d", &hotel->sobe[i].kapacitet);

            printf("\nOdaberite novi status sobe:\n");
            printf("1. Slobodna\n");
            printf("2. Zauzeta\n");
            printf("3. Ciscenje\n");
            printf("4. Odrzavanje\n");
            printf("Odabir: ");

            scanf("%d", &noviStatus);

            if (noviStatus >= 1 && noviStatus <= 4) {
                hotel->sobe[i].status = (StatusSobe)noviStatus;
            }
            else {
                printf("\nNeispravan status! Status ostaje nepromijenjen.\n");
            }

            printf("\nSoba je uspjesno uredjena.\n\n");
            break;
        }
    }

    if (pronadena == 0) {
        printf("\nSoba s tim brojem nije pronadena.\n\n");
    }
}

void obrisiSobu(Hotel* hotel) {
    int brojSobe;
    int pronadena = 0;
    int i;
    int j;

    if (hotel == NULL) {
        return;
    }

    if (hotel->brojSoba == 0) {
        printf("\nNema soba za brisanje.\n\n");
        return;
    }

    printf("\nUnesite broj sobe za brisanje: ");
    scanf("%d", &brojSobe);

    for (i = 0; i < hotel->brojSoba; i++) {
        if (hotel->sobe[i].brojSobe == brojSobe) {
            pronadena = 1;

            for (j = i; j < hotel->brojSoba - 1; j++) {
                hotel->sobe[j] = hotel->sobe[j + 1];
            }

            hotel->brojSoba--;

            printf("\nSoba je uspjesno obrisana.\n\n");
            break;
        }
    }

    if (pronadena == 0) {
        printf("\nSoba s tim brojem nije pronadena.\n\n");
    }
}

void spremiSobeUDatoteku(const Hotel* hotel) {
    FILE* datoteka;
    int i;

    if (hotel == NULL) {
        return;
    }

    datoteka = fopen(DATOTEKA_SOBA, "w");

    if (datoteka == NULL) {
        printf("\nGreska pri otvaranju datoteke za spremanje.\n\n");
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