#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV_TIPA 50
#define MAX_OPIS_TIPA 100
#define MAX_BROJ_SOBA 100

typedef enum {
    SLOBODNA = 1,
    ZAUZETA,
    CISCENJE,
    ODRZAVANJE
} StatusSobe;

typedef struct {
    int id;
    char naziv[MAX_NAZIV_TIPA];
    char opis[MAX_OPIS_TIPA];
    double cijenaPoNoci;
} TipSobe;

typedef struct {
    int brojSobe;
    int kat;
    int kapacitet;
    StatusSobe status;
    TipSobe tip;
} Soba;

typedef struct {
    Soba sobe[MAX_BROJ_SOBA];
    int brojSoba;
} Hotel;

void prikaziNaslov(void);
void inicijalizirajHotel(Hotel* hotel);
void glavniIzbornik(Hotel* hotel);
void prikaziPocetniIzbornik(void);
void upravljanjeSobama(Hotel* hotel);
void upravljanjeTipovima(void);
const char* statusUTekst(StatusSobe status);

int main(void) {
    Hotel hotel;

    inicijalizirajHotel(&hotel);

    prikaziNaslov();
    glavniIzbornik(&hotel);

    return 0;
}

void prikaziNaslov(void) {
    printf("=========================================\n");
    printf("      SUSTAV ZA UPRAVLJANJE HOTELOM\n");
    printf("=========================================\n\n");
}

void inicijalizirajHotel(Hotel* hotel) {
    if (hotel == NULL) {
        return;
    }

    hotel->brojSoba = 0;
}

void prikaziPocetniIzbornik(void) {
    printf("Glavni izbornik:\n");
    printf("1. Upravljanje sobama\n");
    printf("2. Upravljanje tipovima soba\n");
    printf("3. Izlaz iz programa\n");
    printf("Odabir: ");
}

void glavniIzbornik(Hotel* hotel) {
    int odabir = 0;

    do {
        prikaziPocetniIzbornik();
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
            printf("\nNeispravan odabir. Pokusajte ponovno.\n\n");
            break;
        }

    } while (odabir != 3);
}

void upravljanjeSobama(Hotel* hotel) {
    if (hotel == NULL) {
        return;
    }

    printf("\n--- Upravljanje sobama ---\n");
    printf("Ovaj dio programa ce sluziti za dodavanje,\n");
    printf("pregled i azuriranje hotelskih soba.\n\n");
}

void upravljanjeTipovima(void) {
    printf("\n--- Upravljanje tipovima soba ---\n");
    printf("Ovaj dio programa ce sluziti za definiranje\n");
    printf("tipova soba i njihovih osnovnih cijena.\n\n");
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