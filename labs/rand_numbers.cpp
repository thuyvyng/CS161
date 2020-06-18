#include <iostream>
#include <ctime> 
#include <cstdlib>

using namespace std;

int main() {
	int x,b;
	srand(time(NULL));

	x = rand();
	b = x%6;

	cout << "x = " << b << endl;
	if (b == 0 ){

		cout << "Bummer, I'm zero!!!" << endl;
	}
	else if (b%2 ==1 ){
		cout << "I'm an odd number!" << endl;

		}
	else {
		cout <<	"I'm an even number!" << endl;
	}
	return 0;
}
