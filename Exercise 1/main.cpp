#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Vector{
	int cols;		//number of coordinates, cols
	int *p;		//pointer to vector
};

//Create a vector with n columns
//Allocate an array
void create_vector(Vector &V, int n = 0);

//Deallocate space occupied by vector
//V = empty vector
void empty_vector(Vector &V);

//Assuming V not empty, return number of columns
int get(const Vector &V, int i);

//Set number of columns
void set(Vector &V, int i);

//Display Vector V to stream out
ostream& operator<<(ostream& out, const Vector &V);


//Read a Vector V from stream in
istream& operator>>(istream& in, Vector &V);

int main(){


	return 0;
}

void create_vector(Vector &V, int n){

	//create empty vector
	if(!n){
		V.cols = 0;
		V.p = nullptr;
		return;
	}
	//else?

	V.cols = n;						//set columns
	V.p = new (nothrow) int [n];	//Allocate memory, return nullptr if unsuccessful

	if(!V.p)	//if not possible
		V.cols = 0;

	cout << "Vector created.\n";
}
