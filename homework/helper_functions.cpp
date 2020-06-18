#include <iostream>
#include "helper_functions.h"
#include <string>
#include <cmath>

using namespace std;
/*-------------------------------------------------------------------
 * Function: check_range
 * Description: This function checks if a value is in range of two other values. 
 * Parameters: Does not work for floats, or anything not specifically int. Only accepts ints.
 * Pre-Conditions: Input three ints.
 * Post-Conditions: Either a yes or no, to indicate whether the value was inbetwe.
 **********************************************************************/
bool check_range( int lower_bound, int upper_bound, int test_value) {
	bool range = 0;

	if ((lower_bound < test_value) && (test_value < upper_bound)){
		range = 1;
	}
	return range;
}
/**********************************************************************
 * Function: is_int
 * Description: This function will output whether the input is an int or no.
 * Parameters: Says whether the input is an int not a number, so no floats.
 * Pre-Conditions: Input any value
 * Post_Conditions: Either a yes or a no (1 or 0) to indicate whether the input was an int or not
 * *********************************************************************/

bool is_int(string num){
	bool c_num = 0;
	int len = 0;
	int l = num.length();

	while(num[len] != '\0'){
		if(((num[len]> 47) && (num[len] < 58)) || (num[len] == 45 )){
			len++;
		}
		else{
			break;
		}
	c_num = 1;
	}

	return c_num; 
}
/************************************************************************
 * Function: is_capital
 * Description: Takes in a single character anf will say yes or no if the character os capitalized or not
 * Parameters: Did not test on any non letters (ABC).
 * Pre-conditions: Takes a single input from the user.
 * Post-conditions: Outputs 1 or 0 correspondingly
 * *********************************************************************/

bool is_capital(char letter){
	bool end = 0;
	int i = 0;

	if((letter > 64) && (letter < 91)){
		end = 1;
	}
	return end;
}

/************************************************************************8
 * Function: is_float
 * Descriptions: Takes in input from the user and will output whether or not the output was a float or not
 * Parameters: Didn't really try negatives or funky floats such as 00000000.00087 or how precise it was.
 * Pre-conditions: Takes a single input from a user.
 * Post-conditions: Outputs a 1 or 0 correspondingly
 * *****************************************************************/

bool is_float(string num){
	bool flo = 0;
	bool end = 0;
	int len = 0;
	int i = 0;
	int dec = 0;
	
	while(num[i] != '\0'){
		if (((num[i] > 47) && (num[i] < 58)) || (num[i] == 45) || (num[i] == 46) ){
			i++;
		}
		else{
			break;
		}

	flo = 1;
	}
	
	while (num[len] != '\0'){
		if (num[len] == 46){
			++dec;
			++len;
		}
		else{
			++len;
		}
	}
	if ((flo == 1) && (dec == 1)){
		end = 1;
	}
	return end;
}
/*********************************************************************8
 * Function: is_even
 * Descriptions: Takes an input from the user and will output whether or not the int provided is even or not
 * Parameters:  DId not handle bad user input so it would take non ints. Did not try negatives.
 * Pre-Conditions: Takes a single input from the user that is an int.
 * Post-conditions: Yes or a no (1 or 0)
 * **************************************************************************/
bool is_even(int num){
	bool end = 0;
	int res =  (num%2);

	if (res == 0){
		end = 1;
	}

	return end;
}

/*********************************************************************8
 * Function: is_odd
 * Descriptions: Takes an input from the user and will output whether or not the int provided is odd or not
 * Parameters:  DId not handle bad user input so it would take non ints. Did not try negatives.
 * Pre-Conditions: Takes a single input from the user that is an int.
 * Post-conditions: Yes or a no (1 or 0)
 * **************************************************************************/
bool is_odd(int num){
	bool end = 0;
	int res = num%2;
	
	if (res == 1){
		end = 1;

	}
	return end;
}
/*********************************************************************************8
 * Function: to_upper
 * Descriptions: Will capitalize all lowercase letters in a string
 * Parameters: Did not try long sentences or anything. 
 * Pre-conditions: Strings
 * Post-conditions: Same string but all uppercase letters are now lowercase
 * *********************************************************************************/
string to_upper(string sentence){
	bool end = 0;
	int i = 0;

	while(sentence[i] != '\0'){
		if ((sentence[i] > 96) && (sentence[i] < 123)){
			sentence[i] = sentence[i]-32;
			++i;
			}
		else{
			++i;
		} 
	}

	return sentence;
}

/*********************************************************************************8
 * Function: to_lower
 * Descriptions: Will lowercase all capitalized  letters in a string
 * Parameters: Did not try long sentences or anything. 
 * Pre-conditions: Strings
 * Post-conditions: Same string but all lowercase letters are now uppercase
 * *********************************************************************************/
string to_lower(string sentence){
	bool end = 0;
	int i = 0;

	while(sentence[i] != '\0'){
		if ((sentence[i]> 64) && (sentence[i] < 91)){
			sentence[i] = sentence[i]+32;
			++i;
		}
		else{
			++i;
		}
	}
	return sentence;
}

/******************************************************************************
 * Function: equality_test
 * Description: Tests the relationship between two ints.
 * Parameters: Only checked with positive ints
 * Pre-conditions: Two ints
 * Post-conditions: will output either -1, 0, 1 depending on the relationship between the two ints
 * ***************************************************************************/
int equality_test( int num1, int num2){
	int end = 10;

	if ( num1 == num2){
		end = 0;
	}
	else if ( num1 < num2 ){
		end = -1;
	}
	else if (num1 > num2){
		end = 1;
	}
	
	return end;
}

/****************************************************************************************************
 * Function: float_is_equal
 * Description: Determines if two floats are within a certain precision of each other
 * Parameters: Did not check negatives
 * Pre-conditions: 3 floats
 * Post-conditions: a boolean value indicating whether or not the boolean was true
 * ****************************************************************************************************/
bool float_is_equal(float num1, float num2, float precision){
	bool end = 0;
//	cout << num1 << endl << num2 << endl << precision;
	float x = (num1 - num2);
	float w = (num2 - num1);

//	cout << x << endl << w << endl;
	if (num1 == num2){
		end = 1;
	}
	
	if (num1 > num2){
		if (x < precision){
			end = 1;
			}
		}
	else if (num2 > num1){
		if (w < precision){
			end = 1;
		}
	}
	return end;

}

/************************************************************************************************
 * Function: numbers_present
 * Description: Determines if in a given string has any numbers present.
 * Parameters: Did not try weird sentences
 * Pre-conditions: String given
 * Post-conditions: A boolean value indicated whether or not there were any numbers presents
 * *************************************************************************/
 
 bool numbers_present(string sentence){
	bool end = 0;
	int i = 0;

	while (sentence[i] != '\0'){
		if ((sentence[i] > 47) && (sentence[i] < 58)){
			end = 1;
			break;
		}

		else{
			i++;
		}

	}
}
/**********************************************************************************************************

 * Function: letters_present
 * Description: Determines if in a given string has any letters present.
 * Parameters: Did not try weird sentences but it works for lowercase and uppercase
 * Pre-conditions: String given
 * Post-conditions: A boolean value indicated whether or not there were any letters presents
 * *************************************************************************/
bool letters_present(string sentence){
	bool end = 0;
	int i = 0;
	
	while (sentence[i] != '\0'){
		if (((sentence[i] > 96) && (sentence[i] <123)) || ((sentence[i] > 64) && (sentence[i] <91))){
			end = 1;
			break;
		}
		else{
			i++;
		}

	}
	return end;
}


/**************************************************************************************
 * Function: word_count
 * Description: counts how many words are in a sentence
 * Parameters: did not factor in if user put in bad input and put two spaces as one
 * Pre-Conditions: string given
 * Post-conditions: int of how many words there was
 * ******************************************************************************************/
int word_count(string sentence){
	int i = 0;
	int space = 0;

	while(sentence[i] != '\0'){
		if (sentence[i] == 32){
			space++;
			i++;
		}
		else{
			i++;
		}
	}

	space = space+1;

	return space;
		
}
/**********************************************************************************************
 * Function: contains_substring
 * Description: determines whether one string has another string inside of it
 * Parameters: Did not factor in spaces or long sentences or whether not the bigger string had the smaller one more than once
 * Pre-conditions: two strings
 * Post-conditions: boolean value saying whether the condition was met
 *****************************************************************************************************/
bool contains_substring(string sentence, string sub_sentence){
	int i = 0;
	int x = 0;
	bool end = 0;

	while(sentence[i] != '\0'){
		if (sentence[i] == sub_sentence[x]){
			i++;
			x++;
			if (x == sub_sentence.length()){
				end = 1;
			}
			}
		else{
		i++;
		}
	}
	return end;
}
/*******************************************************************************
 * Functions: pass_or_fail, woo, last
 * Descriptions: Checking if said functions work
 * Parameters: Doesn't really work for the get int/or float because we dont have an expected value
 * Pre-conditions: Expected value stated in the testing and the actia value provided by the function:
 * Post-conditions: hopefully a pass
 * ****************************************************************/
string pass_or_fail(bool expected, bool comparison){
	string end = "FAIL";

	if (expected == comparison) {
		end = "PASS";
		}

	return end;

}

string woo(string expected, string comparison){
	string end = "FAIL";

	if (expected == comparison){

		end = "PASS";
	}
	return end;

}

string last(int expected, int comparison){
	string end = "FAIL";

	if (expected == comparison){

		end = "PASS";

	}
	return end;

}


/***************************************************************************************************
 * Functions: get_bin, get_bin2
 * Description: taking in user input for the get functions and then respectively checking if they are valid input
 * Parameters: Does not perfectly check input like for how precise for floats and i did not check negatives
 * Pre-conditions: statement asking for inpit
 * Post: checking if the input is valid (an int or string)
 ***********************************************/
string get_bin() {
	string bin = "";

	do{
		cout << "Insert a number";
		getline(cin,bin);
	} while(is_int(bin) == 0);
	return bin;
}

string get_bin2() {

	string bin = "";
	do{
		cout << "Insert string to convert to float: ";
		getline(cin,bin);
	} while(is_float(bin) == 0);
	return bin;
}

/*******************************************************************************
 * Function: get_int, get_float
 * Description: If the input was said to be an int or a float then this will convert the string to the int/float
 * Parameters: Not very precise, doesn't work with negatives
 * Pre-Conditions: Taking user input for a string
 * Post-Conditions: A string or float respectively
 * ************************/
int get_int (string bin){
	int res = 0;

	for ( int i = 0;i < bin.length(); i++){
		int check = bin[i]- '0';
//		int check2  = pow(10,bin.length()-i-1);
		res = (check*pow(10,bin.length()-i-1)) + res;

//		cout << check << check2 << res << endl << endl << endl;
	}
	return res;
}

float get_float (string bin){
	float res = 0;
	int temp = 0;
	int check = 0;
	int i = 0;
	int w = 0;
	while (	bin[i] != '.'){

		check = bin[i]- '0';
		res = (check*pow(10,bin.length()-i-1)) + res;
		i++;
		}
	i = i+1;

	while ( i < bin.length()){
		check = bin[i] - '0';
		res = (check*pow(10,bin.length()-i))+res;
		i++;
		w++;

	}
	float y = res/(pow(10,w+1));	
	//cout << w << endl;
	return y;
}
