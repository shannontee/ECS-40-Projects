#ifndef FLIGHT_H
#define	FLIGHT_H

#include <fstream>
#include "plane.h"

using namespace std;

#define MAX_CITY_LENGTH 20

class Flight
{
  int flightNum;
  char origin[MAX_CITY_LENGTH];
  char destination[MAX_CITY_LENGTH];
  Plane *plane;

  public:
    void addPassenger();
    ~Flight();
    int getFlightNumber();
    void printFlightInfo();
    void readFlight(ifstream &inf);
    void writeFlight(ofstream &outf) const;

}; // class Flight
 
#endif	// FLIGHT_H

