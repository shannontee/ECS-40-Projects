#ifndef FLIGHTS_H
#define	FLIGHTS_H

#include "flight.h"

class Flights
{
  static const int INITIAL_SIZE = 2;
  static const int RESIZE_MULTIPLIER = 2;
  static const int TEN = 10;
  static const int NAME_LENGTH = 30;
  Flight **flights;
  int size;
  int capacity;
public:
  Flights();
  ~Flights();
  void addPassenger() const;
  Flights & operator++(); 
  void operator+=(Flight * flight); 
  int getSize() const;
 
  friend istream & operator>>(istream & in, Flights & f); 
  Flights & operator--(int); 
  void removePassenger() const;
  void findPassenger()const;
}; // class flights

istream & operator>>(istream & in, Flights & f); 

#endif	// FLIGHTS_H
