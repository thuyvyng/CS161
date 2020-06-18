// Calculate the size of things
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main(){

	int user_answ = 0;

	cout << "Insert number:  ";

	cin >> user_answ;
	int user_ans;

	user_ans = user_answ*8;

	double max_num_unsigned, max_num_sign_one,max_num_sign, max_value_unsigned, max_value_signed;
	max_num_unsigned = pow(2,user_ans);
	max_num_sign_one = user_ans -1;
	max_num_sign = pow(2,max_num_sign_one);

	max_value_unsigned = pow(2,user_ans)-1; // good
	max_value_signed = max_num_sign -1; //good
	double min_unsigned, min_signed;
	min_unsigned = 0;
	min_signed = -1*max_num_sign;

	cout << "Max value unsigned = " << max_value_unsigned << endl;
	cout << "Max value signed = " << max_value_signed << endl;
	cout << "Min value signed  = " << min_signed << endl;
	cout << "Min value unsigned = " <<  min_unsigned << endl;




//	cout << "You answered: " << user_ans << endl;


	return 0;
}













