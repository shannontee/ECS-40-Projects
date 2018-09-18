#ifndef _PLANE_H_
#define _PLANE_H_

typedef struct
{
  int rows;
  int width;
  int reserved;
  char ***passengers;
} Plane;

void readPlane(Plane *plane, FILE *fp);

void printSeating (Plane* pp);

int userRowNumber (Plane* pp);

int userSeatLetter (int userRow, Plane* pp);	
void addPass(int uRow, int uSeat, char* str, Plane* pp, int fNum, char* pName);
//void readingPlaneInfo (Plane* plane, FILE* FP);
void printPass(Plane* plane, FILE* f);
void freePlane(Plane* plane);
void readHelper(Plane* plane, FILE* f);
#endif 

