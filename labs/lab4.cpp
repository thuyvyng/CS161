/********************************************************
 * Function: a_to_i
 * Description: turns a character into a decimal value
 * Parameters: char character
 * Pre-conditions: the input is a character
 * Post- conditions: returnedthe decimal value of the character
 * ******************************************************/

#include <iostream>
#include <string>
using namespace std;

int a_to_i(char user){
	int end = 0;
	if ((user > 47) && (user < 58)){
		end = (int)(user-48);
	}
	return end;


}	

char i_to_a(int other){

	char end = (char)other;

	return end;





}
int main(){
	char user = ' ';
	cout << "Input your character" << endl;
	cin >> user;

	cout << a_to_i(user) << endl;

	int other = 0;
	cout << "Input your number" << endl;
	cin >> other;

	cout << i_to_a(other) << endl;



	return 0;
}
