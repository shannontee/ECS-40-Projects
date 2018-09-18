#ifndef PLANE_H
#define	PLANE_H
#include <fstream>
#include "linkedlist.h"

using namespace std;


class Plane
{
  static const int FIRST_ROW = 1;
  static const int FIRST_SEAT = 'A';
  static const int TEN = 10;
  static const int ROW_SPACE = 2;
  int rows;
  int width;
  int reserved;
  int flightNumber;
 
  LinkedList *passengers; //array of linked list
  int getRow() const;
  void showGrid() const;

public:
  Plane(int flightNum);
  ~Plane();
  void addFlight();
  Plane & operator++(); 
  Plane & operator--(int); 
  Plane & operator!(); 
  void writePlane(ofstream &outf) const;
  int findPassenger(const char *passName) const;

  friend istream & operator>>(istream &inf, Plane & plane);
  friend ostream & operator<<(ostream &out, const Plane & plane);
}; // class Plane

istream & operator>>(istream &inf, Plane & plane);
ostream & operator<<(ostream &out, const Plane & plane);

#endif	// PLANE_H
