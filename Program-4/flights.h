#ifndef FLIGHTS_H
#define	FLIGHTS_H

#include <iostream>
#include <fstream>
#include "flight.h"
#include "utilities.h"

using namespace std;

class Flights
{
 
  static const int START_SIZE = 2;
  static const int TEN_2 = 10;

  Flight **flightsArray;
  int capacity; //size of the array
  int size; //number of flights in the array
public:

  Flights();
 ~Flights();

  void insert(Flight*);
  void addPassenger() const;
  void readFlights();
  void readFlight(ifstream &inf);
  void addFlight();
  void removePassenger() const;
  void removeFlight();
} ;

#endif	// FLIGHTS_H

