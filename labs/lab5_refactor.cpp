#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float everything(string askquest) {

	float current_offer = 0, future_offer = 0, ir = 0, m = 1, n = 0, res, val, decimal;
	string input = "";
	int i, count;
	bool flag;

	do{
		cout << askquest;
		getline(cin, input);
		flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				if (input[i] == '.') {
					count++;
					if (count > 1) {
						flag = true;	
					}	
				}
				else {
					flag = true;
				}	
			} 	
		}
	} while (flag);
	
	for(i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			break;	
	}
	res = 0;
	val = 0;
	for(int j = i-1; j >= 0; j--) {
		val = ((int) input[j]) -48;
		res += val * pow(10, (i - 1 - j));
	}
	decimal = 0;
	count = 1;
	for(int k = i+1; k < input.length(); k++) {
		val = ((int) input[k]) - 48;
		decimal += val * pow(10, (-count));
		count++;
	}
//	cout << res << endl << decimal;	
	current_offer = res + decimal;



	return current_offer;
	}

float sup(){
	float n = 0;
	float res = 0;
	float val = 0;
	bool flag;
	string input = "";
	do{
		cout << "Please provide the amount of time in years between the current offer and future offer: ";
		getline(cin, input);
		flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				flag = true;	
			}
		}
	} while (flag);
	
	for(int i = (input.length()-1); i >= 0; i--) {
		val = ((int) input[i]) - 48;
		res +=  val * pow(10,(input.length() - i -1));
	}
	n = res;

	return n;
}

int main() {
	cout << "It looks like you have two offers. Let's calculate which one is worth more." << endl;
	float m = 1;

	float current_offer = everything("Please provide the current offer: ");
	cout << current_offer << endl;
	float future_offer = everything("Please provide the future offer: ");
	cout << future_offer << endl;
	float ir = everything("Please provide interest rate: ");
	cout << ir << endl;


	float num = sup();
	cout << num << endl;
//	cout << "sup bi" << endl;
	float val_current_offer = current_offer*(pow((1+(ir/m)),(num*m)));
//	cout << "vco" << val_current_offer << endl;	
	float val_future_offer = future_offer/(pow((1+(ir/m)), (num*m))); 
//	cout << "vfo" << val_future_offer << endl;

	//cout << "hellop" << endl;
		
	if (val_current_offer > val_future_offer) {
		cout << "Take the current offer" << endl;	
	}
	else if (val_current_offer < val_future_offer) {
		cout << "Take the future offer" << endl;	
	}	
	else {
		cout << "Choose which ever" << endl;	
	}


	return 0;	
}
