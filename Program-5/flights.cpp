// Author: Sean Davis

#include <cstring>
#include "flights.h"
#include "utilities.h"

Flights::Flights() : size( 0 ), capacity(INITIAL_SIZE)
{
  flights = new Flight*[capacity];
} // Flights()


Flights::~Flights()
{
  ofstream outf ("flights2.csv");
  outf << size << endl;
  outf.close();
  outf.open("passengers3.dat", ios::trunc | ios::out);
  outf.close();

  for(int i = 0; i < size; i++)
    delete flights[i];

  delete [] flights;
} // ~Flights()

Flights & Flights::operator++()
{
  int i;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    cout << *flights[i];

  Flight *flight = new Flight();
  flight->addFlight();
  
  *this += flight; /// this->operator+=(flight)  (same lines of code)
  // (*this).operator+=(flight);
  // x OP y  ---> x.operatorOP(y)


  return *this;
}  // operator++


void Flights::addPassenger() const
{
  int i, flightNumber;

  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    cout << *flights[i];

  do
  {
    cout << "\nFlight number (0 = exit): ";
    flightNumber = getNumber();

    if(flightNumber > 0)
    {

      for(i = 0; i < size; i++)
        if(flights[i]->getFlightNumber() == flightNumber)
        {
        
          (*(flights[i]))++;
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
  } while((flightNumber != 0 && i == size) || flightNumber == ERROR);
}  // addPassenger()

void Flights::operator+=(Flight * flight) 
{
  int i;

  if(capacity == size)
  {
    Flight **temp = flights;
    capacity *= RESIZE_MULTIPLIER;
    flights = new Flight*[capacity];

    for(i = 0; i < size; i++)
      flights[i] = temp[i];

    delete [] temp;
  } // if size == capacity

  for(i = size - 1;
    i >= 0 && flights[i]->getFlightNumber() > flight->getFlightNumber(); i--)
    flights[i + 1] = flights[i];

  flights[i + 1] = flight;
  size++;
}  // operator +=


int Flights::getSize() const
{
  return size;
}  // size()


istream & operator>>(istream & inf, Flights & f)
{
  Flight *flight;
  int numberOfFlights;
  int i;

  //ifstream inf  ("flights.csv");
  inf >> numberOfFlights;

  for(i = 0; i < numberOfFlights; i++)
  {
    flight = new Flight;
    inf >> (*flight);
    
    f += flight;
  }  // for each flight

  //inf.close();
  return inf;
} // operator>>

Flights & Flights::operator--(int)
{
  int i, flightNumber;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    cout << *flights[i];
 

  cout << "\nFlight number to remove: ";
  cin >> flightNumber;
  cin.ignore(TEN, '\n');

  for(i = 0; i < size; i++)
    if(flights[i]->getFlightNumber() == flightNumber)
    {
     
      !(*(flights[i]));
      delete flights[i];

      for(; i < size - 1; i++)
        flights[i] = flights[i + 1];

      size--;
      break;
    }  // if found match of flight

    return *this;
}  // operator--


void Flights::findPassenger() const
{
  bool isFound = false;
  char passName[NAME_LENGTH];

  cout << "\nName of passenger: ";
  cin.getline(passName, NAME_LENGTH);
  //passName[strlen(passName) - 1] = '\0';

  for(int i =  0; i < size; ++i) 
  {

    if( flights[i]->findPassenger(passName))
      isFound = true;
  } // for loop

  if(!isFound) 
  {
    cout << passName << " not found.\n";
  } // if statement

} // findPassenger()

void Flights::removePassenger() const
{
  int i, flightNumber;
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    cout << *flights[i];

  cout << "\nFlight number of passenger remove: ";
  cin >> flightNumber;
  cin.ignore(TEN, '\n');

  for(i = 0; i < size; i++)
    if(flights[i]->getFlightNumber() == flightNumber)
    {

      --(*(flights[i]));
      break;
    }  // if found match of flight
}  // removePassenger()
