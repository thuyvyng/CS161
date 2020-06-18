#include <iostream>
#include <stdio.h>
#include <stdbool.h> // hey uhm library
#include <string>
using namespace std;

int main() {
	string my_str;
	cout << "Please give a string without spaces: ";
	getline(cin,my_str); // this is wrong
	int length = my_str.length();
	bool flag = true;
	for(int i=0; i<(length/2); i++) {
		if (my_str[i] != my_str[(length-1)-i]) { //wrong here logic
			flag = false;	// wrong
		}	
	}
	if (flag == true) {
		cout << "It's a palindrome" << endl;	
	}
	else {
		cout << "It's not a palindrome" <<  endl;	// these are wrong bc >> <<
	}

	return 0;	
}
