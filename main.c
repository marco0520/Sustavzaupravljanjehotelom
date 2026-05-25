#define _CRT_SECURE_NO_WARNINGS

#include "hotel.h"

int main(void) {
    Hotel hotel;

    inicijalizirajHotel(&hotel);

    ucitajSobeIzDatoteke(&hotel);

    prikaziNaslov();
    glavniIzbornik(&hotel);

    spremiSobeUDatoteku(&hotel);

    return 0;
}
