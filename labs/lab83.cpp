#include <iostream>
//#include <string>
#include <cstring>
using namespace std;

void get_string(char* mssg, int max_chars){
	cout << "please input a string: " << endl;
	int what = max_chars +1;
	cin.ignore();
	cin.getline(mssg,what);
	cout << mssg << endl;
} 


void set_replace_string(char* mssg, char* other){
//	cout << strlen(mssg);

	for (int i = 0; i < strlen(mssg); i++){
		if (( mssg[i]>32) && (mssg[i] <127)){
			other[i] = '-';
		}
		else{
			other[i] = ' ';
		}

	}
	cout << "other = " <<  other << endl;
}

int get_search_replace(char* mssg, char* other){
	char chardummy;
	cout << "please input a character: " << endl;
	cin >> chardummy;
	int end = 0;
	for (int i = 0; i < strlen(mssg); i++){
		if (mssg[i] == chardummy){
			end = end + 1;
			other[i] = chardummy;			
		}
	}
	cout << "mssg =" << mssg << endl << "other = " << other << endl;
	return end;
}

int main(){
	int max_chars = 0;
	cout << "How many chars do you want?";
	cin >> max_chars;
	
	char * mssg = new char[max_chars + 1];
	char * other = new char[max_chars + 1];
	cout << endl;
	
	
		
	//char mssg[256];
	//char other[256];
	get_string(mssg, max_chars);
	
	set_replace_string(mssg, other);

	cout << mssg << endl << other << endl;
	cout << "there are " << get_search_replace(mssg,other) << "in your string" << endl;

	cout << "original = " << mssg << endl;
	cout << "hidden = " <<  other << endl;

	delete [] mssg;
	delete [] other;
	return 0;
}
