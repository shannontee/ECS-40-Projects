// Author: Sean Davis

#include <iostream>
#include <fstream>
#include <iomanip>
#include "passenger.h"
#include "flight.h"
#include "flights.h"
#include "utilities.h"

using namespace std;

enum 
  {
    DONE, 
    ADD_PASSENGER, 
    REMOVE_PASSENGER, 
    ADD_FLIGHT, 
    REMOVE_FLIGHT, 
    SEARCH_PASS
  }; //enum

const int MAX_CHOICE = SEARCH_PASS;

int getChoice()
{
  int choice;
  cout << "\nECS Flight Reservation Menu\n";
  cout << DONE << ". Exit.\n";
  cout << ADD_PASSENGER << ". Add Passenger.\n";
  cout << REMOVE_PASSENGER << ". Remove Passenger.\n";
  cout << ADD_FLIGHT << ". Add Flight.\n";
  cout << REMOVE_FLIGHT << ". Remove Flight.\n";
  cout << SEARCH_PASS << ". Find Passenger.\n";

  do
  {
    cout << "\nPlease enter your choice: ";
    choice = getNumber();

    if(choice == ERROR)
    {
      cout << "Your choice is invalid.\n";
      cout << "Please try again.\n";
    }  // if invalid format
    else // choice is a valid number
      if(choice < DONE || choice > MAX_CHOICE)
      {
        cout << choice << " is not an available choice.\n";
        cout << "Please try again.\n";
      }  // if choice out of range.
  } while(choice < DONE || choice > MAX_CHOICE  || choice == ERROR);

  if(choice == DONE)
    cout << "Goodbye.\n";

  return choice;
} // getChoice()


int main(int argc, char** argv)
{
  int choice;
  Flights flights;
  Passenger::copyPassengers();
  ifstream inf  ("flights.csv");
  inf >> flights; 
  inf.close();

  while((choice = getChoice()) != DONE)
    switch(choice)
    {

      case ADD_PASSENGER : flights.addPassenger(); break;
      case REMOVE_PASSENGER : flights.removePassenger(); break;
      case ADD_FLIGHT : ++flights; break;
      case REMOVE_FLIGHT : flights--; break;
      case SEARCH_PASS : flights.findPassenger(); break;

    }  // switch

  return 0;
} // main())
