#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void get_string(string *a){
	cout << "Please input a string: " << endl;
	getline(cin, *a);

	}

void set_replace_string(string original, string * hidden){
	*hidden = original;
	for ( int i = 0; i < original.length(); i++){
		if ( (original[i] > 32) && (original[i] < 127) ){
			(*hidden)[i] = '-';
		}
	}
}

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
int main(){
	string original = "";
	string hidden = "";
	

	get_string(&original);
	set_replace_string(original, &hidden);
	char chardummy;
	cout << "Please input a character: " << endl;
	cin >> chardummy;
//	get_replace(chardummy, original, &hidden);	
	set_replace_string(original, &hidden);
	cout << "There were " << get_search_replace(chardummy,original,hidden) << " " << chardummy << "in your string" << endl;

	cout << "original = " << original << endl;
	cout << "hidden = " <<  hidden << endl;
	return 0;
}
