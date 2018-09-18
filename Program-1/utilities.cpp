#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "utilities.h"

#define MAXSIZE 80
#define ASCII 65
#define INVALID -1
#define TEN 10
#define TWENTY 20
#define THREE 3
#define ASC_ZERO '0'

int userReservationChoice()
{
  int userChoice;

  printf ("Please enter your choice: ");
  userChoice = getNumber();

  if(userChoice == INVALID)
  {
    printf ("Your choice is invalid.\nPlease try again.\n\n");
    return (INVALID);
  } // end invalid userChoice
  else // else if greater htan 0 or 1
    if(userChoice < 0 ||  userChoice > 1)
    {
        printf ("%d is not an available choice.\n", userChoice);
        printf ("Please try again.\n\n");
        return(INVALID);
    } // end unavaliable userChoice
  else // else it's a valid choice
  { // exit 
    if(userChoice == 0)
    {
       printf ("Goodbye.\n");
       return userChoice;
    } // end goodbye userChoice 
    else // continue
      return userChoice;
  } // ending the choice
} // end userReservationChoice

int getNumber()
{
 long long number = 0, OK = 1;
  char c;

  for(c = getchar(); isspace(c) && c != '\n'; c = getchar());

  if(isdigit(c))
  {
    do
    {
      number = number * TEN + c - ASC_ZERO;
      c = getchar();
    }  while(isdigit(c) && number <= INT_MAX);

    while(c != '\n' && isspace(c))
      c = getchar();

    if(c != '\n' || number > INT_MAX)
      OK = 0;
  }  // if first non-space is a digit
  else // first non-space is not a digit
    OK = 0;  // false

  while(c != '\n')
    c = getchar();

  if(OK)
    return number;
  else  // invalid number
    return INVALID; 
} // end getNumber

void title ()
{
  printf ("\nECS Flight Reservation Menu\n0. Exit.\n1. Add Passenger.\n\n");
} // end title

int numberFlight ()
{
  int numFlights;
  FILE *fp;
  fp = fopen ("reservations.txt", "r");
  fscanf (fp, "%d\n", &numFlights);
  fclose (fp);
  return numFlights;
} // end numberFlight
