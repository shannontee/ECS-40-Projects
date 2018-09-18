#include <iostream>
#include <fstream>
#include <cstring>
#include "passenger.h"

using namespace std;

void Passenger::copyPassengers()
{
  Passenger passenger;
  ifstream inf ("passengers.dat", ios::binary | ios::in);
  ofstream outf ("passengers2.dat", ios::binary | ios::out);

  while(inf.read((char*)&passenger, sizeof(Passenger)))
  {  
    outf.write((char*)&passenger, sizeof(Passenger));
  } // while loop
 
  inf.close();
  outf.close();

} // copyPassengers()

Passenger::Passenger ()
{  
} // default

Passenger::Passenger(short newFliNum, short newRow, char newSeat, char* newName)
{
  flightNum = newFliNum;
  row = newRow;
  seat = newSeat;
  strcpy (name, newName);
  
} // standard




