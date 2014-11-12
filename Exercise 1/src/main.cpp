#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>

#include "../header/exercise1.h"
//#include "exercise1.cpp"
//#include <new>

using namespace std;

int main(){
	Vector V;
	int cols = 0;
	
	char answer;

	while(true){

		//create_vector(V, cols);		//allocate memory

		cout << "\nNumber of coordinates: ";
		cin >> cols;

		create_vector(V, cols);

		cout << "\nEnter coordinates: ";
		cin >> V;

		cout << "\nLength of " << V << ": " << length(V);

		cout << "\nContinue? (y/n): ";
		cin >> answer;

		if(answer == 'n'){
			empty_vector(V);	//deallocate memory every iteration
			break;				//exit loop
		}
		
		empty_vector(V);	//deallocate memory every iteration
	}

	return 0;
}