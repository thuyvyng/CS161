/****************************************************************
 Program Filename: Assignment1
 Author: Thuy-Vy Nguyen
 Date: 1/12/18
 Description: My code for assignment 1
 Input: 
 Output: 
 ******************************************************************/
#include <iostream>
#include <cmath>
using  namespace std;

int main() {
	
	float num2, num3, num4, num55, num60;
	num2 = 2;
	num3 = 3;
	num4 = 4;

	num55 = 55;
	num60 = 60;
	
	float numtwothirds, numthreefourths;	
	numtwothirds = (num2/num3);
	numthreefourths = -(num3/num4);


	/*------- used to test out program ----------------------
	cout << numtwothirds << endl;
	cout << numthreefourths << endl;

	cout << num3 << endl;
	cout << num4 << endl;
	---------------------------------------------------------*/

	float rcostwothree = cos(numtwothirds);
	cout << endl << "The value of cos(2/3) is " << rcostwothree << endl;

	float rprob2 = sin(numtwothirds);
	float rprobtwo = 2*rprob2;
	cout << "The value of 2sin(2/3) is " << rprobtwo << endl;

	float tanprob = tan(numthreefourths);
	cout << "The value of tan(-3/4) is " << tanprob << endl;

	float logz = log10(num55);
	cout << "Log of 55 with base 10 (log10 55) is " << logz << endl;

	float natlog = log(60);
	cout << "Natural log of 60 (ln 60) is " << natlog << endl << endl;

	cout  << endl << "Find the log base of 2 of 15 (log2 15)" << endl;

	float num15, num40;
	num15 = 15;
	num40 = 40;

	float nl15, nl30, nl40, nl2, logz1, nl4, logz2;

	nl15 = log(15);
	nl40 = log(40);
	nl4 = log(4);
	nl2 = log (2);
	logz1 = nl15/nl2;
	logz2 = nl40/nl4;

	cout << "ln(15) = " << nl15 << endl;
	cout << "ln(2) = " << nl2 << endl;
	cout << "log2 15 = ln(15)/ln(2) = " << logz1 << endl << endl;

	cout  << endl << "Find the log base of 4 of 40 (log4 40)" << endl;
	cout << "ln(40) = " << nl40 << endl;
	cout << "ln(4) = " << nl4 << endl;
	cout << "log4 40 = ln(40)/ln(4) = " << logz2 << endl << endl;

	float num1, num10, num100;

	num1 = 1;
	num10 = 10;
	num100 = 100;
	
	double sinn1, threeto;
	sinn1 = sin(1);
	//threeto = 3^sinn1;  fix here--------------------------------
	threeto = pow(3.0,sinn1);

	cout  << endl << "Solving 3 to the sin(x) (3^sinx)" << endl << endl;
	int loop;
	double num, result;
        for (loop = 0; loop < 3; loop++) {
		num = pow(10,1.0*loop);
		threeto = pow(3.0,sin(num));
		cout << "when x is " << num << endl;
		cout << "sin(" << num << ") = " << sin(num) << endl;
		cout << "3^(sin(" << num << ")) = " << threeto << endl << endl; 
	}

	cout  << endl << "solving log2(x^2 +1) " << endl << endl;
        for (loop = 0; loop < 3; loop++) {
		num = pow(10,1.0*loop);
		result = pow(1.0*num,2.0) + 1;
		cout << "when x is " << num << endl;
		cout << "(" << num << ")^2 + 1 = " << result << endl; 
		cout << "log2(x^2 +1) = log2(" << num << "^2 +1) = "  << log2(result) << endl << endl; 
	}
/*
	cout << "when x is 1" << endl;
	cout << "sin(1) = " << sinn1 << endl;
	cout << "3^(sin(1)) = " << threeto << endl << endl; 

	sinn1 = sin(10);
	threeto = pow(3.0,sinn1);	
	cout << "when x is 10" << endl;
	cout << "sin(10) = " << sinn1 << endl;
	cout << "3^(sin(10)) = " << threeto << endl << endl; 

	sinn1 = sin(100);
	threeto = pow(3.0,sinn1);
	cout << "when x is 100" << endl;
	cout << "sin(100) = " << sinn1 << endl;
	cout << "3^(sin(100)) = " << threeto << endl << endl; 

	float eq1, eq2, eq3, nl1, ah;
	//eq1 =(1^2) + 1;
	eq1 = pow(1.0,2.0) + 1;
	nl1 = log(eq1);
	ah = nl1/nl2;
	cout << "solving log2(x^2 +1) " << endl;
	cout << " When x is 1 " << endl;
	cout << " (1)^2 + 1 = " << eq1 << endl;
	cout << " log2(x^2 +1) = ln(1^2 +1) / ln(2) = " << ah << endl;
	cout << " or log2(x^2 +1) = log2(1^2 +1) = " << log2(eq1) << endl << endl;
	
	float  ahh, nl10;
	//eq2 = 10^2 +1;
	eq2 = pow(10.0,2.0) + 1;
	nl10 = log(eq2);
	ahh = nl10/nl2;
	cout<< "When x is 10 " << endl;
	cout << " (10)^2 + 1 = " << eq2 << endl;
	cout << " log2(x^2 +1) = ln(10^2 +1) / ln(2) = " << ahh << endl;
	cout << " or log2(x^2 +1) = log2(10^2 +1) = " << log2(eq2) << endl << endl;

	float ahhh, nl100;
	//eq3 = 100^2 +1;
	eq3 = pow(100.0,2.0) + 1;
	nl100 = log(eq3);
	ahhh = nl100/nl2;
	cout << "when x is a 100" << endl;
	cout << " (100)^2 +1 = " << eq3 << endl;
	cout << " log2(x^2 +1) = ln(100^2 +1) / ln(2) = " << ahhh << endl;
	cout << " or log2(x^2 +1) = log2(100^2 +1) = " << log2(eq3) << endl << endl;

	return 0;
*/
}
 

