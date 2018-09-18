#include <iostream>

using namespace std;

template <typename T>
ReverseVectorIterator<T>::ReverseVectorIterator(const Vector<T> *ptr, int pos)
  :vectorPtr(ptr), position(pos) 
{
} // ReverseVectorIterator()

template <typename T>
const T& ReverseVectorIterator<T>::operator*() const
{
  return vectorPtr->arr[position];
} // operator*

template <typename T>
void ReverseVectorIterator<T>::operator++(int) 
{
  --position;

  if(position < 0)
    position = NPOS;
} // operator++

template <typename T>
bool ReverseVectorIterator<T>::operator!=
  (const ReverseVectorIterator<T> & rhs) const
{
  return position != rhs.position;
} //operator!

template <typename T>
VectorIterator<T>::VectorIterator(const Vector<T> *ptr, int pos)
  :vectorPtr(ptr), position(pos)
{
} // VectorIterator()

template <typename T>
const T& VectorIterator<T>::operator*() const
{
  return vectorPtr->arr[position];
} // operator* 

template <typename T>
void VectorIterator<T>::operator++(int)
{
  ++position;

  if(position >= vectorPtr->count)
    position = NPOS;

} // operator+=

template <typename T>
bool VectorIterator<T>::operator!=(const VectorIterator<T> & rhs) const
{
  return position != rhs.position;
} // operator!

//--------------------------

template <typename T>
VectorIterator<T> Vector<T>::begin() const
{
  iterator itr(this, 0);
  return itr;
} // begin()

template <typename T>
VectorIterator<T> Vector<T>::end() const
{
  iterator itr(this, NPOS);
  return itr;
} // end()

template <typename T>
ReverseVectorIterator<T> Vector<T>::rbegin() const
{
  reverse_iterator itr(this, count - 1);
  return itr;
} // rbegin()

template <typename T>
ReverseVectorIterator<T> Vector<T>::rend() const
{
  reverse_iterator itr(this, NPOS);
  return itr;
} // rend()


template <typename T>
const int Vector<T>::size() const
{
  return count;
} // size()

template <typename T>
const int Vector<T>::capacity() const
{
  return storage;
} // capacity()

template <typename T>
Vector<T>::Vector()
{
  storage = 0; // initializes values
  count = 0; 
  arr = NULL;
} // Vector()

template <typename T>
Vector<T>::Vector(const T* array)
{
  int i;
  
  for(i = 0; ; i++) // determines length of array
  {

    if(array[i] == 0)
      break;
  } // for loop
  
  count = i;
  storage = i;
  arr = new T[count]; // creates new array

  for(i = 0; i < count; i++) // copy to new
     arr[i] = array[i];

} // Vector()

template <typename T>
Vector<T>::~Vector()
{
  delete [] arr;
} // ~Vector()

template <typename T>
ostream& operator<< (ostream& os, const Vector<T>& vector)
{
  int i;
 
  for(i = 0; i < vector.size(); i++) // prints out vector
    os << vector.arr[i];

  return os;
} // operator <<


template <typename T>
Vector<T> Vector<T>::operator= (const Vector<T>& vector)
{
  int i;

  if (vector.count != storage)
  {
    delete [] arr;
    arr = new T[vector.storage];
    storage = vector.storage;
  } // if statement

  count = vector.count;
 
  for(i = 0; i < count; i++)
    arr[i] = vector.arr[i];
   
  return *this;
} // operator= 

template <typename T>
size_t Vector<T>::find(const Vector<T>& vector) const
{
  int i, j;
 
  for(i = 0; i < count; i++)
  {

    if(arr[i] == vector.arr[ 0 ])
    {
      if(vector.count == 1)
         return (size_t) i;

      for(j = 1; j < vector.count; j++)
      {

         if(arr[i + j] != vector.arr[j])
           break;

         if(j == (vector.count - 1))
           return (size_t) i;
      } // for loop
    } // if statement
  } // for loop

  return (size_t) NPOS; // fail to locate specified string
} // find()

template <typename T>
Vector<T> Vector<T>::operator+= (const Vector<T>& vector)
{
  int i, j, newCount, newStorage;
  newCount = count + vector.count;
  
  if(newCount < (DOUBLE * storage))
     newStorage = DOUBLE * storage;
  
  else // else statement
    newStorage = newCount;

  T* tempArray = new T[newStorage];

  for(i = 0; i < count; ++i)
    tempArray[i] = arr[i];

  for(j = 0; j < vector.count; ++j)
    tempArray[i + j] = vector.arr[j];

  delete [] arr;
  arr = tempArray;
  storage = newStorage;
  count = newCount;
  return *this;

} // operator+= 

template <typename T>
Vector<T> Vector<T>::substr(int start, int length) const
{
  int end, i, j;
  T* tempArray;

  tempArray = new T[length + 1];
  tempArray[length] = 0;

  end  = start + length;
  
  for(i = start, j = 0; i < end; i++, j++)
    tempArray[j] = arr[i];

  Vector<T> ans(tempArray);

  delete [] tempArray;
  return ans;
} // substr()

template <typename T>
void Vector<T>::insert(const int start, const Vector<T>& vector)
{
  int tempLength = count + vector.count;
  T* tempArray = new T [tempLength + 1];
  int i, j, k;

  for(i = 0; i < start; ++i)
    tempArray[i] = arr[i];

  for(j = 0; j < vector.count; ++j)
    tempArray[i + j] = vector.arr[j];

  for(k = start; k < count; ++k)
    tempArray[j + k] = arr[k];

  tempArray[tempLength] = 0;

  int newStorage = storage;

  while ( newStorage < tempLength)
    newStorage *= DOUBLE;

  delete [] arr;
  arr = new T [newStorage];
  storage = newStorage;
  count = tempLength;

  for(int l = 0; l < tempLength + 1; ++l)
    arr[l] = tempArray[l];

  delete [] tempArray;
  
} // insert()

template <typename T>
void Vector<T>::replace(int start, int length, T* s, int subStart, int subLen)
{
  int newCount = count - length + subLen;
  int newStorage = storage;
  int i, j, k;

  if(newCount > storage)
  {
    if(newCount < DOUBLE * storage)
      newStorage = DOUBLE * storage;
   
    else // else statement
      newStorage = newCount;
  } // if statement

  T* tempArray = new T[newStorage];

  for(i = 0; i < start; ++i)
    tempArray[i] = arr[i];

  for(j = 0; j < subLen; ++j)
    tempArray[i + j] = s[j + subStart];

  for(k = start + length; k < count; ++k)
    tempArray[i + j + k - (start + length)] = arr[k];

  delete [] arr;
  arr = tempArray;
  storage = newStorage;
  count = newCount;
} // replace()

template <typename T>
Vector<T>::Vector(const Vector<T>& vector) 
{
  int i;
  count = vector.storage;
  storage = vector.count;
  arr = new T[count]; // creates new array
  
  for(i = 0; i < count; i++) // copy to new
     arr[i] = vector.arr[i];

} // Vector <T>
