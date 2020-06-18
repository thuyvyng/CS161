#include <iostream>
#include <cmath>
#include <string>
#include <cstring> 
using namespace std;

//FUNCTIONS FROM PREVIOUS ASSIGNMENTS___________________________________________________

//function: is_int
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

//function: get_int
int get_int(string bin){
	int res = 0;
	for (int i = 0; i <bin.length(); i++){
		int check = bin[i] - '0';
		int topower = int(bin.length()) -i -1;
		res = (int)((check*pow(10.0,topower)) + res);
	
	}
	return res;


}
//FUNCTIONS FROM PREVIOUS ASSIGNMENT OVER__________________________________________________



//function: check_user_board
//description: checks command line argument and make sure it is valid
//parameters: takes in the second index of the command line argument and checks the length
//pre: they add command line arguments
//post: returns or reprompts

int check_user_board(int argc, char ** argv){
	int check = 0;
	string bin = "";

	if ( (argc != 2) || ((strcmp(argv[1],"8") != 0) && (strcmp(argv[1],"10") != 0) && (strcmp(argv[1], "12") != 0))) {
		do{
			cout << "Insert Board Size (8,10,or 12) Ex. If 8 then Enter '8' : " ;
			getline(cin,bin);
		} while ((bin != "8") && (bin != "10") && (bin != "12"));
	}
	else{
		bin = argv[1];
	}
	check = get_int(bin);

	return check;
	
}


//function: create_board
//description:  initializes the board & sets all values to 0
//parameters: takes in the board and rows and cols set by user
//pre: the board and that the user put in valid rows and cols
//post: board is created (just the array)

void create_board(int **board_array, int rows, int cols){

	board_array = new int*[rows];
	for (int i = 0; i < rows; i++){
		board_array[i] = new int[cols];

	}

}

//function: start_board
//description: creates starting board
//parameters: takes the board and the rows and columns of the board
//pre: the board should have values inputted or garbage
//post: board is set up

void start_board(int ** board_array, int rows, int cols){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			board_array[i][j] = 0;

		}
	}
	
	for (int i = rows/2 +1; i < rows; i++ ){
		for (int j = 0; j < cols; j++){
			if (((i%2 == 0) && (j%2 == 0 )) || ((i % 2 ==1) && ( j%2 ==1))){
				board_array[i][j] = 2;
			}
		}
	}
	for (int i = 0; i < (rows/2 -1); i++ ){
		for (int j = 0; j < cols; j++){
			if (((i%2 == 0) && (j%2 == 0 )) || ((i % 2 ==1) && ( j%2 ==1))){
				board_array[i][j] = 1;
			}
		}
	}
	for (int i = (rows/2 -1); i < (rows/2 +1); i++ ){
		for (int j = 0; j < cols; j++){
			board_array[i][j] = 5;
		}
	}
}
//function: print_board
//description: prints the board out
//parameters: takes the board and the rows and the columns of the board
//pre: board should have values
//post: board posted

void print_board( int ** board_array, int rows, int cols){
	cout << endl;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (i%2 == 0 && j%2 == 0){
				cout << "|\033[30;47m " <<  board_array[i][j] << " ";
			}
			else if (i % 2 == 1 && j %2 ==1){
				cout << "|\033[30;47m " << board_array[i][j] << " ";
			}
			else {
				cout << "|\033[0m " << board_array[i][j] << " ";
			}
			cout << "\033[0m";

		}
	cout << endl;
	}
	cout << endl;

}
//function: winner
//description: evaluates gameplay and determines when the game is over (when theres a winner)
//parameters: takes in the board and the playerscoreboard
//pre: there must be no winner
//post: game is over


bool winner( int ** boardarray, int * playerscore){
	bool end = 0;

	return end;

}


//function: playgame
//description: where gameplay actually occurs
//parameters: takes in the board and its rows and columns
//pre: board should have values
//post: board posted

int playgame(int ** boardarray, int rows, int cols){
	int playerscore[2] = {0,0};

	do{


	} while (winner != 1);
	

}




//MAIN_________________________________________________________________________________
int main(int argc, char**argv){
	int rows = 0, x = 0, cols = 0;
	int ** board_array;
	x = check_user_board(argc, argv); // add one for the row of indexes (A1)
	rows = x;
	cols = x;	
	board_array = new int*[rows];
	for (int i = 0; i < rows; i++){
		board_array[i] = new int[cols];
	}
	start_board(board_array,rows,cols);
	print_board(board_array,rows,cols);
	playgame(board_array,rows,cols);





	return 0;
}
