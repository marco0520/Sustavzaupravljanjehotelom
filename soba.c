#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"

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
                printf("\nNeispravan status. Status ostaje nepromijenjen.\n");
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

int usporediSobePoBroju(const void* prva, const void* druga) {
    const Soba* soba1 = (const Soba*)prva;
    const Soba* soba2 = (const Soba*)druga;

    if (soba1->brojSobe < soba2->brojSobe) {
        return -1;
    }

    if (soba1->brojSobe > soba2->brojSobe) {
        return 1;
    }

    return 0;
}

void sortirajSobePoBroju(Hotel* hotel) {
    if (hotel == NULL) {
        return;
    }

    if (hotel->brojSoba == 0) {
        printf("\nNema soba za sortiranje.\n\n");
        return;
    }

    qsort(hotel->sobe, hotel->brojSoba, sizeof(Soba), usporediSobePoBroju);

    printf("\nSobe su uspjesno sortirane po broju sobe.\n\n");
}

void pretraziSobuPoBroju(Hotel* hotel) {
    Soba trazenaSoba;
    Soba* pronadenaSoba;

    if (hotel == NULL) {
        return;
    }

    if (hotel->brojSoba == 0) {
        printf("\nNema soba za pretrazivanje.\n\n");
        return;
    }

    printf("\nUnesite broj sobe koju trazite: ");
    scanf("%d", &trazenaSoba.brojSobe);

    qsort(hotel->sobe, hotel->brojSoba, sizeof(Soba), usporediSobePoBroju);

    pronadenaSoba = (Soba*)bsearch(
        &trazenaSoba,
        hotel->sobe,
        hotel->brojSoba,
        sizeof(Soba),
        usporediSobePoBroju
    );

    if (pronadenaSoba == NULL) {
        printf("\nSoba s brojem %d nije pronadena.\n\n", trazenaSoba.brojSobe);
        return;
    }

    printf("\n--- Pronadena soba ---\n");
    printf("Broj sobe: %d\n", pronadenaSoba->brojSobe);
    printf("Kat: %d\n", pronadenaSoba->kat);
    printf("Kapacitet: %d\n", pronadenaSoba->kapacitet);
    printf("Status: %s\n", statusUTekst(pronadenaSoba->status));
    printf("Tip sobe: %s\n\n", pronadenaSoba->tip.naziv);
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
