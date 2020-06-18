#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

int fib_iter(int n){
	int prev = 0;
	int prev2;
	int current = 0;
	for (int i = 0; i < n; i++){
		if ( i == 1)
			current = 1;
		prev = prev2;
		prev2 = current;
		current = prev + prev2;
		
	}
	return current;
}

int fib_recurse(int n){
	if( ( n == 1) || (n == 0)){
		return n;	
	}
	return fib_recurse(n-2) + fib_recurse(n-1);

}

int main(){

	typedef struct timeval time;
	time stop, start;

	int answ = 0;
	cout << "Insert number: ";
	cin >> answ;
//	int sup = fib_recurse(answ);
//	cout << sup << endl;

//	int yoooo = fib_iter(answ);
//	cout << yoooo << endl;



	gettimeofday(&start, NULL);
	//time your iterative or recursive function here
	
	cout << fib_recurse(answ) << endl;

	gettimeofday(&stop,NULL);

	if(stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;



	gettimeofday(&start, NULL);
	//time your iterative or recursive function here
	
	cout <<  fib_iter(answ) << endl;
	gettimeofday(&stop,NULL);

	if(stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
	
	cout << "How many steps do you have? " << endl;
	int steps = 0;
	cin >> steps;

	cout << fib_recurse(steps+1) << "is how many options you have" << endl;

	
	return 0;
}



