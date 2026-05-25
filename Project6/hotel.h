#ifndef HOTEL_H
#define HOTEL_H

#include "soba.h"

#define MAX_BROJ_SOBA 50
#define DATOTEKA_SOBA "sobe.txt"

typedef struct {
    Soba sobe[MAX_BROJ_SOBA];
    int brojSoba;
} Hotel;

void inicijalizirajHotel(Hotel* hotel);

void prikaziNaslov(void);
void glavniIzbornik(Hotel* hotel);
void upravljanjeSobama(Hotel* hotel);
void upravljanjeTipovima(void);

void dodajSobu(Hotel* hotel);
void prikaziSobe(const Hotel* hotel);
void urediSobu(Hotel* hotel);
void obrisiSobu(Hotel* hotel);

void sortirajSobePoBroju(Hotel* hotel);
void pretraziSobuPoBroju(Hotel* hotel);

void spremiSobeUDatoteku(const Hotel* hotel);
void ucitajSobeIzDatoteke(Hotel* hotel);

#endif
