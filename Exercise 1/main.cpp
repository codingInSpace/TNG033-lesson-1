#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Vector{
	int cols;		//number of coordinates, cols
	double *p;		//pointer to vector
};

//Create a vector with n columns
//Allocate an array
void create_vector(Vector &V, int n = 0);

//Deallocate space occupied by vector
//V = empty vector
void empty_vector(Vector &V);

//Assuming V not empty, return value stored in column col
int get(const Vector &V, int col);

//Store value d in comumn col
void set(Vector &V, int col, double d);

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
	
	char answer;

	while(true){

		cout << "\nNumber of coordinates?";
		cin >> cols;

		create_vector(V, cols);

		cout << "\nEnter coordinates: ";
		cin >> V;

		cout << "\nVector: ";
		cout << V;

		cout << "\nContinue? (y/n): ";
		cin >> answer;

		if(answer == 'n'){
			break;				//exit loop
		}
		
		empty_vector(V);	//deallocate memory
	}

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
	else{
		V.cols = n;						//set columns
		V.p = new (nothrow) double [n];	//Allocate memory, return nullptr if unsuccessful
	}

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

//Assuming V not empty, return value stored in column col
int get(const Vector &V, int col){
    return V.p[col];
}

//Store value d in comumn col
void set(Vector &V, int col, double d){
    V.p[col] = d;
}


//Calculate and return length of vector
double length(const Vector &V){
	return 0.0;

}

//Display Vector V to stream out
ostream& operator<<(ostream& out, const Vector &V){
    cout << "(<-";

    for(int i = 0; i < V.cols; i++){
    	out << setw(4) << fixed << setprecision(2)
    		<< get(V,i) << " ";
    }
    

    cout << "->)" << endl;

    return out;
}


//Read Vector V from stream in
istream& operator>>(istream& in, Vector &V){
    for(int i = 0; i < V.cols; i++)
		in >> V.p[i];
	
    return in;
}