#ifndef _FLIGHT_H_
#define _FLIGHT_H_

#define LENGTH 20
#include "plane.h"

typedef struct
{
  int flightNum;
  char origin[LENGTH];
  char destination[LENGTH];
  Plane *plane;
} Flight;

Flight * openFlight(int numFlights);
Flight * readFlight(int numFlights, Flight* flights, FILE* fp);
int menuFlights(int numFlights, Flight* flights);
int userFlightNumber(int numFlights, Flight* flights);
void printFlightMenu(int numFlights, Flight* flights);
void printToFile(int numFlights, Flight* flights);
void freeFlight(int numFlights, Flight* flights);
void menuHelper(Flight* flights, int n);
//char* stringAlloc(int uRow, char uSeat, char* passName);

#endif
 
