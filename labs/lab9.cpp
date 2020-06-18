#include <iostream>

using namespace std;



void print_array( int b[][3]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j< 3; j++){
			cout << b[i][j] << " ";				
		}
		cout << endl;
	} 



}

void move( int b[][3], int from_col, int to_col, int size){
	int hold = 0;

	for ( int i = 0; i < 3; i++){
		if (b[i][from_col] != 0 ){
			hold = b[i][from_col];
			b[i][from_col] = 0;
			break;
		}
	}
	

	for (int i = 2; i >= 0; i--){
		if (b[i][to_col] == 0){
			b[i][to_col] = hold;
			break;		
		}
	}
	
		
}

void towers(int disks, int b[][3], int from_col, int to_col, int spare){

	int size = 3;

	if (disks >= 1){
		towers(disks-1,b,from_col, spare, to_col);
		move(b, from_col,to_col,size);
		print_array(b);
		cout << endl;
		towers(disks-1,b, spare, to_col, from_col);
	
	}
}


int main(){
	

	int b[3][3] = {{1,0,0}, {2,0,0}, {3,0,0}};

	int disks = 0, from_col = 0, to_col = 2, spare = 1;
	towers(3,b,0,2,1);

//	print_array(b);


	return 0;
}	
