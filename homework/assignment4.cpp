#include <iostream>
#include <string>
#include <cmath>
#include "helper_functions.h"
#include <stdlib.h>
using namespace std;

/****************************************************
 * Function: is_int
 * Description: checks if string is int
 * Paramters: String
 * Pre: Takes a string
 * Post: Returns boolean if condition has been met
 * ****************************************************/
bool is_int(string num){
	bool c_num = 0;
	int len = 0;
	int l = num.length();

	while(num[len] != '\0'){
		if((num[len] >47) && (num[len] <58)){
			len++;
		}
		else{
			break;
		}
		c_num = 1;
	}
	if ( len != l){
		c_num = 0;
	}
	return c_num;
}
/**********************************************************
 * Function: is_float
 * Description:  Takes an input from user and inputs whether the input was a float
 * Parameters: string
 * Pre: String
 * Post: boolean
 * *********************************************************/
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



/**********************************
 * Function: get_float
 * Description: takes string float and converts to float
 * Parameters: string
 * pre: string
 * post: float
 * ********************************/
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

/*****************************************************
 * Function: between4
 * Description: Check if the user's input is between 1 and 4
 * Parameters: string
 * Pre: string
 * Returns: boolean
 * *******************************************/
bool between4(string num){
	bool end = 0;
	int i = 0;

	if (num.length() == 1){
		if ((num[i] == '1') || (num[i] == '2') || (num[i] == '3') || (num[i] == '4')) {
			end = 1;
		}
		else{
			end = 0;
		}
	}
	return end;
}

/*****************************************************
 * Function: is_bool
 * Description: Checks if user's input is 0 or 1
 * Parameters: string
 * Pre: Takes a string
 * Returns: boolean
 * ****************************************/

bool is_bool(string num){
	bool end = 0;
	int i = 0;

	if ( num.length() == 1){
		if ( (num[i] == '1') || ( num[i] == '0')){
			end = 1;
		}
		else{
		end = 0;
		}
	}
	return end;
}
/*******************************************************
 * Function: get_int
 * Description: takes a string and converts to an int
 * Parameters: String
 * Pre: String
 * Post: Int
 * ******************************************************/

int get_int(string bin){
	int res = 0;
	for (int i = 0; i < bin.length(); i++){
		int check = bin[i] - '0';
		res = (check*pow(10,bin.length() -i -1)) +res;
	}
	return res;}
/*********************************************************
 * Function: typevalid2
 * Descriptions: Checks if string only has 0 or 1s
 * Parameters: string
 * Pre: String
 * Post: Boolean
 * ********************************************************/

bool typevalid2(string stuff){
	bool end = 0;
	int i = 0;	
	while(stuff[i] != '\0'){
		if( (stuff[i] == '0') || (stuff[i] == '1')){
			i++;
		}
		else{
			break;
		}
	end = 1;
	}
	if ( i != stuff.length()){
		end = 0;
	}
	return end;

}

/********************************************************8
 * Function typevalid1
 * Description: make sure the string only has operators, numbers, or -/.
 * Parameters: string
 * Pre: String:
 * Post boolean
 * ******************************************************/

bool typevalid1(string stuff){
	bool end = 0;
	int i = 0;

	while(stuff[i] != '\0'){
		if ((stuff[i]  >47) && (stuff[i] <58) || (stuff[i] == '-') || (stuff[i] == '*') || (stuff[i] == '/') || (stuff[i] == '+') || (stuff[i] == '.') || (stuff[i] == ' ')){
			i++;
		}
		else{
			break;
		}
	end = 1;
	}
	return end;

}
/**************************************************
 * Function: get_bin
 * Description: This returns the string one it has been checked that it is infact a decimal number
 * Parameters: String
 * Pre: String
 * Post: String
 * ************************************************/
string get_bin(){
	string bin = "";
	do{
		cout << "Insert a number: " ;
		getline(cin,bin);
	}while(is_int(bin) == 0);
	return bin;
}
/***************************************************
 * Function: get_biin
 */ 
string get_biin(){
	string bin = "";
	do{
		cout << "Insert 1,2,3,or 4: ";
		getline(cin,bin);
	}while(between4(bin) == 0);
	return bin;
}
/*************************************************
 * Function: get_bool
 * Description: This returns the string once it has been checked that it is 0 or 1
 * Parameters: String
 * Pre: String
 * Post: String
 * *****************************************************/

string get_bool(){
	string bin = "";
	do{
		cout << "Insert 0 or 1: ";
		getline(cin,bin);
	}while(is_bool(bin) == 0);
	return bin;
}
/*************************************************
 * Function: get_bin2
 * Description: Returns string that has been proven to be binary
 * Parameters: String
 * Pre: String
 * Post: String
 * *******************************************/
string get_bin2(){
	string bin = "";
	do {
		cout << "Insert a binary number: ";
		getline(cin,bin);
	}while(typevalid2(bin) == 0);

	return bin;

}
/********************************************************
 * Function: get_bin1
 * Description: checks if calculator (simple) input is valid and then recieves it
 * Parameters: userinput string
 * Pre: String
 * Post: String
 * ********************************************/

string get_bin1(){
	string bin = "";
	do {
		cout << "Insert your calculation: " << endl;
		getline(cin,bin);
	}while(typevalid1(bin)==0);
	return bin;
}

/************************************************
 * Function: convert2
 * Description: Converts string of 01 to decimal
 * Parameter: String
 * Pre: String
 * Post: int
 * **************************************************/

int convert2(string binary){
	int i = 0;
	int temp = 0;
	while (binary[i] != '\0'){
		if ( binary[i] == '1'){
			temp = pow(2,binary.length()-1-i) + temp;
//			cout << temp;
			i++;
		}
		else{
			i++;
		}
	}
	return temp;

}
 /********************************************
  * Function: dec2binconvert
  * Description: convert decimal string to binary
  * Parameter: Int
  * Pre: Int
  * Post: int
  * **********************************************/



int dec2binconvert( int number) {
	int r = 0, placeholder = 1, binarynum = 0;

	while (number != 0){
		r = number%2;
		number = number/2;
		binarynum = binarynum + (r*placeholder);
		placeholder = placeholder*10;
	}
	return binarynum;

}
/******************************************888
 * Function: gradecalcweighted
 * Description: Calculated grades when user wants it weighted
 * Parameter: Int how many grades
 * Pre: int
 * Post: Float
 * *********************************************/
float gradecalcweighted(int grades) {
	float end = 0;
	for (int i = 0; i < grades; i++){
		cout << endl << "Insert grade out of 100: " << endl;
		string input = get_bin();
		int numgrades = get_int(input);
	//	cout << "NUMBER = " << numgrades << endl;
		cout << "Insert weighted as a whole number. Ex. 60% weighted = 60" << endl;
		string weights = get_bin();
		float weighted = get_int(weights)/100.0;
	//	cout << "weight = " << weighted << endl;
		float sup = weighted*numgrades;
		end = end + sup;
		cout << endl;
	}
	return end;
}
/******************************************************
 * Function: gradcalcnon
 * Description: Calculate grades when not weighted
 * Parameter: Int how many grades
 * Pre: Int
 * Post: Float
 * *****************************************************/

float gradecalcnon (int grades){

	float end = 0; 
	for (int i = 0; i < grades; i++){
		cout << endl << "Insert grade out of 100: " << endl;
		string input = get_bin();
		float numgrades = get_int(input)*1.0;
		end = end + numgrades;
	}
	float yolo = 0;

	yolo = end/grades;
	return yolo;
}
/***********************************************************
 : binarytodec
 * Description: Runs all the functions to turn binary string into decimal
 * Parameters: n/a
 * pre: n/a
 * post: will turn binary strings into decimal #
 * ****************************************************************/

void binarytodec(){
	// this is for binary to decimal conversion
	string bin2dec = get_bin2();
	int result2 = convert2(bin2dec);
	cout << "	In decimal: " << result2 << endl << endl;
	//------------------end of binary to decimal
}
/*********************************************************************
 * Function: dectobinary
 * Descriptions: Void function to turn decimal to binary
 * Parameters: n/a
 * pre: n/a
 * post: turn decimal to binary
 * ***************************************************/
void dectobinary(){

	//decimal to binary conversion
	string dec2bin = get_bin();
	int dec2binINT = get_int(dec2bin);
	int result3 = dec2binconvert(dec2binINT);
	cout << "	In binary: " << result3 << endl << endl;
}



/********************************************************
 * Function total_field
 * Description: find total field in equation and check for error
 * Parameters: string
 * Pre: String:
 * Post: int how many fields there and also checks if it there is error
 * ******************************************************/
int total_field(string bin){
	string result = "";
	int i = 0;
	int total = 0;

	while (1) {
		if ((bin[i]  == ' ') || (bin[i] == '\0')) {	// Check for space or end of line
			total++;				// total number of field in equation
		}

		if (bin[i] == '\0')		// End of line, exit
			break;
		i++;				// Increase to next character in equation
	}

	// Check to make sure equation have more than 3 field, odd, and last character must be a number
	if ((total < 3) || (total%2 == 0) || (bin[i-1] < 48) || (bin[i-1] > 57)) {
		cout<<"Error! equation is not correct"<< endl;
		return 0;
	}

	return total;
}





/********************************************************
 * Function string_split
 * Description: split and get all character before space
 * Parameters: string
 * Pre: String:
 * Post string
 * ******************************************************/
string string_split(string bin){
	string result = "";
	int i = 0;

	while (1) {
		if ((bin[i]  == ' ') || (bin[i] == '\0')) {	// Check for space or end of line
			break;
		}
		else{
			result = result + bin[i];	// Add all character until space or EOL reach
		}

		if (bin[i] == '\0')		// End of line, exit
			break;
		i++;				// Increase to next character in equation
	}

	return result;
}


/********************************************************
 * Function string_space
 * Description: split and get all character after space
 * Parameters: string
 * Pre: String:
 * Post: string
 * ******************************************************/
string string_space(string bin){
	string result = "";
	int i = 0;
	int flag = 0;

	while (1) {
		if (flag) {
			result = result + bin[i];	// Add all character after space or EOL reach
		}

		if (bin[i]  == ' ') {		// Check for space
			flag = 1;
		}

		if (bin[i] == '\0')		// End of line, exit
			break;
		i++;				// Increase to next character in equation
	}

	return result;
}


/*************************************************
 * Function: simplecalccompute
 * Description: Compute equation
 * Parameters: n/a
 * pre: n/a
 * post: puts simple calc in motion
 * *************************************************/
float simplecalccompute(string field, int num_op){
	float result = 0.0;
	string oper = "";

	result = strtof(string_split(field).c_str(),0);	// Get first number in equation to first space
	field = string_space(field);			// Get all character from first space

	for (int i = 1; i < num_op; i++) {
		oper = string_split(field);	// Get first operator in equation to next space
		field = string_space(field);	// Get all character after operator

		// Accumulate result to number next to operator
		if (oper[0] == '+')
			result = result + strtof(string_split(field).c_str(),0);
		else if (oper[0] == '-')
			result = result - strtof(string_split(field).c_str(),0);
		else if (oper[0] == '*')
			result = result * strtof(string_split(field).c_str(),0);
		else if (oper[0] == '/')
			result = result / strtof(string_split(field).c_str(),0);
		field = string_space(field);	// Get all character after operator
	}

	return result;
}


/*************************************************
 * Function: simplecalc
 * Description: Runs all the corresponding functions for simple calc
 * Parameters: n/a
 * pre: n/a
 * post: puts simple calc in motion
 * *************************************************/
void simplecalc(){
	float result = 0.0;
	int num_op = 0;
	int i = 0;
	string bin = "";
	string field = "";
	string oper = "";

	// Check input equation is valid
	do{
		cout<<"What is your equation?" << endl << " Separate your eq w/ spaces ex. '2 + 3 * 5'" << endl << "Only positive ints/floats" << endl;
		getline(cin,bin);
		num_op = total_field(bin);	// Check equation for operand, operator, & spaces
	}while((typevalid1(bin)==0) || (num_op==0));

	result = simplecalccompute(bin, num_op);	// Compute equation

	cout << bin << " = " << result << endl;		
}


/*********************************************************
 * Function: gradecalcc
 * Description: Void function for grade calculator
 * Parameters: n/a
 * Pre: n/a
 * post: will run grade calc
 * ********************************************************/

void gradecalcc(){

	cout << endl << "How many grades do you want to compute?" << endl;
	string grades = get_bin();
	int numgrades = get_int(grades);
	cout << endl << "Do you want weighted grades or not? Insert 0 for no, 1 for yes" << endl;
	string weighted = get_bool();
	int weights = get_int(weighted);

	if ( weights == 0){
		float result0 = gradecalcnon(numgrades);
		cout << result0 << endl;

	}
	else if ( weights == 1){
		float result41 = gradecalcweighted(numgrades);
		cout << result41 << endl;
	}
}
/**************************************************
 * Function: whatcalc
 * Description: will ask which calc you want and then call corresponding function todo so
 * Parameters: n/a
 * pre: n/a
 * post: a calc will run
 * **********************************************************/

void whatcalc(){

	cout << "What kind of calculator do you want? Insert #." << endl << " 1.Simple calc 2.Bin2Dec 3.Dec2Bin 4.Grade Calc." << endl << endl;
	string choice = get_biin();
	int calctype = get_int(choice);
	
	if (calctype == 1){
		simplecalc();
	}
	else if (calctype == 2){
		binarytodec();		
	}
	else if (calctype == 3){
		dectobinary();
	}
	else if (calctype == 4){
		gradecalcc();
	}


}
int main(){
	int answer = 1;

	while (answer != 0){
	whatcalc();

	cout << endl <<  "Do you want to do another calculation? 0 for no, Any other number for yes " << endl;
	string ah = get_bin();
	int ahh = get_int(ah);
	answer = ahh;

	}
	return 0;
}
