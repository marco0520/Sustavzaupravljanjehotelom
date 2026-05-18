#define _CRT_SECURE_NO_WARNINGS

#include "hotel.h"

int main(void) {
	Hotel hotel;

	inicijalizirajHotel(&hotel);

	prikaziNaslov();
	glavniIzbornik(&hotel);

	return 0;
}