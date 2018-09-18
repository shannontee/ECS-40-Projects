// Author: Sean Davis

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "flight.h"

using namespace std;

Flight & Flight::operator++(int)
{
  ++(*plane); 

  return *this;
}  // operator ++


Flight::~Flight()
{
  ofstream outf("flights2.csv", ios::app);
  outf << flightNum << ',' << origin << ',' << destination << ',';
  plane->writePlane(outf);
  outf.close();
  delete plane;
}  // freeFlight()

void Flight::addFlight()
{
  cout << "\nFlight number to add: ";
  cin >> flightNum;
  cin.ignore(TEN, '\n');
  cout << "Origin: ";
  cin.getline(origin, MAX_CITY_LENGTH);
  cout << "Destination: ";
  cin.getline(destination, MAX_CITY_LENGTH);
  plane = new Plane(flightNum);
  plane->addFlight();
}  // addFlight()

int Flight::getFlightNumber() const
{
  return flightNum;
}  // getFlightNumber()


ostream & operator<<(ostream &out, const Flight & f)
{
  out << left << setw(f.FLIGHT_NUM_SPACE) << f.flightNum << ' '
    << setw(f.MAX_CITY_LENGTH) << f.origin << ' '  << f.destination << endl;
  return out;
}  // operator <<


int Flight::findPassenger(const char *passName) const
{
  return plane->findPassenger(passName);
} // findPassenger()

istream & operator>>(istream &inf, Flight & f)
{
  inf >> f.flightNum;
  inf.ignore(f.TEN, ',');
  inf.getline(f.origin, f.MAX_CITY_LENGTH, ',');
  inf.getline(f.destination, f.MAX_CITY_LENGTH, ',');
 
  f.plane = new Plane(f.flightNum);
  inf >> *(f.plane);

  return inf;
}  // operator >>

void Flight::operator!()
{
  !(*plane);
}  // operator

Flight & Flight::operator--()
{
  (*plane)--;
  return *this;
}  // operator --
