// Author: Sean Davis

#include <iostream>
#include <ctype.h>
#include <limits.h>
#include "utilities.h"

using namespace std;

int getNumber()
{
  long long number = 0, OK = 1;
  char c;

  for(c = cin.get(); isspace(c) && c != '\n'; c = cin.get());

  if(isdigit(c))
  {
    do
    {
      number = number * TENN + c - ASCII_ZERO;
      c = cin.get();
    }  while(isdigit(c) && number <= INT_MAX);

    while(c != '\n' && isspace(c))
      c = cin.get();

    if(c != '\n' || number > INT_MAX)
      OK = 0;
  }  // if first non-space is a digit
  else // first non-space is not a digit
    OK = 0;  // false

  while(c != '\n')
    c = cin.get();
    
  if(OK)
    return number;
  else  // invalid number
    return ERROR;
  
} // getNumber()

