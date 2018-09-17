#include <iostream>
#include <fstream>
#include "container.h"
#include "vector.h"                         
#include "sortedvector.h"                   
#include "linkedlist.h"                     
#include "sortedlinkedlist.h"               

using namespace std;

int main(int argc, char** argv) 
{
  char operation;
  int num, *intPtr, containerNum, index;
  Container *containers[4] = {NULL, NULL, NULL, NULL};

  SortedVector *vectors[2];                       
  containers[0] = vectors[0] = new SortedVector; 
  Vector *vectorPtr = new Vector;                 
  containers[1] = vectors[1] = vectorPtr;         
  LinkedList *lists[2];                            
  containers[2] = lists[0] = new LinkedList;      
  containers[3] = lists[1] = new SortedLinkedList; 
  
  ifstream inf(argv[1]);
  
  while(inf >> containerNum >> operation)
  {  
    switch(operation)
    {
        case 'C' :   
        cout << "Capacity: " << vectors[containerNum]->getCapacity() << endl; 
        break;
                    
      case 'E' : 
        inf >> num;
        intPtr = containers[containerNum]->erase(num); 
        cout << "Erase " << num << " : ";

        if(intPtr)
          cout << *intPtr << endl;
        else // nothing after num
          cout << "NULL\n";

        break;
      case 'F' :
        inf >> num;
        cout << "Find " << num << " : ";  
        intPtr = containers[containerNum]->find(num); 

        if(intPtr)
          cout << *intPtr << endl;
        else // not found
          cout << "NULL\n";

        break; 
      case 'I' : 
        inf >> num;
        intPtr = containers[containerNum]->insert(num); 
        cout << "Insert " << num << " : " << *intPtr << endl;
        break;
      case 'S' :
        cout << "Size: " << containers[containerNum]->getSize() << endl;
        break; 
      case 'R' :                       
        inf >> index;
        num = (*vectors[containerNum])[index];
        cout << "Read [" << index << "] : " << num << endl;
        break;
      case 'W' : 
        inf >> index >> num;
        cout << "Write [" << index << "] = " << num << endl;
        (*vectorPtr)[index] = num;  
        break;
      case 'M' : 
        intPtr = --(*lists[containerNum - 2]); 
        cout << "-- : ";
        
        if(intPtr)
          cout << *intPtr << endl;
        else  // moved beyound front of container
          cout << "NULL\n";
        
        break;
      case 'P' :
        intPtr = ++(*lists[containerNum - 2]) ; 
        cout << "++ : ";
        
        if(intPtr)
          cout << *intPtr << endl;
        else  // moved beyond end of container
          cout << "NULL\n";
        
        break;
    }  // switch
  }  // while more in file
    
  for(int i = 0; i < 4; i++)
    if(containers[i])
      delete containers[i];

  return 0;
} // main())

