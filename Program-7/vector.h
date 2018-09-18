#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class Vector;

template <typename T>
ostream& operator<< (ostream& os, const Vector<T>& vector);

template <typename T>
class VectorIterator 
{
  static const int NPOS = -1;

  const Vector<T> * vectorPtr;
  int position;

public:
  VectorIterator(const Vector<T> *ptr = NULL, int pos = 0);
  const T& operator*() const;
  void operator++(int);
  bool operator!=(const VectorIterator<T> & rhs) const;
}; // VectorIterator

template <typename T>
class ReverseVectorIterator 
{ 
  static const int NPOS = -1;
  const Vector<T> * vectorPtr;
  int position;

public:
  ReverseVectorIterator(const Vector<T> *ptr = NULL, int pos = 0);
  const T& operator*() const;
  void operator++(int);
  bool operator!=(const ReverseVectorIterator<T> & rhs) const;
}; // ReverseVectorIterator

template <typename T>
class Vector
{
  static const int DOUBLE = 2;
  static const int NPOS = -1;

  int storage;
  int count;
  T* arr;

public:
  const int size() const;
  const int capacity() const;
  Vector();
  ~Vector();
  Vector(const T* array);
  Vector(const Vector<T>& vector);
  size_t find(const Vector<T>& vector) const;
  Vector<T> substr(const int start, int length) const;
  void insert(int start, const Vector<T>& vector);
  void replace(int start, int length, T* s, int subStart, int subLen);
  Vector<T> operator= (const Vector<T>& vector);
  Vector<T> operator+= (const Vector<T>& vector);
  friend ostream& operator<< <T> (ostream& os, const Vector& vector);

  friend class VectorIterator<T>;
  friend class ReverseVectorIterator<T>;

  typedef VectorIterator<T> iterator;
  typedef ReverseVectorIterator<T> reverse_iterator;
  VectorIterator<T> begin() const;
  VectorIterator<T> end() const;
  ReverseVectorIterator<T> rbegin() const;
  ReverseVectorIterator<T> rend() const;

}; // Vector

#include "vector.cpp"

#endif // VECTOR_H
