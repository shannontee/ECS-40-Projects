#include <string.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "plane.h"
#include "utilities.h"
#include "passenger.h"

using namespace std;

Plane::Plane(const int flightNum, ifstream &inf)
{
  int row, seatNum, position; 
  reserved = 0;
  inf >> rows; 
  inf.ignore();
  inf  >> width;
  inf.ignore();
  passengers = new int * [rows];
  
  for(row = 0; row < rows; row++)
  {
    passengers[row] = new int [width];
    
    for(seatNum = 0; seatNum < width; seatNum++)
      passengers[row][seatNum] = EMPTY;
  } // for each row

  Passenger passenger;
  ifstream infPass("passengers2.dat");
  position = infPass.tellg();

  while(infPass.read((char*)&passenger, sizeof(Passenger)))
  {
    if (flightNum == passenger.flightNum)
    {
      passengers[passenger.row - 1][passenger.seat - FIRST_SEAT] = position;
      reserved++;
    } // if statement

    position = infPass.tellg();
  }  // for each passenger
}  // Plane()


Plane::~Plane()
{
  int row; // seatNum;
  
  for(row = 0; row < rows; row++)
  {   
    delete passengers[row];
  }  // for row
  
  delete [] passengers;
}  // ~Plane()


int Plane::addPassenger(const int flightNum)
{
  int row, seatNum;
  char name[MAX_NAME_SIZE];
  char seatLetter;
  
  if(reserved == rows * width)
    return 0;  // false
  
  cout << "Please enter the name of the passenger: ";
  cin.getline(name, MAX_NAME_SIZE);
  showGrid();
  
  while(TRUE)
  {
    row = getRow();
    cout << "Please enter the seat letter you wish to reserve: ";
    seatNum = cin.get() - FIRST_SEAT;

    while(cin.get() != '\n');

    if(passengers[row - FIRST_ROW][seatNum] == EMPTY)
      break;

    printf("That seat is already occupied.\nPlease try again.\n");
  } // while occupied seat

  seatLetter = seatNum + FIRST_SEAT;
  ofstream outf ("passengers2.dat", ios::binary | ios::app );
  Passenger passenger = Passenger(flightNum, row, seatLetter, name);
  passengers[row - FIRST_ROW][seatNum] = outf.tellp();
  outf.write((char*)&passenger, sizeof(Passenger));
  reserved++;
  return 1;
}  // addPassenger()


int Plane::getRow() const
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

void Plane::showGrid() const
{
  int row, seatNum = 0;
  
  printf("ROW# ");
  
  for(seatNum = 0; seatNum < width; seatNum++)
    cout << char(seatNum + FIRST_SEAT);
  
  putchar('\n');
  
  for(row = 0; row < rows; row++)
  {
    printf("%2d   ", row + 1);
    
    for(seatNum = 0; seatNum < width; seatNum++)
    {
      if(passengers[row][seatNum] != EMPTY)
        putchar('X');
      else  // empty seat
        putchar('-');
    } // for loop

    putchar('\n');
  }  // for each row
  
  printf("\nX = reserved.\n");

}  // showGrid()


void Plane::writePlane(const int flightNum, ofstream &outf) const
{
  outf << rows << ',' << width << endl;

  int i, j ;
  Passenger passenger;
  ifstream inf ("passengers2.dat", ios::binary);
  ofstream outff ("passengers3.dat", ios::binary | ios::app);  

  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < width; j++)
    {
      if( passengers[i][j] != EMPTY)
      {       
        inf.seekg(passengers[i][j], ios::beg);
        inf.read((char*)&passenger, sizeof(Passenger));
        outff.write ((char*)&passenger, sizeof(Passenger));
      } // if statement
    } // for loop
  } // for loop

  inf.close();
  outff.close();

}  // writePlane()

Plane::Plane()
{
} // default

void Plane::addFlight()
{ 
  int row, seatNum;
  cout << "Rows: ";
  rows = getNumber();
  cout << "Width: ";
  width = getNumber();

  passengers = new int * [rows];

  for(row = 0; row < rows; row++)
  { 
    passengers[row] = new int [width];
    
    for(seatNum = 0; seatNum < width; seatNum++)
      passengers[row][seatNum] = EMPTY;

  } // for each row

} // addFlight()

void Plane::removePassenger()
{
  int i, j;
  
  Passenger passenger;
  fstream inf ("passengers2.dat", ios::binary | ios::in | ios::out);

  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < width; j++)
    {
      if (passengers[i][j] != EMPTY)
      {
        inf.seekg(passengers[i][j], ios::beg);
        inf.read((char*)&passenger, sizeof(Passenger));
        cout << passenger.name << endl;
      } // if statement
    } // for loop
  } // for loop

  inf.close();
  removePassenger2();

} // removePassenger()

void Plane::removePassenger2()
{
  int i, j;
  char passName [MAX_NAME_SIZE];

  Passenger passenger;
  fstream inf ("passengers2.dat", ios::binary | ios::in | ios::out);

  cout << "\nName of passenger to remove: ";
  cin.getline (passName, MAX_NAME_SIZE);

 for (i = 0; i < rows; i++)
  {
    for (j = 0; j < width; j++)
    {
      if (passengers[i][j] != EMPTY)
      {
        inf.seekg(passengers[i][j], ios::beg);
        inf.read((char*)&passenger, sizeof(Passenger));

        if (strcmp (passenger.name, passName) == 0)
        {
          passenger.flightNum = EMPTY;
          reserved--;
          inf.seekp(passengers[i][j], ios::beg);
          inf.write((char*)&passenger, sizeof(Passenger));
          passengers[i][j] = EMPTY;
        } // if statement
      } // if statement
    } // for loop
  } // for loop

  inf.close();

} // removePassenger2()


void Plane::removeFlight() const
{
  int i, j;

  Passenger passenger;
  fstream inf ("passengers2.dat", ios::binary | ios::in | ios::out);  

  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < width; j++)
    {
      if (passengers[i][j] != EMPTY)
      {
        inf.seekg(passengers[i][j], ios::beg);
        inf.read((char*)&passenger, sizeof(Passenger));
        passenger.flightNum = EMPTY;
        inf.seekp(passengers[i][j], ios::beg);
        inf.write((char*)&passenger, sizeof(Passenger));
      } // if statement
    } // if statement

  } // for loop

  inf.close();

} // removeFlight()
