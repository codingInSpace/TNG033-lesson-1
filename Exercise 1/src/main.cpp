#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <math.h>

#include "exercise.h"
#include <new>

using namespace std;

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

		cout << "\nLength: " << length(V);

		cout << "\nContinue? (y/n): ";
		cin >> answer;

		if(answer == 'n')
			break;			//exit loop
		
		empty_vector(V);	//deallocate memory every iteration
	}

	return 0;
}