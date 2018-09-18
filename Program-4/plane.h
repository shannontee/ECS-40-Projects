#ifndef PLANE_H
#define	PLANE_H
#include <fstream>

using namespace std;

class Plane
{
  static const int MAX_NAME_SIZE = 80;
  static const int FIRST_ROW = 1;
  static const char FIRST_SEAT = 'A';
  static const int EMPTY = -1;
  static const int TRUE = 1;

  int rows;
  int width;
  int reserved;
  int  **passengers;
  int getRow() const;
  void showGrid() const;
public:
  Plane(int flighNum, ifstream &inf);
  Plane();
  ~Plane();
  int addPassenger(int flightNum);
  void writePlane(int flightNum, ofstream &outf) const;
  void addFlight();
  void removePassenger();
  void removePassenger2();
  void removeFlight() const;

}; // class Plane

#endif	// PLANE_H


