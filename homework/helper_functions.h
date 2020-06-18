/***********************************************************************
 Function: Assignment 3
 Author: Thuy-Vy Nguyen
 Description: Designing functions for error handling
 **********************************************************************/
#include <string>

using namespace std;

/*-------------------------------------------------------------------
 * Function: check_range
 * Description: This function checks if a value is in range of two other values. 
 * Parameters: Does not work for floats, or anything not specifically int. Only accepts ints.
 * Pre-Conditions: Input three ints.
 * Post-Conditions: Either a yes or no, to indicate whether the value was inbetwe.
 **********************************************************************/
bool check_range( int lower_bound, int upper_bound, int test_value);
/**********************************************************************
 * Function: is_int
 * Description: This function will output whether the input is an int or no.
 * Parameters: Says whether the input is an int not a number, so no floats.
 * Pre-Conditions: Input any value
 * Post_Conditions: Either a yes or a no (1 or 0) to indicate whether the input was an int or not
 * *********************************************************************/

bool is_int(string num);
/************************************************************************
 * Function: is_capital
 * Description: Takes in a single character anf will say yes or no if the character os capitalized or not
 * Parameters: Did not test on any non letters (ABC).
 * Pre-conditions: Takes a single input from the user.
 * Post-conditions: Outputs 1 or 0 correspondingly
 * *********************************************************************/

bool is_capital(char letter);
/************************************************************************8
 * Function: is_float
 * Descriptions: Takes in input from the user and will output whether or not the output was a float or not
 * Parameters: Didn't really try negatives or funky floats such as 00000000.00087 or how precise it was.
 * Pre-conditions: Takes a single input from a user.
 * Post-conditions: Outputs a 1 or 0 correspondingly
 * *****************************************************************/

bool is_float(string num);
/*********************************************************************8
 * Function: is_even
 * Descriptions: Takes an input from the user and will output whether or not the int provided is even or not
 * Parameters:  DId not handle bad user input so it would take non ints. Did not try negatives.
 * Pre-Conditions: Takes a single input from the user that is an int.
 * Post-conditions: Yes or a no (1 or 0)
 * **************************************************************************/
bool is_even(int num);

/*********************************************************************8
 * Function: is_odd
 * Descriptions: Takes an input from the user and will output whether or not the int provided is odd or not
 * Parameters:  DId not handle bad user input so it would take non ints. Did not try negatives.
 * Pre-Conditions: Takes a single input from the user that is an int.
 * Post-conditions: Yes or a no (1 or 0)
 * **************************************************************************/
bool is_odd(int num);

/*********************************************************************************8
 * Function: to_upper
 * Descriptions: Will capitalize all lowercase letters in a string
 * Parameters: Did not try long sentences or anything. 
 * Pre-conditions: Strings
 * Post-conditions: Same string but all uppercase letters are now lowercase
 * *********************************************************************************/
string to_upper(string sentence);
/*********************************************************************************8
 * Function: to_lower
 * Descriptions: Will lowercase all capitalized  letters in a string
 * Parameters: Did not try long sentences or anything. 
 * Pre-conditions: Strings
 * Post-conditions: Same string but all lowercase letters are now uppercase
 * *********************************************************************************/
string to_lower(string sentence);

/******************************************************************************
 * Function: equality_test
 * Description: Tests the relationship between two ints.
 * Parameters: Only checked with positive ints
 * Pre-conditions: Two ints
 * Post-conditions: will output either -1, 0, 1 depending on the relationship between the two ints
 * ***************************************************************************/
int equality_test( int num1, int num2);
/****************************************************************************************************
 * Function: float_is_equal
 * Description: Determines if two floats are within a certain precision of each other
 * Parameters: Did not check negatives
 * Pre-conditions: 3 floats
 * Post-conditions: a boolean value indicating whether or not the boolean was true
 * ****************************************************************************************************/
bool float_is_equal(float num1, float num2, float precision);

/************************************************************************************************
 * Function: numbers_present
 * Description: Determines if in a given string has any numbers present.
 * Parameters: Did not try weird sentences
 * Pre-conditions: String given
 * Post-conditions: A boolean value indicated whether or not there were any numbers presents
 * *************************************************************************/
 
 bool numbers_present(string sentence);

/**********************************************************************************************************

 * Function: letters_present
 * Description: Determines if in a given string has any letters present.
 * Parameters: Did not try weird sentences but it works for lowercase and uppercase
 * Pre-conditions: String given
 * Post-conditions: A boolean value indicated whether or not there were any letters presents
 * *************************************************************************/
bool letters_present(string sentence);

/**************************************************************************************
 * Function: word_count
 * Description: counts how many words are in a sentence
 * Parameters: did not factor in if user put in bad input and put two spaces as one
 * Pre-Conditions: string given
 * Post-conditions: int of how many words there was
 * ******************************************************************************************/
int word_count(string sentence);


/**********************************************************************************************
 * Function: contains_substring
 * Description: determines whether one string has another string inside of it
 * Parameters: Did not factor in spaces or long sentences or whether not the bigger string had the smaller one more than once
 * Pre-conditions: two strings
 * Post-conditions: boolean value saying whether the condition was met
 *****************************************************************************************************/
bool contains_substring(string sentence, string sub_sentence);

/*******************************************************************************
 * Functions: pass_or_fail, woo, last
 * Descriptions: Checking if said functions work
 * Parameters: Doesn't really work for the get int/or float because we dont have an expected value
 * Pre-conditions: Expected value stated in the testing and the actia value provided by the function:
 * Post-conditions: hopefully a pass
 * ****************************************************************/
string pass_or_fail(bool expected, bool comparison);

string woo(string expected, string comparision);

string last(int expected, int comparison);

/***************************************************************************************************
 * Functions: get_bin, get_bin2
 * Description: taking in user input for the get functions and then respectively checking if they are valid input
 * Parameters: Does not perfectly check input like for how precise for floats and i did not check negatives
 * Pre-conditions: statement asking for inpit
 * Post: checking if the input is valid (an int or string)
 ***********************************************/
string get_bin();

string get_bin2();

/*******************************************************************************
 * Function: get_int, get_float
 * Description: If the input was said to be an int or a float then this will convert the string to the int/float
 * Parameters: Not very precise, doesn't work with negatives
 * Pre-Conditions: Taking user input for a string
 * Post-Conditions: A string or float respectively
 * ************************/
int get_int (string bin);

float get_float (string bin);

