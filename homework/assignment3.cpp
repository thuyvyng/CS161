/***********************************************************************
 Function: Assignment 3
 Author: Thuy-Vy Nguyen
 Description: Designing functions for error handling
 **********************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include "helper_functions.h"
using namespace std;

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
