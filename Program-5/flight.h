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
  static const int FLIGHT_NUM_SPACE = 4;
  int flightNum;
  char origin[MAX_CITY_LENGTH];
  char destination[MAX_CITY_LENGTH];
  Plane *plane;
public:
  Flight & operator++(int); // post inc. new addPassenger()
  ~Flight();
  void addFlight();
  int getFlightNumber() const;
  friend ostream & operator<<(ostream &in, const Flight & f);
  friend istream & operator>>(istream &in,  Flight & f);
  void operator!(); 
  Flight & operator--(); 
  int findPassenger(const char *passName) const;
} ;  // class Flight


ostream & operator<<(ostream &in, const Flight & f); // new printFlightInfo()
istream & operator>>(istream &in,  Flight & f); // new readFlight

#endif	// FLIGHT_H
