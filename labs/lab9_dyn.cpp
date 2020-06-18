#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



void print_array( int** b, int rows, int cols){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j< cols; j++){
			cout << b[i][j] << " ";				
		}
		cout << endl;
	} 



}

void move( int** b, int from_col, int to_col, int rows){
	int hold = 0;

	for ( int i = 0; i < rows ; i++){
		if (b[i][from_col] != 0 ){
			hold = b[i][from_col];
			b[i][from_col] = 0;
			break;
		}
	}
	

	for (int i = rows-1; i >= 0; i--){
		if (b[i][to_col] == 0){
			b[i][to_col] = hold;
			break;		
		}
	}
	
		
}

void towers(int disks, int** b, int from_col, int to_col, int spare, int rows, int cols){

	int size = 3;

	if (disks >= 1){
		towers(disks-1,b,from_col, spare, to_col, rows, cols);
		move(b, from_col,to_col, rows);
		print_array(b,rows,cols);
		cout << endl;
		towers(disks-1,b, spare, to_col, from_col, rows, cols);
	
	}
}




int main(int argc, char **argv){

	int n = 0;
	n = atoi( argv[1]) ;


	int **b;
	b = new int*[n];
	for (int i = 0; i < n; i++){
		b[i] = new int[3];
	}


	for (int i = 0; i < n ; i++){
		for (int j = 0; j < 3; j++){
			b[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++){
		b[i][0] = i + 1;
	}

//	print_array(b,n,3);
//	int disks = 0, from_col = 0, to_col = 2, spare = 1;
	towers(n,b,0,2,1,n,3);


	for (int i = 0; i < n; i++){
		delete [] b[i];
	}

	delete [] b;


	return 0;
}	
