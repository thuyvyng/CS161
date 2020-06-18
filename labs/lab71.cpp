#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void get_string(char* mssg){
	cout << "please input a string: " << endl;

	cin.getline(mssg,256);
//	cout << "user input = " << mssg << endl;
} 

/*
void set_replace_string(string original, string * hidden){
	*hidden = original;
	for ( int i = 0; i < original.length(); i++){
		if ( (original[i] > 32) && (original[i] < 127) ){
			(*hidden)[i] = '-';
		}
	}
}

*/

void set_replace_string(char* mssg, char* other){

	for (int i = 0; i < sizeof(mssg); i++){
		if (( mssg[i]>32) && (mssg[i] <127)){
			other[i] = '-';
		}
	}
	cout << "other = " <<  other << endl;
}

/*
int get_search_replace(char chardummy, string original, string & hidden){
	int end = 0;
	for (int i = 0; i < original.length(); i++){
		cout << i << endl;
		if (original[i] == chardummy){
			end = end + 1;
			hidden[i] = chardummy;			
		}
	}
	return end;
}
*/
int get_search_replace(char* mssg, char* other){
	char chardummy;
	cout << "please input a character: " << endl;
	cin >> chardummy;
	int end = 0;
	for (int i = 0; i < sizeof(mssg); i++){
		if (mssg[i] == chardummy){
			end = end + 1;
			other[i] = chardummy;			
		}
	}
	cout << "mssg =" << mssg << endl << "other = " << other << endl;
	return end;
}


int main(){	
	char mssg[256];
	char other[256];
	get_string(mssg);
	
	set_replace_string(mssg, other);

/*
	set_replace_string(original, &hidden);
*/

//	char chardummy;
//	cout << "Please input a character: " << endl;
//	cin >> chardummy;
//	set_replace_string(mssg, other);
	cout << mssg << endl << other << endl;
	cout << "there are " << get_search_replace(mssg,other) << "in your string" << endl;

	cout << "original = " << mssg << endl;
	cout << "hidden = " <<  other << endl;
	return 0;
}
