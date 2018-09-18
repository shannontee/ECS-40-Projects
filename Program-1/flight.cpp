#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "flight.h"
#include "utilities.h"

#define MAXSIZE 80
#define ASCII 65
#define INVALID -1
#define TEN 10
#define TWENTY 20
#define THREE 3
#define LENGTH 20
#define EXIT -2

Flight* openFlight (int numFlights)
{
  FILE *fp;
  Flight* flights;
  fp = fopen ("reservations.txt", "r");
  flights = (Flight *) malloc (numFlights * sizeof (Flight));
  readFlight (numFlights, flights, fp);
  fclose (fp);
  return flights;
} // end openFlight 

Flight* readFlight (int numFlights, Flight* flights, FILE *fp )
{ 
  int i;
  char str[LENGTH];
  fgets (str, LENGTH, fp);
  
  for(i = 0; i<numFlights; i++)
  { 
    fscanf (fp, "%d ", &(flights[i].flightNum));
    fscanf (fp, "%[^\n]\n\n", (flights[i].origin)); 		
    flights[i].origin[strlen(flights[i].origin)] = (char) 0;
    fscanf (fp, "%[^\n]\n", (flights[i].destination));		       
    flights[i].destination[strlen(flights[i].destination)] = (char) 0;
    flights[i].plane = (Plane * ) malloc (sizeof (Plane));
    readPlane (flights[i].plane, fp);	
  } // end for loop

  return flights;
} // readFlight

int menuFlights (int numFlights, Flight* flights)
{
  int userChoice, n;
  userChoice =  userReservationChoice();

  if(userChoice == INVALID)
    return 1;
  else // else user choice
    if(userChoice == 0)
    {
      printToFile(numFlights, flights);
      freeFlight(numFlights, flights);
      return 0;
    } // end if else
  
  printFlightMenu (numFlights, flights);
 
  while ((n = (userFlightNumber(numFlights, flights))) == INVALID);

  if(n == EXIT)
  {
    title();
    return 1;
  } // ending if 

  menuHelper(flights, n);
  return 1;
} // end menu function

void menuHelper(Flight* flights, int n)
{
  char passName[MAXSIZE], str[MAXSIZE], c[THREE];
  int uRow, uSeat, temp;
  
  printf ("Please enter the name of the passenger: ");
  
  fgets(passName, MAXSIZE, stdin);

  if(strlen(passName)>0 && (passName[strlen(passName) - 1] == '\n'))
    passName[strlen(passName) - 1] = (char) 0;

  printSeating ((flights + n)->plane);

  while((uRow = userRowNumber((flights + n)->plane)) == INVALID);

  uSeat = userSeatLetter(uRow, (flights + n)->plane);
  sprintf (c, "%d", uRow);
  strcpy (str, c);
  temp = strlen(str);
  str[temp] = char(uSeat + 'A');
  str[temp + 1] = (char) 0 ;
  strcat (str, " ");
  strcat (str, passName);
  addPass(uRow, uSeat, str, flights[n].plane, flights[n].flightNum, passName);
  title ();

}// ending function

void printFlightMenu(int numFlights, Flight* flights)
{
  int i;
  printf ("Flt# Origin               Destination\n");

  for(i = 0; i < numFlights; i++)
  {
    printf("%-4d %-20s ", flights[i].flightNum, flights[i].origin);
    printf ("%s\n", flights[i].destination);
  } // end printing

} //end printFlightMenu function

int userFlightNumber(int numFlights, Flight* flights)
{ 
  int userFlightNum, i;
  printf ("\nFlight number (0 = exit): ");
  userFlightNum = getNumber();
  
  if(userFlightNum == 0)
  { 
    return EXIT;
  } // end goodbye userFlightNumber
  else  // invalid flight number
    if(userFlightNum == INVALID)
    { 
      printf ("Your number is invalid.\nPlease try again.\n\n");
      return INVALID;
    } // end invalid userFlightNumber
  else // check flight number
  { 
    for(i = 0; i<numFlights; i++)
    {

     if(userFlightNum == (flights + i)->flightNum)
       return i;
     else  // unavaliable flight number
       if(i == (numFlights - 1))
       {
        printf ("We do not have a flight number %d.\n", userFlightNum);
        printf ("Please try again.\n");
        return INVALID;
       } // end else statement
    } // end for loop
  } // end else statement

  return INVALID;
} // end userFlightNumber

void printToFile( int numFlights, Flight* flights)
{
  FILE *f;
  int i;
  f = fopen("reservations2.txt", "w");

  fprintf(f, "%d\n", numFlights);

  for(i = 0; i < numFlights; i++)
  {
    fprintf(f, "%d\n", flights[i].flightNum);
    fprintf(f, "%s\n", flights[i].origin);
    fprintf(f, "%s\n", flights[i].destination);
    printPass(flights[i].plane, f);
  } // end for loop for printing 

} // end printing function

void freeFlight(int numFlights, Flight* flights)
{
  int i = 0;

  for(i = 0; i < numFlights; i++)
  {
     freePlane(flights[i].plane);
     free(flights[i].plane);
  } // end for loop

  free(flights);
  flights = NULL;
} // end freeFlight
