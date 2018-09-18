#ifndef FLIGHT_H
#define	FLIGHT_H

#include <iostream>
#include <fstream>
#include "plane.h"

using namespace std;

class Flight
{
  static const int MAX_CITY_LENGTH = 20;
  static const int TEN = 10;

  int flightNum;
  char origin[MAX_CITY_LENGTH];
  char destination[MAX_CITY_LENGTH];
  Plane *plane;
public:
  void addPassenger(int flightNum) const;
  ~Flight();
  int getFN() const;
  void printFlightInfo() const;
  void readFlight(ifstream &inf);
  void addFlight();
  void removePassenger() const;
  void removeFlight() const;

} ;
 



#endif	// FLIGHT_H

