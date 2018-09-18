#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "flight.h"

using namespace std;

void Flight::addPassenger()
{
  if(!(plane->addPassenger()))
    cout << "We are sorry but Flight #" << flightNum << " is full.\n";
  
}  // addPassenger()


Flight::~Flight()
{
  delete plane; 
}  // deleteFlight()


int Flight::getFlightNumber()
{
  return flightNum;
}  // getFlightNumber()


void Flight::printFlightInfo()
{
  cout << left << setw(4) << flightNum << ' ' << setw(20) << origin
    << ' ' << destination << endl;
}  // printFlightInfo()


void Flight::readFlight(ifstream &inf)
{
  inf>>flightNum;
  inf.ignore();
  inf.getline(origin, MAX_CITY_LENGTH);
  inf.getline(destination, MAX_CITY_LENGTH);
  plane = new Plane(inf);
}  // readFlight()


void Flight::writeFlight(ofstream &outf) const
{
  outf << flightNum << endl << origin << endl << destination << endl; 
  plane->writePlane(outf);
}  // readFlight()
