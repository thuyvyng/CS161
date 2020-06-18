#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int max_chars = 0;
	cout << "How many chars would you like? " << endl;
	cin >> max_chars;
	//cout << max_chars;
	char * mssg = new char[max_chars+1];
	cout << endl;
	int i = 0;
	cout << "Enter your input here: ";
	cin >> mssg;
	cout << endl;

	for(i = strlen(mssg); i >= 0; i--){
		cout << mssg[i];
	}
	cout << endl;
	delete [] mssg;
	return 0;
}
