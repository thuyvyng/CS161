#include <iostream>

using namespace std;

void woo( int * x){
	(*x)++;
}


int main(){
	int *w;
	int whatever = 9;
	w = &whatever;

	
	cout << "w before: " << *w << endl;
	
	woo(w);

	cout << "w after: " << *w << endl;

	return 0;
}
