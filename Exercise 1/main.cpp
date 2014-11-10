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
int get(const Vector &V);

//Set number of columns
void set(Vector &V, int i);

//Display Vector V to stream out
ostream& operator<<(ostream& out, const Vector &V);

//Read a Vector V from stream in
istream& operator>>(istream& in, Vector &V);

//Calculate and return length of vector
double length(const Vector &V);


/*******MAIN*********/

int main(){
	Vector V;
	int cols = 0;
	create_vector(V, cols);

	cout << "\nNumber of coordinates?";
	cin >> cols;

	set(V, cols);

	cout << "\nEnter coordinates: ";
	cin >> V;

	cout << "\nVector: ";
	cout << V;

	return 0;
}

/********************/


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

//Deallocate space occupied by Vector
//V = empty vector
void empty_vector(Vector &V){
    V.cols = 0;

    delete [] V.p; //deallocate memory

    V.p = nullptr;
}

//Assuming V not empty, return number of columns
int get(const Vector &V){
    return V.cols;
}

//Store value v in line i and column j of M, i.e. M[i,j] = v
void set(Vector &V, int n){
    V.cols = n;
}

//Calculate and return length of vector
double length(const Vector &V){
	return 0.0;

}