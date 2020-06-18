#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <fstream>

using namespace std;

/*******************************************************/
//function: deletePtr
//description
//deleting the pointer, in order to set back to NULL properly
//parameters: it must by passed by pointer (or reference)
//pre: passed by pointer/ref
//post: ptr will be deleted
/*******************************************************/
void deletePtr(int **x){
    delete[] *x;
    *x = NULL;
}

/********************************************************
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
		if ((stuff[i]  >47) && (stuff[i] <58) || (stuff[i] == ' ')) {
			i++;
			end = 1;
		}
		else{
			cout<<"Error! Value Enter is not correct"<< endl;
			end = 0;
                        break;
		}
	}
	return end;
}

/********************************************************
 * Function total_field
 * Description: find total field in equation and check for error
 * Parameters: string
 * Pre: String:
 * Post boolean
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

	return total;
}

/********************************************************
 * Function string_split
 * Description: split and get all character before space
 * Parameters: string
 * Pre: String:
 * Post boolean
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
 * Post boolean
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
		if(((num[len] >47) && (num[len] <58)) || (num[len] == 45)){
			len++;
		}
		else{
			break;
		}
		c_num = 1;
	}
	return c_num;
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
		int topower = int(bin.length()) -i -1;
		res = (int)((check*pow(10.0,topower)) + res);
	}
	return res;
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
//		cout << "Insert a number: " ;
		getline(cin,bin);
	}while(is_int(bin) == 0);
	return bin;
}

//********** Function to establish player name array, set it's size and take name input
//Function: PromptPlayerNames
//Description:establishes array of players
//parameters: takes int
//Pre: Int
//Post: Outputs an array
string *PromptPlayerNames(int NumPlayers) {
	string *players = new string[NumPlayers];
	for (unsigned int i = 0; i < NumPlayers; ++i) {
        	cout << "Enter Name of player " << (i + 1) << ": ";
        	getline(cin, players[i]);     // Assign Enter Player name to "players" variable
    	}

        return players;
}

//********** Prompt the user for the Number of Players **********
//Function: PromptNumPlayers
//Description: Asks for how many players
//Parameters: int
//Pre: Int
//Post: int
int PromptNumPlayers()
{
	system("clear");
	cout << "=================" << endl;
	cout << "NEW GAME" << endl;
	cout << "=================" << endl;
	unsigned int tmp;              // Assign Enter number of Player to variable

	do {
		cout << "How many players are playing? ";
		string ah = get_bin();
		tmp = get_int(ah);              // Assign Enter number of Player to variable
		if (tmp < 2)
			cout << "Number of Player need to be 2 or more" << endl;
	} while (tmp < 2);

        return tmp;
}

//********** Displays the Main Menu **********
//Function: Show menu
//Description: homepage
//Parameters: ? none
//Pre: None? Run the game
//Post: either quits you out, makes you reprompt, or plays game
int ShowMenu()
{
	unsigned int selection;

	system("clear");
	cout << "=================" << endl;
	cout << "Welcome to Farkle" << endl;
	cout << "=================" << endl;

	cout << "1) New Game" << endl;
//	cout << "2) Show Rules" << endl;
	cout << "2) Quit" << endl << endl;

	cout << "Please enter a selection: ";

	string ah = get_bin();
	selection = get_int(ah);

        return selection;
}

/*
 function: diceoccurance
 description: counts how many times each number is rolled
 	(used for scoring purposes)
parameters: takes in dice array for its value and the number of dice rolled
pre: has array and number of array
post: occurance of how many times 1-6 was rolled
 */
int *diceOccurance(int *diceVal, int NumDiceRoll) 
{
	int *diceCount = new int[7];
	for (int i = 0; i < 7; i++) { diceCount[i] = 0;}
	for (int i = 0; i < NumDiceRoll; i++) {
        	if (diceVal[i] == 1)      { diceCount[1]++;}  // Add occurance of 1 from NumDiceRoll
                else if (diceVal[i] == 2) { diceCount[2]++;}  // Add occurance of 2 from NumDiceRoll
                else if (diceVal[i] == 3) { diceCount[3]++;}  // Add occurance of 3 from NumDiceRoll
                else if (diceVal[i] == 4) { diceCount[4]++;}  // Add occurance of 4 from NumDiceRoll
                else if (diceVal[i] == 5) { diceCount[5]++;}  // Add occurance of 5 from NumDiceRoll
                else if (diceVal[i] == 6) { diceCount[6]++;}  // Add occurance of 6 from NumDiceRoll
	}

	return diceCount; //Returns roll values
}

/*
 function: diceroll
 description: rolls the dice and puts it in an array
 paramters: how many dice
 pre: number of dice
 post: the dice array
*/
int *diceRoll(int NumDiceRoll) //Dice roll function, restricts possible numbers between 1 and 6
{
	int *diceVal = new int[NumDiceRoll];

	for (int i = 0; i < NumDiceRoll; i++) {
        	diceVal[i] = (rand() % 6 + 1); //Numbers restricted to between 1 and 6 to simulate dice

        	cout << "Dice #" << (i + 1) << " Roll = " << diceVal[i] << endl;
	}

	return diceVal; //Returns roll values
}

/* POINT CHECKING FUNCTIONS___________________________________________________________________________________ */
// Functions: various point checking functions
// Description: checks points for scoring
// Paramters: array of dicecount (how many times each 1-6 was rolled
// Pre: an array
// Post: various points
int ThreePair(int *DiceCount, int flag)
{
	int totalPoint = 0;

	for (int i = 1; i < 7; i++) {
                if (DiceCount[i] == 2) {   // Check first Pair
	                for (int j = 1; j < 7; j++) {
                                if ((DiceCount[j] == 2) && (i != j)) {  // Check second Pair
	                                for (int k = 1; k < 7; k++) {
                                                if ((DiceCount[k] == 2) && (k != i) && (k != j))  // Check third Pair
                                                        totalPoint = 1500;
	                                }
	                        }
	                }
                }
	}

        if ((totalPoint > 0) && flag)
     	     	cout << "Three pairs, possible Point for this Roll = " << totalPoint << endl;

	return totalPoint;
}

/************************************************************/
int FourTwo(int *DiceCount, int flag)
{
	int totalPoint = 0;

	for (int i = 1; i < 7; i++) {
                if (DiceCount[i] == 4) {   // Check first Four
	                for (int j = 1; j < 7; j++) {
                                if ((DiceCount[j] == 2) && (i != j))   // Check second Two
                                        totalPoint = 1500;
	                }
                }
	}

        if ((totalPoint > 0) && flag)
     	   	cout << "Four of any number + a pair, possible Point for this Roll = " << totalPoint << endl;

	return totalPoint;
}

/************************************************************/
int TwoTriplet(int *DiceCount, int flag)
{
	int totalPoint = 0;

	for (int i = 1; i < 7; i++) {
                if (DiceCount[i] == 3) {   // Check first Triplet
	                for (int j = 1; j < 7; j++) {
                                if ((DiceCount[j] == 3) && (i != j))  // Check second Triple
                                        totalPoint = 2500;
	                }
                }
	}

        if ((totalPoint > 0) && flag)
     	        cout << "Two triplets, possible Point for this Roll = " << totalPoint << endl;

	return totalPoint;
}

/************************************************************/
int Dice6RollScore(int *DiceCount, int flag)
{
	for (int i = 1; i < 7; i++) {
                // Six of any number = 3,000
                if (DiceCount[i] == 6) {
     		        if (flag) cout << "Six of any number, possible Point for this Roll = 3000" << endl;
                        return 3000; }

                // 1-6 straight = 1,500
                if ((DiceCount[1] == 1) && (DiceCount[2] == 1) && (DiceCount[3] == 1) &&
                    (DiceCount[4] == 1) && (DiceCount[5] == 1) && (DiceCount[6] == 1)) {
     		        if (flag) cout << "Straight, possible Point for this Roll = 1500" << endl;
                        return 1500; }

                if (DiceCount[i] == 2)             // Three pairs = 1,500
                        return ThreePair(DiceCount, flag);

                if (DiceCount[i] == 4)             // Four of any number with a pair = 1,500
                        return FourTwo(DiceCount, flag);

                if (DiceCount[i] == 3)            // Two triplets = 2,500
                        return TwoTriplet(DiceCount, flag);
	}

	return 0;
}

/************************************************************/
int DiceScore(int *DiceCount, int flag)
{
	int totalPoint = 0;

	for (int i = 1; i < 7; i++) {
        	if (i == 1) totalPoint += 100*DiceCount[i];                    // Single 1 = 100
        	else if ((i == 2) && (DiceCount[i] == 3))
                	totalPoint += 200;  // Three 2’s = 200
        	else if ((i == 3) && (DiceCount[i] == 3))
                	totalPoint += 300;  // Three 3’s = 300
        	else if ((i == 4) && (DiceCount[i] == 3))
                	totalPoint += 400;  // Three 4’s = 400
        	else if (i == 5) {
                	totalPoint += 50*DiceCount[i];                          // Single 5 = 50
                	if (DiceCount[i] == 3) totalPoint += 500;               // Three 5’s = 500
        	}
        	else if ((i == 6) && (DiceCount[i] == 3))
                	totalPoint += 600;  //Three 6’s = 600
	}

        if ((totalPoint > 0) && (flag == 1))
     		cout << "Possible Point, three of any number or 1 & 5 combos, for this Roll = " << totalPoint << endl;

	return totalPoint;
}

/************************************************************/
//function: dicescore1
//description: this adds to score for 3 of a kind and for 1s
//parameters: the amount each number is rolled and an array for point per dice
//pre: user must have rolled
//post: user gets points
void DiceScore1(int *DiceCount, int *pointPerDice)
{
	for (int i = 1; i < 7; i++) {
        	pointPerDice[i] = 0;
        	if (i == 1) pointPerDice[i] = 100*DiceCount[i];                    // Single 1 = 100
        	else if ((i == 2) && (DiceCount[i] == 3)) {pointPerDice[i] = 200;}  // Three 2’s = 200
        	else if ((i == 3) && (DiceCount[i] == 3)) {pointPerDice[i] = 300;}  // Three 3’s = 300
        	else if ((i == 4) && (DiceCount[i] == 3)) {pointPerDice[i] = 400;}  // Three 4’s = 400
        	else if (i == 5) {
                	pointPerDice[i] = 50*DiceCount[i];                          // Single 5 = 50
                	if (DiceCount[i] == 3) pointPerDice[i] = 500;               // Three 5’s = 500
        	}
        	else if ((i == 6) && (DiceCount[i] == 3)) {pointPerDice[i] = 600;}  //Three 6’s = 600

                // Four of any number = 1,000
                if (DiceCount[i] == 4) pointPerDice[i] = 1000;

                // Five of any number = 2,000
                if (DiceCount[i] == 5) pointPerDice[i] = 2000;
	}
}

/********************************************************************************************************************/
/*
 * function: dicerollscore
 * description: this actually checks the dice array and uses the functions from above to give points
 * Parameters: takes dicecount and makes sure input is valid
 * pre: it has dicecount array
 * post: gives user temp score
 */
int DiceRollScore(int *DiceCount, int flag)
{
	int totalPoint = 0;

	for (int i = 1; i < 7; i++) {
                // Four of any number = 1,000
                if (DiceCount[i] == 4) totalPoint += 1000;

                // Five of any number = 2,000
                if (DiceCount[i] == 5) totalPoint += 2000;
	}

        if (totalPoint > 999) {
        	for (int i = 1; i < 7; i++) {
        	        if ((i == 1) && ((DiceCount[i] != 4) || (DiceCount[i] != 5)))
                                totalPoint += 100*DiceCount[i];                    // Single 1 = 100
        	        if ((i == 5) && ((DiceCount[i] != 4) || (DiceCount[i] != 5)))
                	        totalPoint += 50*DiceCount[i];                     // Single 5 = 50
		}
     		cout << "Four or Five of any number + 1 & 5 combos, possible Point for this Roll = " << totalPoint << endl;
	}
	else
        	totalPoint = DiceScore(DiceCount, flag);

	return totalPoint;
}

/************************************************************/
/*
 * function: dicerollscore
 * description: this actually checks the dice array and uses the functions from above to give points
 * Parameters: takes dicecount and makes sure input is valid
 * pre: it has dicecount array
 * post: gives user temp score
 */
int DiceCheckScore(int *DiceCount, int flag)
{
	int NumDiceScore = 0;
	int *pointPerDice = new int[7];

	DiceScore1(DiceCount, pointPerDice);

	for (int i = 1; i < 7; i++) {
                if ((DiceCount[i] > 0) && (pointPerDice[i] > 0)) NumDiceScore += DiceCount[i];
	}

        deletePtr(&DiceCount);
        deletePtr(&pointPerDice);

	return NumDiceScore;
}

/*************************************************/
//Function
//description: checks they put valid number for how many dice they want to take out
//parameters: how many dice there are left
//pre: you have dice and its your turn
//post: you take out the corresponding amount of dice
int diceQuest( int NumDiceLeft, int numDiceRemove){
	string bin = "";	
		do{
			cout << "How many dice do you want to take out? ";
			getline(cin,bin);
			numDiceRemove = get_int(bin);
		}while((numDiceRemove < 1) || (numDiceRemove > NumDiceLeft));

	return numDiceRemove;
}

/*************************************************/
//function: diceRemoveEnter
//description: error handles that the user removes valid dice
//parameters: dice entered array (puts the number they put in into here) # of dice, diceremove val is the number of the
//	corresponding dice ex) dice 6 = 3 so 3, tempval is to check its like a temporary checker, int numdiceremove is how many they want 
//	to remove, and intnumdice is how many dice they would have left after removing
//pre: all the parameters must be correct
//post: diceenter array will be filled
void diceRemoveEnter(int *diceEnter, int *diceRemoveVal, int *diceTmpVal, int numDiceRemove, int NumDiceLeft)
{
	string bin = "";
	for (int i = 0; i < numDiceRemove; i++){
		do{
			cout << "Remove which dice? (Insert dice one number at a time): ";
			getline(cin,bin);
			diceEnter[i] = get_int(bin);
                	if ((get_int(bin) > 0) && (get_int(bin) < (NumDiceLeft+1))) {
				diceRemoveVal[i] = diceTmpVal[get_int(bin)-1];
				break;
			}
			else
				cout << "Incorrect Dice was Enter.  Dice Out of Range" << endl;

		}while (1);
	}
}

/**********************************************************************/
//function: diceremovequest
//description: more error handling for user taking out dice this one is for duplicate dice
//parameters: dice entered array (puts the number they put in into here) # of dice, diceremove val is the number of the
//	corresponding dice ex) dice 6 = 3 so 3, tempval is to check its like a temporary checker, int numdiceremove is how many they want 
//	to remove, and intnumdice is how many dice they would have left after removing
//pre: all parameters must be correct
//post: will return whether or not it works
void diceRemoveQuest(int *diceEnter, int *diceRemoveVal, int *diceTmpVal, int numDiceRemove, int NumDiceLeft)
{
	int duplicate_dice;
	do {
        	duplicate_dice = 0;
                diceRemoveEnter(diceEnter, diceRemoveVal, diceTmpVal, numDiceRemove, NumDiceLeft);

		for (int i = 0; i < numDiceRemove-1; i++){
			for (int j = i+1; j < numDiceRemove; j++){
				if (diceEnter[i] == diceEnter[j]) {
					cout << "Incorrect Dice was Enter.  Duplicate Dice" << endl;
					duplicate_dice = 1;
				}
			}
		}
	} while (duplicate_dice);
}

/************************************************************/
//function:initialDice
//description: this just initializes dice
//parameters: DiceVal to set the Val, diceTmpVal, and how many dice there are to initalize
//pre: you need the arrays and how many dice
//post: array will be initalized
void initialDice(int *DiceVal, int *diceTmpVal, int NumDiceLeft)
{
        for (int i = 0; i < NumDiceLeft; i++) {
               	diceTmpVal[i] = DiceVal[i];
                DiceVal[i] = 0;
        }
}

/************************************************************/
//function: tmpDiceScoreCheck
//description: checks the dice if theyre good and if they are good then does ot
//parameters: all the dice arrays
//pre: make sure its users turn
//post: remove dice
int tmpDiceScoreCheck(int *diceEnter, int *diceRemoveVal, int *DiceVal, int *diceTmpVal, int numDiceRemove, int tmpDiceScore)
{
	int *tmpDiceCount = diceOccurance(diceRemoveVal, numDiceRemove);
	if (Dice6RollScore(tmpDiceCount, 0) > 1499) {
		tmpDiceScore = 6;
        	deletePtr(&tmpDiceCount);
	}
	else
		tmpDiceScore = DiceCheckScore(tmpDiceCount, 0);

	if (tmpDiceScore != numDiceRemove)
		cout << "Incorrect Dice was Enter.  Dice not use for Score" << endl;
	else {
		for (int i = 0; i < numDiceRemove; i++)
			DiceVal[diceEnter[i]-1] = diceTmpVal[diceEnter[i]-1];
	}

	deletePtr(&diceRemoveVal);
	deletePtr(&diceEnter);
	deletePtr(&diceTmpVal);

        return tmpDiceScore;
}

/*****************************************************************************************/
//Function: promptremovedice
//description: deals with everything having to do with user removing dice for scoring and rerolling
//Parameters: how many dice there are left and the values of the dice
//Pre: the amound of dice left and the values of those dice
//post: should create new array
/************************************************************/
int PromptRemoveDice(int *DiceVal, int NumDiceLeft)
{
	string bin = "";
       	int tmpDiceScore = 0, numDiceRemove = 0;
	int *diceTmpVal = new int[NumDiceLeft];

	initialDice(DiceVal, diceTmpVal, NumDiceLeft);

	do{
		numDiceRemove = diceQuest(NumDiceLeft,numDiceRemove); //asks usershow many dice to take out and returns a valid number

		int *diceRemoveVal = new int[numDiceRemove];
		int *diceEnter = new int[numDiceRemove];

                diceRemoveQuest(diceEnter, diceRemoveVal, diceTmpVal, numDiceRemove, NumDiceLeft);

                tmpDiceScore =  tmpDiceScoreCheck(diceEnter, diceRemoveVal, DiceVal, diceTmpVal, numDiceRemove, tmpDiceScore);

	} while(tmpDiceScore != numDiceRemove);

        return (numDiceRemove);
}

/*****************************************************************************************/
/* function: over500
 * description: after user has 500 points they are prompted if they want to reroll each time
 * parameters: user must have 500 points and they must have rolled
 * pre: they have over 500 points and it is time for them roll
 * post: they roll again or next users turn
 */
int over500(int NumDiceRoll, int FinalPoint){
	string ans = "";
	do {
		cout << "You got : " << FinalPoint << " Point.  Do you want to continue Rolling (y/n) ? ";
		getline(cin,ans);
		if (ans[0] == 'y') {
			if (NumDiceRoll == 0)
                        	NumDiceRoll = 6;
			break;
		} else
                        	NumDiceRoll = 0;
	} while (ans[0] != 'n');
	return NumDiceRoll;
}

/***************************************************************************/
//function: printFinalPoint
//description: prints the running total
//parameters: total score and running total
//pre: had to have scored points
//post: the running total for the round
int printFinalPoint(int FinalPoint, int totalPoint)
{
	// Compute accumulate Point after Dice remove
	FinalPoint += totalPoint;
	cout << "                        Running Total = " << FinalPoint << endl;

        return FinalPoint;
}

/***************************************************************************/
//function: checkDiceRollScorre
//description: checks each dice combo value
//Parameters: dice values and how many of each number the total total points and how many dice are rolled
//pre: user just rolled
//post: return the total points
int checkDiceRollScore(int *diceVal, int *DiceCount, int totalPoint, int NumDiceRoll)
{
        // Add all dices: all 6 Dices add up or Add each Dice combination
	if ((totalPoint = Dice6RollScore(DiceCount, 1)) < 1500)
                totalPoint = DiceRollScore(DiceCount, 1);

	deletePtr(&DiceCount);

        return totalPoint;
}

/***************************************************************************/
//function: printFarkled
//description: if user gets a farkle this will be printed
//parameters: diceVal and their points for the round
//pre: must have rolled and gotten a farkle
//post: no points added
int printFarkled(int *diceVal, int FinalPoint, int tempFinalPoint)
{
	cout << endl << "FARKLED.... Total Point of " << FinalPoint << " is Loss" << endl << endl;
        FinalPoint = tempFinalPoint;

        deletePtr(&diceVal);

        return FinalPoint;
}

/***************************************************************************/
//function: rollDiceAgain
//description: if they user wnats to roll
//parameters: how many of each number of dice the values how many dice were rolled and total total points
//pre: user must want to have roll again or have to\
//post": they roll again
int rollDiceAgain(int *DiceCount, int *diceVal, int NumDiceRoll, int totalPoint)
{
        DiceCount = diceOccurance(diceVal, NumDiceRoll); // Compute total Occurance remove
	if ((totalPoint = Dice6RollScore(DiceCount, 0)) < 1500)
        	totalPoint = DiceRollScore(DiceCount, 0);

	deletePtr(&DiceCount);
        deletePtr(&diceVal);

        return totalPoint;
}

/***************************************************************************/
/*
 function: playerturn
 description: runs all the functions and things during users turn, returns points
 parameters: takes in everything having to do with scoring and dices to count scoring
 pre: user will roll
 post: score will be given
 */
int PlayerTurn(int FinalPoint, int totalPoint, int removePoint, int NumDiceRoll)
{
        int NumDiceRemove = 0, *diceVal, *DiceCount, tempFinalPoint = FinalPoint;

        while (NumDiceRoll > 0) {
		diceVal = diceRoll(NumDiceRoll);   // Roll Number of available Dice
		DiceCount = diceOccurance(diceVal, NumDiceRoll); // Compute total Occurance
                totalPoint = checkDiceRollScore(diceVal, DiceCount, totalPoint, NumDiceRoll);

        	if (totalPoint > 0) {  // If Point avaible (not Farkle) ask player to remove Dice
		        NumDiceRemove = PromptRemoveDice(diceVal, NumDiceRoll);
		        totalPoint = rollDiceAgain(DiceCount, diceVal, NumDiceRoll, totalPoint);
		}
        	else {
			FinalPoint = printFarkled(diceVal, FinalPoint, tempFinalPoint);
                        break;
        	}

                // Compute accumulate Point after Dice remove
                NumDiceRoll -= NumDiceRemove;
                if ((FinalPoint = printFinalPoint(FinalPoint, totalPoint)) > 499)
			NumDiceRoll = over500(NumDiceRoll,FinalPoint);
	}

        return FinalPoint;
}

/*****************************************************************************************/
/*
function: lastturnwinner
description: how the last round is played
parameters: number of players, takes in playersscore, their names, winner, and winnerpoint
pre: usual game
post: game should conclude
 */
void LastTurnWinner(int NumPlayers, int *PlayerScore, string *Players, int winner, int WinnerPoint)
{
 	string line;

	for (int i = 0; i < NumPlayers; i++) {
                if (i != winner) {
	        	cout  << endl << "Player: >>>>>>>>> " << Players[i] << " <<<<<<<<<< Last Turn" << endl << endl;
	        	cout << "Point Started = " << PlayerScore[i] << endl;
			PlayerScore[i] = PlayerTurn(PlayerScore[i],0,0,6);
		}
		cout << "                        Player: >>>>>>>>>" << Players[i] << " <<<<<<<<<< Last Turn Point = " << PlayerScore[i] << endl << endl;
		if (PlayerScore[i] > WinnerPoint) {
			WinnerPoint = PlayerScore[i];
			winner = i;
		}
	}
	cout << "Player: " << Players[winner] << " Win with " << WinnerPoint << " Point..."  << endl << endl ;

	cout << "Press Enter to continue ";
	getline(cin,line);
}

/*****************************************************************************************/
// function: firstturn
// description: is the first turn of the game and then will call function for other rounds
// parameters: needs to know umber of players takes the scoreboard players, whether theres a winner and the points of winner (these get passed)
// pre: needs to have all parameters correctly filled out
// post: game will actually start playinh
int FirstTurn(int NumPlayers, int *PlayerScore, string *Players, int winner, int WinnerPoint)
{
	for (int i = 0; i < NumPlayers; i++) { PlayerScore[i] = 0; }

	do {
		for (int i = 0; i < NumPlayers; i++) {
			cout  << endl << "Player: >>>>>>>>> " << Players[i] << " <<<<<<<<<< Turn" << endl << endl;
	        	cout << "Point Started = " << PlayerScore[i] << endl;
			if ((PlayerScore[i] = PlayerTurn(PlayerScore[i],0,0,6)) > 10000) {
				winner = i;
                                WinnerPoint = PlayerScore[i];
			}
			for (int r = 0; r < NumPlayers; r++)
				cout << endl << "                        Player: >>>>>>>>> " << Players[r] << " <<<<<<<<<< Point = " << PlayerScore[r] << endl << endl;
		}
	} while (winner == -1);
	
	return WinnerPoint;
}

/*****************************************************************************************/
/*
 function: playfarkle
 description: void function that runs in the game
 parameters: takes in numplayers and whether theres a winner (its a boolean but i used an int)
 pre: nothing
 post: game runs
 */
void PlayFarkle(int NumPlayers, int winner)
{
	NumPlayers = PromptNumPlayers();
	string *Players = PromptPlayerNames(NumPlayers);

	int *PlayerScore = new int[NumPlayers]; // Scoring array to hold individual player scores
        int WinnerPoint;

	WinnerPoint = FirstTurn(NumPlayers, PlayerScore, Players, winner, WinnerPoint);

	LastTurnWinner(NumPlayers, PlayerScore, Players, winner, WinnerPoint);

	deletePtr(&PlayerScore);
	delete[] Players;
	Players = NULL;
}

/****************************************************************/
int main()
{
	bool quit = false;
	int selection;

	while (!quit) {
		if ((selection = ShowMenu()) == 1) {
			PlayFarkle(0,-1);
		}
		else if (selection == 2) {
			quit = true;
		}
	}
}
