// Author: Sean Davis

#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "plane.h"
#include "utilities.h"
#include "passenger.h"
#include "linkedlist.h"

using namespace std;


Plane::Plane(const int fn)
{
  flightNumber = fn;
}  // Plane()

istream & operator>>(istream &inf, Plane & plane)
{
  int row, temp1, temp2; 
  char comma;
  Passenger passenger;
  inf >> plane.rows >> comma >> plane.width;
  plane.passengers = new LinkedList [plane.rows];

  for(row = 0; row < plane.rows; row++)
  {
    plane.passengers[row].initialize(plane.width);

  } // for each row

  ifstream inf2("passengers.dat", ios::binary);

  while(inf2.read((char*) &passenger, sizeof(Passenger)))
  {
    if(passenger == plane.flightNumber)
    {
      temp1 = passenger.row - plane.FIRST_ROW;
      temp2 = passenger.seat - plane.FIRST_SEAT;
      plane.passengers[temp1][temp2]
        = (int) inf2.tellg() - sizeof(Passenger);
      plane.reserved++;
    }  // if the passenger is on this flight
  }  // while more in file

  inf2.close();
  return inf;
}  // Plane()


Plane::~Plane()
{
  
  delete [] passengers;
}  // ~Plane()


void Plane::addFlight()
{
  cout << "Rows: ";
  cin >> rows;
  cout << "Width: ";
  cin >> width;
  cin.ignore(TEN, '\n');
  passengers = new LinkedList[rows];

  for(int row = 0; row < rows; row++)
  {
    passengers[row].initialize(width);

  } // for each row
}  // addFlight()

Plane & Plane::operator++() //prefix++
{
  int row, seatNum;
  char name[Passenger::NAME_LENGTH], seat;

  if(reserved == rows * width) 
  {
    cout << "We are sorry but Flight #" << flightNumber << " is full.\n";
    return *this;
  } // if statement

  cout << "Please enter the name of the passenger: ";
  cin.getline(name, Passenger::NAME_LENGTH);
  showGrid();

  while(true)
  {
    row = getRow();
    cout << "Please enter the seat letter you wish to reserve: ";
    seat = cin.get();
    seatNum = seat - FIRST_SEAT;

    while(cin.get() != '\n');

    if(passengers[row - FIRST_ROW][seatNum] == LinkedList::EMPTY)
      break;
    printf("That seat is already occupied.\nPlease try again.\n");
  } // while occupied seat

  ofstream outf("passengers2.dat", ios::binary | ios::app);
  passengers[row - FIRST_ROW][seatNum] = outf.tellp();
  Passenger passenger(flightNumber, row, seat, name);
  outf.write((char*) &passenger, sizeof(Passenger));
  reserved++;
  return *this;
}  // operator ++


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

  cout << "ROW# ";

  for(seatNum = 0; seatNum < width; seatNum++)
    cout << char(seatNum + FIRST_SEAT);

  cout << endl;

  for(row = 0; row < rows; row++)
  {

    cout << right << setw(ROW_SPACE) << row + 1 << "   ";

    cout << passengers[row];
    cout << endl;
  }  // for each row

  cout << "\nX = reserved.\n";
}  // showGrid()



int Plane::findPassenger(const char *passName) const
{
 
  Passenger passenger;


  fstream inOutf("passengers2.dat", ios::binary | ios::in | ios::out);

  int found = 0;

  for(int row = 0; !found && row < rows; row++)
    for(int seatNum = 0; !found && seatNum < width; seatNum++)
      if(passengers[row][seatNum] != LinkedList::EMPTY)
      {
        inOutf.seekg(passengers[row][seatNum], ios::beg);
        inOutf.read((char*) &passenger, sizeof(Passenger));

        if( passenger == passName )
        {
          //found the passenger, so print out info.
         
          cout << "Flight #" << flightNumber
            << " Row: " << row + FIRST_ROW
            << " Seat: " << static_cast<char>('A' + seatNum) << endl;
          found = 1;
        }  // if found name
      }  // if seat not empty

  inOutf.close();
  return found;
} // findPassenger()


Plane & Plane::operator--(int) //postfix --
{
  char name[Passenger::NAME_LENGTH];
  Passenger passenger;
  cout << "Passengers on Flight #" << flightNumber << endl;

  cout << *this;
  fstream inOutf("passengers2.dat", ios::binary | ios::in | ios::out);
  cout << "\nName of passenger to remove: ";
  cin.getline(name, Passenger::NAME_LENGTH);
  bool found = false;

  for(int row = 0; !found && row < rows; row++)
    for(int seatNum = 0; !found && seatNum < width; seatNum++)
      if(passengers[row][seatNum] != LinkedList::EMPTY)
      {
        inOutf.seekg(passengers[row][seatNum], ios::beg);
        inOutf.read((char*) &passenger, sizeof(Passenger));

        if( passenger == name )
        {
          
          !passenger;
          inOutf.seekp(passengers[row][seatNum], ios::beg);
          inOutf.write((char*) &passenger, sizeof(Passenger));
          passengers[row][seatNum] = LinkedList::EMPTY;
          found = true;
        }  // if found name
      }  // if seat not empty

  inOutf.close();
  return *this;
}  // operator

Plane & Plane::operator!()
{
  Passenger passenger;
  fstream inOutf("passengers2.dat", ios::binary | ios::in | ios::out);

  for(int row = 0; row < rows; row++)
    for(int seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != LinkedList::EMPTY)
      {
        inOutf.seekg(passengers[row][seatNum], ios::beg);
        inOutf.read((char*) &passenger, sizeof(Passenger));
       
        !passenger;
        inOutf.seekp(passengers[row][seatNum], ios::beg);
        inOutf.write((char*) &passenger, sizeof(Passenger));
      }  // if seat not empty

  return *this;
}  // operator!

ostream & operator<<(ostream &out, const Plane & plane)
{
  Passenger passenger;
  ifstream inf("passengers2.dat", ios::binary);

  for(int row = 0; row < plane.rows; row++)
    for(int seatNum = 0; seatNum < plane.width; seatNum++)
      if(plane.passengers[row][seatNum] != LinkedList::EMPTY)
      {
        inf.seekg(plane.passengers[row][seatNum], ios::beg);
        inf.read((char*) &passenger, sizeof(Passenger));
        out << passenger << endl;
      }  // if statement

   inf.close();
   return out;
}  // operator<<


void Plane::writePlane(ofstream &outf) const
{
  int row, seatNum;
  Passenger passenger;
  outf << rows << ',' << width << endl;

  ifstream inf("passengers2.dat", ios::binary);
  ofstream outf2("passengers3.dat", ios::binary | ios::app);

  for(row = 0; row < rows; row++)
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != LinkedList::EMPTY)
      {
        inf.seekg(passengers[row][seatNum], ios::beg);
        inf.read((char*) &passenger, sizeof(Passenger));
        outf2.write((char*) &passenger, sizeof(Passenger));
      }  // if seat not empty
}  // writePlane()
