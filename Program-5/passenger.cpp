// Author: Sean Davis
#include <cstring>
#include <fstream>
#include "passenger.h"
using namespace std;


Passenger::Passenger()
{
} // Passenger()


Passenger::Passenger(short flightNu, short ro, char sea, const char nam[]) :
  flightNum(flightNu), row(ro), seat(sea)
{
  strcpy(name, nam);
}  // Passenger()


void Passenger::copyPassengers()
{
  Passenger passenger;

  ifstream inf("passengers.dat", ios::binary);
  ofstream outf("passengers2.dat", ios::binary);

  while(inf.read( (char*) &passenger, sizeof(Passenger)))
    outf.write((char*) &passenger, sizeof(Passenger));

  outf.close();
  inf.close();
}  // copyPassengers()

bool Passenger::operator==(const int i) const
{
  return flightNum == i;
} // operator ==

bool Passenger::operator==(const char * s) const
{
  return strcmp(name, s) == 0;
} //operator ==

void Passenger::operator!()
{
  flightNum = Passenger::CANCELLED;
} // operator !

ostream & operator<<(ostream &out, const Passenger & p)
{
  out << p.name;
  return out;
} // operator <<
