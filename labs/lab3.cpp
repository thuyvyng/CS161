//Password Generator Assignment 1/25/18
//
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main(){
	int p_length = 0;
	int x;
	int answer = 1;
	srand(time(NULL));
	x = rand();
	while( answer != 0){
	string password = "";


	cout << "How long do you want your password to be? " << endl;
	cin >> p_length;

	cout << "Do you want to have uppercase letters in your password? 0 for no, 1 for yes. " << endl;
	int up_q = 0;
	cin >> up_q;
	if (up_q == 1){
		cout << "How many uppercase letters do you want? " << endl;
		int up_amnt = 0;

		cin >> up_amnt;

		for (int i = 0; i < up_amnt; i++){
			//char b;
			//b = (char)(x%25 + 60);
			//password += b;
			password += (char)(rand()% 25 + 65);
			// here add numbers to lower ascii value by adding b and append each letter for how many values they want	
	//		cout << password << endl;
		}


	}
	
	cout << "Do you want to have lowercase in your password? 0 for no, 1 for yes." << endl;
	int lw_q = 0;
	cin >> lw_q;
	if (lw_q == 1){
		cout << "How any uppercase letters do you want? " << endl;
		int lw_amnt = 0;
		
		cin >> lw_amnt;
		
		for (int w = 0; w < lw_amnt; w++){
		//	int z;
		//	z = x%25;
			// here add numbers to lower ascii value and apend
		password += (char)(rand()% 25 + 97);
	//	cout << password << endl;
		} 
	}	

	cout << "Do you want to have numbers in your password? 0 for no, 1 for yes. " << endl;
	int num_q = 0;
	cin >> num_q;
	if (num_q == 1){
		cout << "How many numbers do you want?" << endl;
		int num_amnt = 0;

		cin >> num_amnt;

		for (int l = 0; l < num_amnt; l++){
		//	int o;
		//	o = x%10;
			//how to append to each other
			password += (char)(rand()%10 + 48);
		//	cout << password << endl;
			}
	}
	

	//append all variables together


	cout << password << endl;
	cout << "do you wanna do it again. 0 for no 1 for yes" << endl;

	cin >> answer;




	}	
	return 0;
}
