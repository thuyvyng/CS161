/***********************************************************************
 Function: Assignment 3
 Author: Thuy-Vy Nguyen
 Description: Designing functions for error handling
 **********************************************************************/

#include <iostream>
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
		cout << "Insert string to convert to int: ";
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
int main() {

	cout << endl <<"Testing check_range (lower_bound, upper_bound, test_value)" << endl << "0 is false, 1 for true" << endl << endl; //check_range

		bool rangeGood = check_range(1,10,5);
		cout << "	Value: (1,10,5)" << endl;
		cout << "		Expected: 1" << endl;
		cout << " 		Actual: " << rangeGood << endl;
		cout << "		" << pass_or_fail(1,rangeGood) << endl << endl;

		bool rangeBad = check_range(-100,50,70);
		cout << "	Value: (-100,50,70) " << endl;
		cout << " 		Expected: 0" << endl;
		cout << "		Actual : " << rangeBad << endl;
		cout << "		" << pass_or_fail(0,rangeBad) << endl << endl;

	cout << endl << "Testing is_int" << endl << "0 is false, 1 is for true" << endl << endl; //is_int
	
		bool numGood = is_int("100");
		cout << "	Value:  '100'" << endl;
		cout << "		Expected: 1 " << endl;
		cout << "		Actual : "  << numGood << endl;
		cout << "		" << pass_or_fail(1,numGood) << endl << endl;

		bool numBad = is_int("bad");
		cout << "	Value: 'hello' " << endl;
		cout << "		Expected: 0" << endl;
		cout << "		Actual: " << numBad << endl;
		cout << "		" << pass_or_fail(0,numBad) << endl << endl;

	cout << endl << "Testing is_float" << endl << "0 is false, 1 is true" << endl << endl; //is_float
	
		bool floatGood = is_float("3.96");
		cout << "	Value: 3.96 " << endl;
		cout << "		Expected: 1" << endl;
		cout << "		Actual: " <<  floatGood << endl;
		cout << "		" << pass_or_fail(1,floatGood) << endl << endl;
	
		bool floatBad = is_float("8");
		cout << "	Value: 8  " << endl;
		cout << "		Expected: 0 " << endl;
		cout << "		Actual: " << floatBad << endl;
		cout <<	"		" << pass_or_fail(0,floatBad) << endl << endl;

	cout << endl << "Testing is_capital" << endl << "O is false, 1 is true" << endl << endl; // is_cap				

		bool capAP = is_capital('A');
		cout << "	Value: A " << endl;
		cout << "		Expected: 1" << endl;
		cout << "		Actual: " << capAP << endl;
		cout << "		" << pass_or_fail(1,capAP) << endl << endl;

		bool capBP = is_capital('a');
		cout << "	Value : a = " << endl;
		cout << "		Expected: 0 " << endl;
		cout << "		Actual: "  << capBP << endl;	
		cout << "		" << pass_or_fail(0,capBP) << endl << endl;

	cout << endl << "Testing is_even" << endl << "0 is false, 1 is true" << endl << endl; //is_even
		
		bool evenA = is_even(8);
		cout << "	Value: 8 = " << endl;
		cout << "		Expected: 0" << endl;
		cout << "		Actual: " << evenA << endl;
		cout << " 		" << pass_or_fail(1,evenA) << endl << endl;


		bool evenB = is_even(177);
		cout << "	Value: 177" << endl;
		cout << "		Expected: 1 " << endl;
		cout << "		Actual: " << evenB << endl;
		cout << "		" << pass_or_fail(0,evenB) << endl << endl;


	cout << endl << "Testing is_odd" << endl << "0 is false, 1 is true" << endl << endl; //is_odd

		bool oddA = is_odd(9);
		cout << "	Value: 9 " << endl;
		cout << "		Expected: 1 " << endl;
		cout << "		Actual: " << oddA << endl;
		cout << "		" << pass_or_fail(1,oddA) << endl << endl;

		bool oddB = is_odd(24);
		cout << "	Value: 24  " << endl;
		cout << "		Expected: 0" << endl;
		cout << "		Actual: " << oddB << endl;
		cout << "		" << pass_or_fail(0,oddB) << endl << endl;

	cout << endl << "Testing to_upper"  << endl; //to_upper
		string capitalizeGood = to_upper("Good");
		cout << "	Value: Good " << endl;
		cout << "		Expected: GOOD" << endl;
		cout << "		Actual: " <<  capitalizeGood << endl; 
		cout << "		" << woo("GOOD", capitalizeGood) << endl << endl;

		string capitalizeBad = to_upper("Hello987");
		cout << "	Value: Hello987 " << endl;
		cout << "		Expected: HELLO987 " << endl;
		cout << "		Actual: " << capitalizeBad << endl;
		cout << "		" << woo("HELLO987",capitalizeBad) << endl << endl;
	
	cout << endl << "Testing to_lower" << endl; //to_lower
		string lowLOW = to_lower("HOLY CRAP");
		cout << "	Value: HOLY CRAP  " << endl;
		cout << " 		Expected: holy crap" << endl;
		cout << "		Actual: " <<  lowLOW << endl;
		cout << " 		" << woo("holy crap",lowLOW) << endl << endl;


		string low_l = to_lower("911POLICE");
		cout << "	Value: 911POLICE = " << endl;
		cout << "		Expected: 911police" << endl;
		cout << "		Actual: " <<  low_l << endl;
		cout << "		" << woo("911police",low_l) << endl << endl;

	cout << endl << "Testing equality_test (num1, num2) " << endl << "0 if num1 = num2, -1 if num2 is greater, 1 if num1 is greater" << endl << endl; //equality_test
		int eqT1 = equality_test(100,100);
		cout << "	Value: (100,100)" << endl;
		cout << "		Expected: 0" << endl;
		cout << "		Actual: " << eqT1 << endl;
		cout << "		" << pass_or_fail(0,eqT1) << endl << endl;

		int eqT2 = equality_test(100,11);
		cout << "	Value: (100,11)  " << endl;
		cout << "		Expected: 1" << endl;
		cout << "		Actual: " << eqT2 << endl;
		cout << "		" << pass_or_fail(1,eqT2) << endl << endl;
		
	cout << endl << "Testing float_is_equal (num1, num2, precision)" << endl << "0 is false, 1 is true" << endl << endl; //float_is_equal p
		bool fl1 = float_is_equal(9.8,9.6, 1.3);
		cout << "	Value: (9.8, 9.6, 1.3) " << endl;
		cout << "		Expected: 1" << endl;
		cout << "		Actual: " << fl1 << endl;
		cout << "		" << pass_or_fail(1,fl1) << endl << endl;

		bool fl2 = float_is_equal(9.8, 9.0, 0.3);
		cout << "	Value: (9.8,9.0,0.3) " << endl;
		cout << "		Expected: 0" << endl;
		cout << "		Actual: " << fl2 << endl;
		cout << "		" << pass_or_fail(0, fl2) << endl << endl;						

	cout << endl << "Testing numbers_present" << endl << "0 is false, 1 is true" << endl << endl;
		bool np1 = numbers_present("Hello12345"); 
		cout << "	Value: Hello12345  " << endl;
		cout << "		Expected: 1" << endl;
		cout << "		Actual: " << np1 << endl;
		cout << "		" << pass_or_fail(1, np1) << endl << endl;

		bool np2 = numbers_present("Bye");
		cout << "	Value: Bye = " << endl;
		cout << "		Expected: 0" << endl;
		cout << "		Actual: " << np2 << endl;
		cout << "		" << pass_or_fail(0,np2) << endl << endl;
	
	cout << endl << "Testing letters_present" << endl << "0 is false, 1 is true" << endl << endl;
		bool lp1 = letters_present("12345Hello");
		cout << "	Value: 12345Hello = " << endl;
		cout << "		Expected: 1" << endl;
		cout << "		Actual: " << lp1 << endl;
		cout << "		" << pass_or_fail(1,lp1) << endl << endl;

		bool lp2 = letters_present("1999");
		cout << "	Value: 1999 = " << endl;
		cout << "		Expected: 0" << endl;
		cout << "		Actual: " << lp2 << endl;
		cout << "		" << pass_or_fail(0,lp2) << endl << endl;
	
	cout << endl << "Testing contains_substring (string, substring) " << endl << "0 is false, 1 is true" << endl << endl;
		bool ssub1 = contains_substring("Hello World","Hello");
		cout << "	Value: (Hello World, Hello)  " << endl;
		cout << "		Expected: 1" << endl;
		cout << "		Actual: " << ssub1 << endl;
		cout << "		" << pass_or_fail(1,ssub1) << endl << endl;

		bool ssub2 = contains_substring("Hello world", "Yellow");
		cout << "	Value: (Hello World, Yellow)  " << endl;
		cout << "		Expected: 0" << endl;
		cout << "		Actual: " << ssub2 << endl;	
		cout << "		" << pass_or_fail(0,ssub2) << endl << endl;
					
	cout << endl << "Testing word_count" << endl << endl;
		int wd1 = word_count("Hello this is a very simple sentence");
		cout << "	Value: Hello this is a very simple sentence = " << endl;
		cout << "		Expected: 7" << endl;
		cout << "		Actual : " << wd1 << endl;
		cout << "		" << last(7,wd1) << endl;

		int wd2 = word_count("Yet another sentence. Hello world! All of these words will be counted");
		cout << " 	Value: Yet another sentence. Hello world! All of these words will be counted = " << endl;
		cout << "		Expected: 12" << endl;
		cout << "		Actual: " <<  wd2 << endl;
		cout << "		" << last(12,wd2) << endl << endl;

	cout << endl << "Testing get_int " << endl << endl;
		cout << "	";
		string bin = get_bin();
		int res = get_int(bin);
		cout << "	" << res << endl;

	cout << endl << "Testing get_float" << endl << endl;
		cout << "	";
		string bin2 = get_bin2();
		float res2 = get_float(bin2);
		cout << "	" << res2 << endl;
	
	return 0;
}
