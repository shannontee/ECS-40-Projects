#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "plane.h"
#include "utilities.h"

#define MAXSIZE 80
#define ASCII 65
#define INVALID -1

void readPlane (Plane *plane, FILE *fp)
{ 
  char str[MAXSIZE];
  int i, j;
  char *token;

  fgets (str, MAXSIZE, fp);
  token = strtok (str, " ");
  plane->rows = atoi (token);
  token = strtok (NULL, " ");
  plane->width = atoi (token);
  token = strtok (NULL, "\n");
  plane->reserved = atoi (token);
  plane->passengers = (char ***) malloc ((plane->rows) * sizeof (char**));

  for (i = 0; i<(plane->rows); i++)
  {
    plane->passengers[i] = (char **) malloc ((plane->width) * sizeof (char*));

    for (j = 0; j<(plane->width); j++)
      ((plane)->passengers[i][j]) = NULL;

  } // end for loop  
  
  readHelper(plane, fp);
} // end readPlane

void readHelper(Plane * pp, FILE* fp)
{
  int i, j, t, row, seat;
  char str[MAXSIZE], tempString[MAXSIZE], seatLetter;
  
  for(i = 0; i < (pp->reserved); i++)
  {
    fgets (str, MAXSIZE, fp);

    if(str[strlen(str) - 1] == '\n')
      str[strlen(str) - 1] = '\0';

    for (j = 0; j < (int)strlen(str) ; j++)
    {
      if (isdigit(str[j]))
        tempString[j] = str[j];
      else // determine seat letter
      {
        seatLetter = str[j];
        break;
      } // end else statement

    } // end for loop

    row = atoi (tempString);
    seat = int (seatLetter - ASCII);
    t  = strlen (str);
    ((pp)->passengers[row - 1][seat]) = (char *) malloc (t * sizeof (char));
    strcpy((pp->passengers[row - 1][seat]), str);
  } // end for loop

}// end helper

void printSeating (Plane *pp)
{ 
  int i, j;
  char a;
  
  printf ("ROW# ");
  
  for(i = 0; i<(pp->width); i++)
  {  
     a = char(i + ASCII);
     printf ("%c", a);
  } // end for loop

  printf ("\n");
  
  for(i = 0; i< (pp->rows); i++)
  { 
    printf (" %d   ", (i + 1));

    for(j = 0; j<(pp->width); j++)
    { 
      if(pp->passengers[i][j] == NULL)
        printf ("-");
      else // print X
        printf ("X");
    } // end printing X & -

    printf ("\n");
  } // end for printing of seating
  
  printf ("\nX = reserved.\n\n");
} // end printingSeating 

int userRowNumber (Plane* pp)
{
  int userRow;

  printf ("Please enter the row of the seat you wish to reserve: ");
  userRow = getNumber();
  
  if(userRow == INVALID)
  {
    printf ("That is an invalid row number.\nPlease try again.\n\n");
    return INVALID;
  } // end if statement
  else  // valid row input
    if(userRow > 0 && userRow <= (pp->rows))
      return userRow;
  else // no row on flight
  {
    printf ("There is no row #%d on this flight.\n", userRow);
    printf ("Please try again.\n\n");
    return INVALID;
  } // end else statement

} // end userRowNumber

int userSeatLetter (int userRow, Plane* pp)
{
  int userSeatNum;
 
  while (true)
  {
    printf ("Please enter the seat letter you wish to reserve: ");
    userSeatNum = getchar() - 'A';

    while(getchar() != '\n');

    if(userSeatNum < 0 || userSeatNum >= (pp->width))
      printf ("%d is not an available choice.\n", userSeatNum);
    else // else if comment
      if(pp->passengers[userRow - 1][userSeatNum] != NULL)
        printf ("That seat is already occupied.\nPlease try again.\n\n");
    else // else break
      break;
  } // while loop for userSeatLetter

  return userSeatNum;
} // end userSeatLetter

void addPass(int uRow, int uSeat, char* str, Plane* pp, int fNum, char* pName)
{
  int n;
  n = strlen (str);

  pp->passengers[uRow - 1][uSeat] = (char *) malloc (n * sizeof (char));
  strcpy (pp->passengers[uRow - 1][uSeat], str);
  pp->reserved = pp->reserved + 1;
  //printf("We have reserved seat %d%c ", uRow, char(uSeat+'A'));
  //printf("on flight %d for %s.\n", fNum, pName);
  //printf("string: %s\n length: %d\n", str, strlen(str));
} // end add passenger 

void printPass(Plane* pp, FILE* f)
{
   int i, j;
   
   fprintf(f, "%d %d %d\n", pp->rows, pp->width, pp->reserved);
   
   for(i = 0; i < pp->rows; i++)
   {
     for(j = 0; j < pp->width; j++)
     {
       if(pp->passengers[i][j] != NULL)
       { 
         fprintf(f, "%s\n", pp->passengers[i][j]);
       }// printing a passenger not null
     } // completing the width of that row
   }// complete the entire row
} // finish printing it to a file

void freePlane(Plane * pp)
{
  int i, j;

  for(i = 0; i < pp->rows; i++)
  {
    for(j = 0; j < pp->width; j++)
    {
        free(pp->passengers[i][j]);
        pp->passengers[i][j] = NULL;
    } //freeing one location

    free(pp->passengers[i]);
    pp->passengers[i] = NULL;
  }// freeing an entire row
 
  free(pp->passengers);

  pp->passengers = NULL;
}// ending the freeing of memory

