#ifndef SOBA_H
#define SOBA_H

#define MAX_NAZIV_TIPA 50
#define MAX_OPIS_TIPA 100

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

const char* statusUTekst(StatusSobe status);
int usporediSobePoBroju(const void* prva, const void* druga);

#endif
