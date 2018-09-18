#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <fstream>
#include "plane.h"

using namespace std;

static const int MAX_NAME = 30;

class Plane;

class Passenger
{
  friend class Plane;

private:
  short flightNum;
  short row;
  char seat;
  char name[MAX_NAME];
public:
  Passenger ();
  Passenger (short newFlightNum, short newRow, char newSeat, char* newName);
  static void copyPassengers();

} ;


#endif // PASSENGER_H
