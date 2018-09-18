#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "food.h"
#include "fattyfood.h"

using namespace std;


int main()
{
  Food* foo;
  FattyFood* fatfoo;
  ifstream inf ("food.txt");
  char type;
//  int calories;
//  string name;
//  int fiber; 
//  float fat;

  char temp[6]="hello";
  cout <<  strlen(temp) << endl;
 

  while(inf>>type)
  {
     if (type == 'N')
     {
        foo = new Food;
        inf >> (*foo);
        foo->print();
     }
     else if (type == 'F')
    {
        fatfoo = new FattyFood;
        inf >> (*fatfoo);
        fatfoo->print(); 
    }
  }

 /* while(inf>>type)
  {
    if(type ==  'N')
    {
       inf >> foo->calories >> foo->fiber >> foo->name;
    //   cout << type << ' ' << calories << ' ' << fiber << ' ' << name << endl;
    }
    
   else if (type == 'F')
    {
       inf >> calories >> fiber >> fat >> name;
       cout << type << ' ' << calories << ' ' << fat << ' '<< fiber << ' ' << name << endl;
    }
   else 
     cout << "none" << endl;
 }
*/
  inf.close();
//  cout << type << ' ' << foo->calories << ' ' << foo->fiber << ' ' << foo->name << endl;
return 1;
}
