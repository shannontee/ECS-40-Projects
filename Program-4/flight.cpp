#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "flight.h"
#include "flights.h"
#include "plane.h"

using namespace std;

void Flight::addPassenger(const int flightNum) const
{
  if(!plane->addPassenger(flightNum))
    cout << "We are sorry but Flight #" << flightNum << " is full.\n";

}  // addPassenger()


Flight::~Flight()
{
  ofstream outf("flights2.csv", ios::app);
  outf << flightNum << ',' << origin << ',' << destination << ',';
  plane->writePlane(flightNum, outf); 
  delete plane;
  outf.close();

}  // freeFlight()


int Flight::getFN() const
{
  return flightNum;
}  // getFN()

void Flight::printFlightInfo() const
{
  cout << left << setw(4) << flightNum << ' ' << setw(20) 
    << origin << ' '  << destination << endl;
}  // printFlightInfo()


void Flight::readFlight(ifstream &inf)
{
  inf >> flightNum;
  inf.ignore ();
  inf.getline(origin, MAX_CITY_LENGTH, ',');
  inf.getline(destination, MAX_CITY_LENGTH, ',');
  plane = new Plane(flightNum, inf);
}  // readFlight()

void Flight::addFlight()
{
  cout << "\nFlight number to add: ";
  flightNum = getNumber();
  cout << "Origin: ";
  cin.getline (origin, MAX_CITY_LENGTH);
  cout << "Destination: ";
  cin.getline (destination, MAX_CITY_LENGTH);
  plane = new Plane();
  plane->addFlight();
} // addFlight()

void Flight::removePassenger() const
{
 cout << "Passengers on Flight #" << flightNum << endl;
 plane->removePassenger(); 

} // removePassenger()

void Flight::removeFlight() const
{
  plane->removeFlight();
} // removeFlight() 
