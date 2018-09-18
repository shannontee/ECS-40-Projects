#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <ctype.h>
#include "plane.h"
#include "utilities.h"

using namespace std;

#define TRUE 1
#define IGNORE 1000

int Plane::addPassenger()
{
  int row, seatNum;
  char name[MAX_NAME_SIZE];
  
  if(reserved == rows * width)
    return 0;  // false
  
  cout << "Please enter the name of the passenger: ";
  cin.getline(name, MAX_NAME_SIZE);
  strtok(name, "\r\n");
  showGrid();
  
  while(TRUE)
  {
    row = getRow();
    cout << "Please enter the seat letter you wish to reserve: ";
    seatNum = cin.get() - FIRST_SEAT;

    while(cin.get() != '\n');

    if(passengers[row - FIRST_ROW][seatNum] == NULL)
      break;

    cout << "That seat is already occupied.\nPlease try again.\n";
  } // while occupied seat
  
  passengers[row - FIRST_ROW][seatNum] 
    = new char (strlen(name) + 1);
  strcpy( passengers[row - FIRST_ROW][seatNum], " ");
  strcat( passengers[row - FIRST_ROW][seatNum], name);
  reserved++;
  return 1;
}  // addPassenger()

Plane::~Plane()
{
  int row, seatNum;

  for(row = 0; row < rows; row++)
  { 
    for(seatNum = 0; seatNum < width; seatNum++) 
    {
      if(passengers[row][seatNum] != NULL)
        delete[] (passengers[row][seatNum]);
    } // if passengers 

    delete [] passengers[row];
  }  // for row

 delete [] passengers;
}  // freePlane


int Plane::getRow()
{
  int row;
  
  do
  {
    cout << "\nPlease enter the row of the seat you wish to reserve: ";
    row = getNumber();

    if(row == ERROR)
      cout << "That is an invalid row number.\nPlease try again.\n";
    else  // valid row number
      if(row < 1 || row > rows)
        cout << "There is no row #" << row 
          << " on this flight.\nPlease try again.\n";
  }  while(row < 1 || row > rows);
  
  return row;
} // getRow()

  
Plane::Plane(ifstream &inf)
{
  int row, numPassenger, seatNum;
  char seat, name[MAX_NAME_SIZE];
  inf>>rows>>width>>reserved;
  inf.ignore(IGNORE, '\n');
  passengers = new char ** [rows];
  
  for(row = 0; row < rows; row++)
  {
    passengers[row] = new char * [width];

    for(seatNum = 0; seatNum < width; seatNum++)
      passengers[row][seatNum] = NULL;
  } // for each row 

  for(numPassenger = 0; numPassenger < reserved; numPassenger++)
  {
    inf>>row>>seat;
    inf.getline(name, MAX_NAME_SIZE);
    seatNum = seat;
    passengers[row - FIRST_ROW][seat - FIRST_SEAT] 
      = new char [strlen(name) + 1];
    strcpy(passengers[row - FIRST_ROW][seatNum - FIRST_SEAT], name);
  }  // for each passenger
}  // readPlane()


void Plane::showGrid()
{
  int row, seatNum = 0;
  
  cout << "ROW# ";
  
  for(seatNum = 0; seatNum < width; seatNum++)
    putchar(seatNum + FIRST_SEAT);
  
  putchar('\n');
  
  for(row = 0; row < rows; row++)
  {
    cout << right << setw(2) << row + 1 << "   "; 
    
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum])
        putchar('X');
      else  // empty seat
        putchar('-');
    
    putchar('\n');
  }  // for each row
  
  cout << "\nX = reserved.\n";
}  // showGrid()


void Plane::writePlane(ofstream &outf)
{
  int row, seatNum;
  outf << rows << ' ' << width << ' ' << reserved << endl;

  for(row = 0; row < rows; row++)
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != NULL)
        outf << row + FIRST_ROW << char (seatNum + FIRST_SEAT) 
          << passengers[row][seatNum] << endl;

}  // readPlane()
