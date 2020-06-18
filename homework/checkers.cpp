//author: thuyvy nguyen
//assignment: 6 checkers
//date: 18 march 2019
//description: checkers!
//input: command line and user input
//output: checkerboard




#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

//function: get_int
//description: atoi from previous assignment
//parameters: string
//pre: string
//post: int

int get_int(string bin){
	int res = 0;
	for (int i = 0; i <bin.length(); i++){
		int check = bin[i] - '0';
		int topower = int(bin.length()) -i -1;
		res = (int)((check*pow(10.0,topower)) + res);
	
	}
	return res;


}



//function: delete ptr
//description: deletes the pointer
//parameters: takes a double pointer
//pre: valid double pointer
//post: pointer is deleted no mem leaks


/*******************************************************/
//deleting the pointer, in order to set back to NULL properly
//it must by passed by pointer (or reference)
/*******************************************************/
void deletePtr(int **x){
    delete[] *x;
    *x = NULL;
}

// function: checkcommand
// description: checks the command line argument 
// parameters: takes command line argument
// pre: the executabe is used
// post: number is passed for board size

/****************************************************************/
int checkCommand(int argc, char **argv)
{
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

//function: displayboard
//description: prints out the board
//parameters: takes in the board size and the board array
//pre: there is no board
//post: board is printed out (appropriate board)
/****************************************************************/
void displayBoard(int boardSize, char *playerBoard[])
{
     if (boardSize == 8) cout << endl << "    | A | B | C | D | E | F | G | H |" << endl << endl;
     else if (boardSize == 10) cout << endl << "    | A | B | C | D | E | F | G | H | I | J |" << endl << endl;
     else if (boardSize == 12) cout << endl << "    | A | B | C | D | E | F | G | H | I | J | K | L |" << endl << endl;

     for(int i=0; i<boardSize; i++){
        if (i < 9) cout << " " << i+1 << "  ";
        else cout << " " << i+1 << " ";

        for(int j=0; j<boardSize; j++) {
            if ((i%2 == 0) && (j%2 == 1))
                cout << "|\033[0m " << playerBoard[i][j] << " ";
            else if ((i%2 == 1) && (j%2 == 0))
                cout << "|\033[0m " << playerBoard[i][j] << " ";
            else
                cout << "|\033[30;47m " << playerBoard[i][j] << " ";

            cout << "\033[0m";
        }
        cout << "|" << endl;
    }
}

// (same as above but its the inital board)
/****************************************************************/
void fillBoard(int boardSize, char *playerBoard[])
{
     for(int i=0; i<boardSize; i++){
         for(int j=0; j<boardSize; j++) {
             if (i < (boardSize/2-1)) {
                 if ((i%2 == 0) && (j%2 == 0))
                     playerBoard[i][j] = ' ';
                 else if ((i%2 == 1) && (j%2 == 1))
                     playerBoard[i][j] = ' ';
                 else
                     playerBoard[i][j] = 'o';
             }
             else if (i > (boardSize/2)) {
                 if ((i%2 == 0) && (j%2 == 0))
                     playerBoard[i][j] = ' ';
                 else if ((i%2 == 1) && (j%2 == 1))
                     playerBoard[i][j] = ' ';
                 else
                     playerBoard[i][j] = 'x';
             }
             else
                 playerBoard[i][j] = ' ';
         }
     }
}

//function: isbetween
//description:  Check and return if character is between a specify range
//parameters: the values (coordinates) and the board size
//pre: coordinates
//post: whether or not it is in between
/****************************************************************/
int  isbetween(int c, int start, int boardSize){

    int end = start + boardSize;

//cout << c << " : " << start << " : " << end << endl;

    return ((unsigned)c-start <= (end-start));
}
//function: checkXYentry
//description:
// Error handling for location enter
// Check for incorrect Entry Length or Combination Location
// Check for incorrect X location, must be A-H
// Check for incorrect Y location, must be 1-8
// Check for a need for an ',' between location
// parameters: coordinates from the user and the board size
// pre: the coordinates
// post: whether or not it was valid
/****************************************************************/
int checkXYentry(int *X, int *Y, int totalLocation, string ans, int num, int boardSize)
{
        if (isbetween(tolower(ans[0]),'a',boardSize) == 0) {
            cout << "\033[1;31mIncorrect 'X' location...\033[0m" << endl;
            return 0;
        }
        else if ((num < 1) || (num > boardSize)) {
            cout << "\033[1;31mIncorrect 'Y' location...\033[0m" << endl;
            return 0;
        }
        else {
            X[totalLocation] = tolower(ans[0]) - 97;  // 'a' = 97, 'b' = 98...
            Y[totalLocation] = num - 1;
            return 1;
        }
}
//function: enterXYlocation
//description:
// Player x/o Turn and entry move/capture location
// parameters: whose turn it is and their coordinates
// pre: it is users turn and they entered coordinates
// post: a string
/****************************************************************/
int enterXYlocation(int playerXYturn, int *X, int *Y, int boardSize)
{
    string ans = "";

    if ((playerXYturn = playerXYturn%2) == 0)
        cout << endl << "                 \033[4;34mPlayer 'X' Turn\033[0m" << endl << endl;
    else
        cout << endl << "                 \033[4;34mPlayer 'O' Turn\033[0m" << endl << endl;

    do{
        int totalLocation = 0;
        //                                                  3 5  8
        cout << "Enter location: A-H & 1-8. Ex) A3,B4 or A2,C4,E6,G8: ";
        getline(cin, ans);
        stringstream ss(ans);
        string tmp, tmp1;

        while (getline(ss, tmp, ',')) {
            tmp1[0] = tmp[1]; tmp1[1] = tmp[2];
            if (checkXYentry(X, Y, totalLocation, tmp, atoi(tmp1.c_str()), boardSize) == 0)
                break;
            totalLocation++;
        }

        if (totalLocation < 1)
            cout << "\033[1;31mIncorrect Entry Length or Combination Location...\033[0m" << endl;
        else
            return (totalLocation = totalLocation - 1);

    }while (1);
}
//function: diaglocation
//description:
// Compute and return diagnal location base from start & end entry location
// parameters: coordinates
// pre: user input
// post: where the piece goes
/****************************************************************/
int  diagLocation(int start, int end){
    int tmp;

    if (end > start)
        tmp = start + 1;
    else
        tmp = start - 1;

    return (tmp);
}
//function: checkvalid move
//description:
// Check location enter is a valid move
// return: 0 - invalid
//         2 - valid
//parameters: the coordinates and then the board
//pre: users input
//post: whether or not its a valid move
/****************************************************************/
int checkValidMove(int *column, int *row, char *playerBoard[])
{
    // Check if its a KING move backward
    if ((playerBoard[row[0]][column[0]] == 'x') && (row[1] >= row[0]) ||
        (playerBoard[row[0]][column[0]] == 'o') && (row[0] >= row[1])) {
        cout << "\033[1;31mNot a Valid Move...\033[0m" << endl;
        return 0;
    }

    if ((abs(row[0] - row[1]) != 1) || (abs(column[0] - column[1]) != 1)) {
        cout << "\033[1;31mNot a Valid Move location...\033[0m" << endl;
        return 0;
    }

    if ((tolower(playerBoard[row[0]][column[0]]) == 'x') && (tolower(playerBoard[row[1]][column[1]]) == ' ')) // Check Player X and empty location
        return 2;
    else if ((tolower(playerBoard[row[0]][column[0]]) == 'o') && (tolower(playerBoard[row[1]][column[1]]) == ' ')) // Check Player O and empty location
        return 2;
    else
        cout << "\033[1;31mNot a valid Move...\033[0m" << endl;

    return 0;
}
//function: checkvalidcapture
//description: 
// Check location enter is a valid capture
// return: 1 - invalid
//         3 - valid
//parameters: coordinates and the board
//pre: user has went
//post: checks if there was a capture
/****************************************************************/
int checkValidCapture(int *column, int *row, char *playerBoard[])
{
    int rowDiag, columnDiag;

    // Check if its a KING capture backward
    if ((playerBoard[row[0]][column[0]] == 'x') && (row[1] >= row[0]) ||
        (playerBoard[row[0]][column[0]] == 'o') && (row[0] >= row[1])) {
        cout << "\033[1;31mNot a Valid Capture location unless its a KING...\033[0m" << endl;
        return 1;
    }

    if ((abs(row[0] - row[1]) != 2) || (abs(column[0] - column[1]) != 2)) {
        cout << "\033[1;31mNot a Valid Capture location...\033[0m" << endl;
        return 1;
    }

    rowDiag = diagLocation(row[0], row[1]);
    columnDiag = diagLocation(column[0], column[1]);
    // Check Player X: O at diagnal and empty location
    if ((tolower(playerBoard[row[0]][column[0]]) == 'x') && (tolower(playerBoard[rowDiag][columnDiag]) == 'o') && (playerBoard[row[1]][column[1]] == ' '))
        return 3;
    else if ((tolower(playerBoard[row[0]][column[0]]) == 'o') && (tolower(playerBoard[rowDiag][columnDiag]) == 'x') && (playerBoard[row[1]][column[1]] == ' '))
        return 3;
    else
        cout << "\033[1;31mNot a valid Capture...\033[0m" << endl;

    return 1;
}

/****************************************************************/
//function: checkvalidmovecapture
//description:
// moveCapture value
// 0 >>> Invalid Move location
// 1 >>> Invalid Capture location
// 2 >>> Valid Move location
// 3 >>> Valid Capture location
// 4 >>> Invalid location, Capture only
// parameters: whose turn it is and where they wanna go
// pre: it is users turn
// post: check if they wanted to do a capture if its valid
int checkValidMoveCapture(int *column, int *row, char *playerBoard[], int playerXYturn)
{
    if ((tolower(playerBoard[row[0]][column[0]]) == 'x') && (playerXYturn == 1)) {
        cout << "\033[1;31mNot Player 'X' Turn...\033[0m" << endl;
        return 0;
    }

    if ((tolower(playerBoard[row[0]][column[0]]) == 'o') && (playerXYturn == 0)) {
        cout << "\033[1;31mNot Player 'O' Turn...\033[0m" << endl;
        return 0;
    }

    if ((abs(row[0] - row[1]) == 1) || (abs(column[0] - column[1]) == 1))  // Move
        return (checkValidMove(column, row, playerBoard));
    else                                                                   // Capture
        return (checkValidCapture(column, row, playerBoard));
}
//function: movecapture
//description:
// reassign x/o array/pointer data for move or capture
// moveCapture = 3 mean its a capture entry
//               check & remove diagnal piece
//               increament number of capture piece
// Check & convert to capital X/O letter if piece reach point to becoming KING
// parameters: boardsize, whose turn it is , scoreboard
// pre: users turn and tried to capture
// post: how many moves captured
/****************************************************************/
int MoveCapture(int boardSize, int playerXYturn, int moveCapture, int *column, int *row, char *playerBoard[], int *totalCapture)
{
    char tmp[1];
    
    tmp[0] = playerBoard[row[0]][column[0]];

    playerBoard[row[1]][column[1]] = tmp[0];

    if (moveCapture == 3) {
        playerBoard[diagLocation(row[0], row[1])][diagLocation(column[0], column[1])] = ' ';  // Clear Capture piece
        totalCapture[playerXYturn] = totalCapture[playerXYturn] + 1;   // Total piece Capture
    }

    playerBoard[row[0]][column[0]] = ' ';                              // Clear location

    // Check & convert piece to KING
    if ((playerXYturn == 0) && (row[1] == 0)) {
        playerBoard[row[1]][column[1]] = 'X';
        cout << endl << "Piece 'x' turn to King 'X'........" << endl << endl;
        return 99;
    }

    if ((playerXYturn == 1) && (row[1] == (boardSize-1))) {
        playerBoard[row[1]][column[1]] = 'O';
        cout << endl << "Piece 'o' turn to King 'O'........" << endl << endl;
        return 99;
    }

    return 2;
}

// Start location is in row/column[0]
// End location is in row/column[1]
// If entry was valid for continue capture, move x/o array/pointer to index 0 & 1


//function:checkcaptureagain
//description: if the user makes a capture this checks if they can keep capturing 
//parameters: it takes the current location and then checks it against where they want to go
//pre: they must have already captured
//post: how many of their opponents pieces they have captured




/****************************************************************/
void checkCaptureAgain(int i, int *column, int *row)
{
    row[0] = row[i-1];
    row[1] = row[i];
    column[0] = column[i-1];
    column[1] = column[i];
}

/****************************************************************/
int checkKingValidMove(int boardSize, char *playerBoard[])
{
    // Check for X or O KING available move
    for(int r=1; r<boardSize-1; r++) {
        for(int c=1; c<boardSize-1; c++) {
            if (((playerBoard[r][c] == 'X') || (playerBoard[r][c] == 'O')) &&
                (((playerBoard[r+1][c-1] == ' ') || (playerBoard[r+1][c+1] == ' ')) ||
                 ((playerBoard[r-1][c-1] == ' ') || (playerBoard[r-1][c+1] == ' '))))
                return 1;
            if (((playerBoard[0][c] == 'X') || (playerBoard[0][c] == 'O')) &&
                ((playerBoard[1][c-1] == ' ') || (playerBoard[1][c+1] == ' ')))
                return 1;
            if (((playerBoard[boardSize-1][c] == 'X') || (playerBoard[boardSize-1][c] == 'O')) &&
                ((playerBoard[boardSize-2][c-1] == ' ') || (playerBoard[boardSize-2][c+1] == ' ')))
                return 1;
        }
        if (((playerBoard[r][0] == 'X') || (playerBoard[r][0] == 'O')) &&
            ((playerBoard[r-1][1] == ' ') || (playerBoard[r+1][1] == ' ')))
            return 1;
        if (((playerBoard[r][boardSize-1] == 'X') || (playerBoard[r][boardSize-1] == 'O')) &&
            ((playerBoard[r-1][boardSize-2] == ' ') || (playerBoard[r+1][boardSize-2] == ' ')))
            return 1;
    }

    return 0;
}

/****************************************************************/
//function: checkallvalid moves
//description: (checks for all valid moves to determine when game over)
// moveCapture value
// 0 >>> Invalid Move location
// 1 >>> Invalid Capture location
// 2 >>> Valid Move location
// 3 >>> Valid Capture location
// 4 >>> Invalid location, Capture only
// parameters: boardsize and then the board
// pre: the board
// post: valid moves
int checkAllValidMove(int boardSize, char *playerBoard[])
{
    // Check for x available move
    for(int r=1; r<boardSize; r++) {
        for(int c=1; c<boardSize-1; c++)
            if ((playerBoard[r][c] == 'x') && ((playerBoard[r-1][c-1] == ' ') || (playerBoard[r-1][c+1] == ' ')))
                return 1;
        if (((playerBoard[r][0] == 'x') && (playerBoard[r-1][1] == ' ')) ||
            ((playerBoard[r][boardSize-1] == 'x') && (playerBoard[r-1][boardSize-2] == ' ')))
            return 1;
    }

    // Check for o available move
    for(int r=0; r<boardSize-1; r++) {
        for(int c=1; c<boardSize-1; c++)
            if ((playerBoard[r][c] == 'o') && ((playerBoard[r+1][c-1] == ' ') || (playerBoard[r+1][c+1] == ' ')))
                return 1;
        if (((playerBoard[r][0] == 'o') && (playerBoard[r+1][1] == ' ')) ||
            ((playerBoard[r][boardSize-1] == 'x') && (playerBoard[r+1][boardSize-2] == ' ')))
            return 1;
    }

    if (checkKingValidMove(boardSize, playerBoard) == 1)
        return 1;

    cout << endl << endl << "\033[1;31mNo more Valid Move available...\033[0m" << endl << endl;

    return 0;
}




//function: checkScoreMoveforWin
//description:checks score for win
//parameters: the board and the amount of captures
//pre: someone should be winning
//post: someone winning
/****************************************************************/
int checkScoreMoveForWin(int boardSize, int *totalCapture, char *playerBoard[])
{
    int gameEnd = 0;

    cout << endl << "Total 'O' piece Capture by 'X' = " << totalCapture[0] << endl;
    cout << "Total 'X' piece Capture by 'O' = " << totalCapture[1] << endl;

    // All player O piece capture by Player X
    if (((boardSize == 8)  && ((totalCapture[0] == 12) || (totalCapture[1] == 12))) ||
        ((boardSize == 10) && ((totalCapture[0] == 20) || (totalCapture[1] == 20))) ||
        ((boardSize == 12) && ((totalCapture[0] == 30) || (totalCapture[1] == 30))))
        gameEnd = 1;

    // No more valid move available
    if ((checkAllValidMove(boardSize, playerBoard) == 0) || (gameEnd == 1)) {
        if (totalCapture[0] > totalCapture[1]) {
            cout<< endl << "\033[1;34mPlayer 'X' win with Capture " << totalCapture[0] << " 'O' pieces\033[0m" << endl;
            cout << "Player 'O' capture: " << totalCapture[1] << " 'X' pieces." << endl << endl;
        } else if (totalCapture[0] < totalCapture[1]) {
            cout<< endl << "\033[1;34mPlayer 'O' win with Capture " << totalCapture[1] << " 'X' pieces\033[0m" << endl;
            cout << "Player 'X' capture: " << totalCapture[0] << " 'X' pieces." << endl << endl;
        } else
            cout<< endl << "Tie Games " << endl;
    } else
        return 0;
        
    return 1;
}

/****************************************************************/
//function: checkwinner
//description: checks winner
//parameters: board size how many captures and the board
//pre: someone wins
//post: game over
int checkWinner(int boardSize, int *totalCapture, char *playerBoard[])
{
    string ans = "";

    if (checkScoreMoveForWin(boardSize, totalCapture, playerBoard) == 0)
        return 0;

    do {
        cout << endl << endl << "Do you want to play new games (y/n) ? ";
        getline(cin,ans);
        if (ans[0] == 'y') {
            return 1;
	}
    } while (ans[0] != 'n');

    cout << endl << endl << "Good Bye!!! " << endl << endl;

    return 2;
}
//function:checkmovecapture
//description: check if capture is valid
//parameters: board, whose turn it is and the row and columns and the board and how many captures
//pre: user wants to capture
//post: whether its valid or not
/****************************************************************/
int checkMoveCapture(int boardSize, int playerXYturn, int moveCapture, int *column, int *row, char *playerBoard[], int *totalCapture)
{
    int winner = 0;

    do {
        int totalLocation = enterXYlocation(playerXYturn, column, row, boardSize);

        moveCapture = checkValidMoveCapture(column, row, playerBoard, playerXYturn);
        if ((moveCapture > 1) && (moveCapture < 4)) {
            for (int i = 0; i < totalLocation; i++) {
                if (MoveCapture(boardSize, playerXYturn, moveCapture, column, row, playerBoard, totalCapture) == 99)
                    i = 99;
                displayBoard(boardSize, playerBoard);

                if ((winner = checkWinner(boardSize, totalCapture, playerBoard)) != 0)
                    break;

                if (i < (totalLocation - 1)) {
                    checkCaptureAgain(i+2, column, row);
                    if ((moveCapture = checkValidCapture(column, row, playerBoard)) != 3)
                        i = 99;
                }
            }

        playerXYturn = (playerXYturn + 1) % 2;
        }
    } while (winner == 0);
    
    return (winner);
}
//function: deletedynmicptr
//description: delete pointers
//parameters: all the arrays
//pre: game over
//post: no memory leaks!!!1
/****************************************************************/
void deleteDynmicPtr(int *column, int *row, int *totalCapture)
{
    deletePtr(&totalCapture);
    deletePtr(&row);
    deletePtr(&column);
}

/****************************************************************/
// playerXYturn
// 0 = X Player
// 1 = O Player
// totalLocation: report how may location Player enter
// moveCapture: check to see if entry is move, capture and valid
// MoveCapture function: perform actuall move or capture
// displayBoard function = printout x/o array/pointer in Board Games
// Continue capture if entry was valid
// switch player when all location/move exhaust




//function: playchecker
//description: overall checkers functions
//parameters: board size (from command line) and then the board
//pre: board created from command line argument
//post: the game will play
int playChecker(int boardSize, char *playerBoard[])
{
    int *totalCapture = new int[2], *row = new int[boardSize], *column = new int[boardSize];
    int validMoveCapture, tmpPlayerXYturn, playerXYturn = 0, moveCapture = 0, winner = 0;

    totalCapture[0] = 0;  totalCapture[1] = 0;

    winner = checkMoveCapture(boardSize, playerXYturn, moveCapture, column, row, playerBoard, totalCapture);

    deleteDynmicPtr(column, row, totalCapture);

    return (winner);
}

// Parsing Command line: Executable Numberi
// // Number = Boardsize
// fillBoard function = default x/o array/pointer in Board Games
// displayBoard function = printout x/o array/pointer in Board Games
// playChecker fuction = start playing checker
// Free dynamic memory for x/o array/pointer
/****************************************************************/
int main(int argc, char **argv)
{
    int playAgain = 0;
    char** playerBoard;

    int boardSize = checkCommand(argc, argv);

    playerBoard = new char*[boardSize];
    for (int i=0; i<boardSize; i++)
        playerBoard[i] = new char [boardSize];

    do {
        fillBoard(boardSize, playerBoard);

        displayBoard(boardSize, playerBoard);

        playAgain = playChecker(boardSize, playerBoard);

    } while (playAgain == 1);

    for(int i=0; i<boardSize; i++)
        delete [] playerBoard[i];
    delete [] playerBoard;

    return 0;
}
