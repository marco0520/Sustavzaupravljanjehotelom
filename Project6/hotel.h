#ifndef HOTEL_H
#define HOTEL_H

#define MAX_NAZIV_TIPA 50
#define MAX_OPIS_TIPA 100
#define MAX_BROJ_SOBA 50

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

void inicijalizirajHotel(Hotel* hotel);
void prikaziNaslov(void);
void glavniIzbornik(Hotel* hotel);
void upravljanjeSobama(Hotel* hotel);
void upravljanjeTipovima(void);
void dodajSobu(Hotel* hotel);
void prikaziSobe(const Hotel* hotel);
const char* statusUTekst(StatusSobe status);

#endif