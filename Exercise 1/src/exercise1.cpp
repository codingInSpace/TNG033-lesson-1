#include "../header/exercise1.h"
#include <new>
#include <math.h>

void create_vector(Vector &V, int n){

	V.p = new (nothrow) double[n];

	if(!V.p){
		cout << "no memory" << endl;
		V.p = 0;
	}

	else{
		V.cols = n;
		for (int i = 0; i < n; ++i){
			V.p[i] = 0.0;
		}
	}
}

//Deallocate space occupied by Vector
//V = empty vector
void empty_vector(Vector &V){
    V.cols = 0;

    delete [] V.p; //deallocate memory

    V.p = nullptr;
}

//Assuming V not empty, return value stored in column col
double get(const Vector &V, int col){
    return V.p[col];
}

//Store value d in comumn col
void set(Vector &V, int col, double d){
    V.p[col] = d;
}


//Calculate and return length of vector
double length(const Vector &V){
	double lInitial = 0.0;
	double lFinal = 0.0;

	for (int i = 0; i < V.cols; ++i){
		lInitial += pow(V.p[i], 2);	//other way around?
	}

	lFinal = sqrt(lInitial);

	return lFinal;

}

//Display Vector V to stream out
ostream& operator<<(ostream& out, const Vector &V){
    cout << "(<";

    for(int i = 0; i < V.cols; i++){
    	out << setw(5) << fixed << setprecision(2)
    		<< get(V,i) << " ";
    }
    

    cout << ">)";

    return out;
}


//Read Vector V from stream in
istream& operator>>(istream& in, Vector &V){



/*
    for(int i = 0; i < V.cols; i++){
		in >> V.p[i];

		if(i == V.cols)
    }
	
    return in;
*/
}