#ifndef PLANE_H
#define	PLANE_H

#include <fstream>

using namespace std;

#define MAX_NAME_SIZE 80
#define FIRST_ROW 1
#define FIRST_SEAT 'A'

class Plane
{
  int rows;
  int width;
  int reserved;
  char ***passengers;

  public:
    int addPassenger();
    ~Plane();
    int getRow();
    Plane(ifstream &inf);
    void showGrid();
    void writePlane(ofstream &outf);

}; // class Plane

#endif	// PLANE_H

