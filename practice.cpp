#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){

	cout << "Wassup my dudes!!!" << endl;
	
	int x = 6;
	int* values = new int[x];

	for (int i = 0; i < x; i++){
		values[i] = rand()%2;
	}

	cout << "OG Table" << endl;
	for (int i = 0; i < x; i++){
		cout << values[i] << " " << endl;
	}

	cout << endl;

	int * histogram = new int[x];

	for (int i = 0; i < x; i++){
		histogram[i] = 0;
	}

	for (int i = 0; i <x ; i++){
		histogram[values[i]]++;
	}

	for (int i = 0; i < x; i++){
		cout << values[i] << " = " << histogram[i] << " " << endl;
	}



	return 0;
}
