#ifndef PASSENGER_H
#define	PASSENGER_H
#include <fstream>
#include "plane.h"

class Passenger
{
public:
  static const int NAME_LENGTH = 30;
  static const int CANCELLED = -1;
private:
  short flightNum;
  short row;
  char seat;
  char name[NAME_LENGTH];
public:
  Passenger();
  Passenger(short flightNu, short ro, char sea, const char nam[]);
  static void copyPassengers();

  bool operator==(const int i) const;
  bool operator==(const char * s) const;
  void operator!();
  friend ostream & operator<<(ostream &out, const Passenger & p);
  friend istream & operator>>(istream &inf, Plane & plane);
}; // class passengers

ostream & operator<<(ostream &out, const Passenger & p);

#endif	// PASSENGERS_H
