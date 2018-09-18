#include <stdio.h> 
#include <stdlib.h>
#include "flight.h"
#include "plane.h"
#include "utilities.h"

int main ()
{
  int numFlights = numberFlight();
  Flight* flights = openFlight(numFlights);
  title ();

  while (menuFlights(numFlights, flights) != 0);

  return 0;
} // end main
