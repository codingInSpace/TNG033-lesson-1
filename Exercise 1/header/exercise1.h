#ifndef EXERCISE1_H_INCLUDED
#define EXERCISE1_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <math.h>

//#include "../src/exercise1.cpp"

using namespace std;

struct Vector{
	int cols;		//number of coordinates, cols
	double *p;		//pointer to vector
};

//Create a vector with n columns
//Allocate an array
void create_vector(Vector &V, int n);

//Deallocate space occupied by vector
//V = empty vector
void empty_vector(Vector &V);

//Assuming V not empty, return value stored in column col
double get(const Vector &V, int col);

//Store value d in comumn col
void set(Vector &V, int col, double d);

//Display Vector V to stream out
ostream& operator<<(ostream& out, const Vector &V);

//Read a Vector V from stream in
istream& operator>>(istream& in, Vector &V);

//Calculate and return length of vector
double length(const Vector &V);

#endif // EXERCISE1_H_INCLUDED