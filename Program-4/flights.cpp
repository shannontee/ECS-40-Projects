#include <iostream>
#include <fstream>
#include "flights.h"
#include "flight.h"
#include "utilities.h"

using namespace std;

void Flights::insert(Flight* newFlight)
{
  int i;

  if( !(size < capacity))
  {
    Flight **newArray = flightsArray;
    flightsArray = new Flight * [START_SIZE * capacity];

    for(i = 0; i < size; i++)
    {
      flightsArray[i] = newArray[i];

    } // for loop
 
   delete [] newArray;

  //  flightsArray = newArray;
    capacity = capacity * START_SIZE;
  } // end if statement
  
  flightsArray[size] = newFlight;
  size++;
  i = size - START_SIZE;

  while(i >= 0 && flightsArray[i]->getFN() > flightsArray[i + 1]->getFN())
  {
      Flight *tempPtr;
      tempPtr = flightsArray[i + 1];
      flightsArray[i + 1] = flightsArray[i];
      flightsArray[i] = tempPtr;
      --i;
 
  } // while loop

} // insert()

Flights::Flights()
{
  capacity = START_SIZE; //size of the array
  size = 0; //number of flights in the array
  flightsArray = new Flight* [capacity];
} // Flights()


void Flights::addPassenger() const
{ 
  int i, flightNumber;
  
  cout << "Flt# Origin               Destination\n";
  
  for(i = 0; i < size; i++)
    flightsArray[i]->printFlightInfo();
  
  do
  { 
    cout << "\nFlight number (0 = exit): ";
    flightNumber = getNumber();
    
    if(flightNumber > 0)
    {
      
      for(i = 0; i < size; i++)
        if(flightsArray[i]->getFN() == flightNumber)
        { 
          flightsArray[i]->addPassenger(flightNumber);
          break;
        }  // if found match of flight
      
      if(i == size)
      { 
        cout << "We do not have a flight number " << flightNumber << ".\n";
        cout << "Please try again.\n";
      }  // if flightNumber not found
    }  // if flightNumber > 0
    else // if flightNumer <= 0
      if(flightNumber == ERROR)
        cout << "That is an invalid flight number.\nPlease try again.\n";
  }  while((flightNumber != 0 && i == size) || flightNumber == ERROR);
}  // addPassenger()

void Flights::readFlights()
{
  int i, numFlights;
  ifstream inf("flights.csv");
  
  inf >> numFlights;
              
  for(i = 0; i < numFlights; i++)
  {
    Flight *aFlight;
    aFlight = new Flight;
    aFlight->readFlight(inf);
    insert(aFlight);
  } // for loop
                                      
  inf.close();

} // readFlights()

Flights::~Flights()
{
  int i;
//  outf.open("passengers3.dat", ios::binary | ios:: out |  ios::trunc);
 // outf.close();

  ofstream outf("flights2.csv");
  outf << size << endl; // print num flights
  outf.close();
  outf.open("passengers3.dat", ios::binary | ios::trunc |  ios::out);
  outf.close();

  for (i = 0; i < size; i++)
    delete flightsArray[i]; 
  delete [] flightsArray; 
} // ~Flights()

void Flights::addFlight()
{
  int i;
  Flight* newFlight = new Flight;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    flightsArray[i]->printFlightInfo();
  
  newFlight->addFlight();

  insert(newFlight);
  
} // addFlight()

void Flights::removePassenger() const
{
  int i, removePass;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    flightsArray[i]->printFlightInfo();
 
  cout << "\nFlight number of passenger remove: ";
  removePass = getNumber(); 
 
  for(i = 0; i < size; i++)
  {
    if (flightsArray[i]->getFN() == removePass)
      flightsArray[i]->removePassenger();    
  } // for loop

} // removePassenger()

void Flights::removeFlight()
{
  int i, removeFlightNum;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    flightsArray[i]->printFlightInfo();

  cout << "\nFlight number to remove: ";
  removeFlightNum = getNumber();

  for(i = 0; i < size; i++)
  {
    if (flightsArray[i]->getFN() == removeFlightNum)
    {
      flightsArray[i]->removeFlight();
     
      delete flightsArray[i];
     

       for(; i < size; i++)
         flightsArray[i] = flightsArray[i + 1];
      size--;
      break;
   } // if statement
  } // for loop
} // removeFlight()
