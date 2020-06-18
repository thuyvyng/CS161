/*******************************************************
 * Program: panda.cpp
 * Author: Thuy-Vy Nguyen
 * Date: 18/1/18
 * Description: A panda maybe goes on an adventure
 * Input: 1 or 2
 * Output: Different paths
 * ***************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	
	cout << endl << "Panda Adventure Game!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	
	cout << "You are a panda." << endl << "You wake up and realize that you are hungry but also sleepy."
	 << endl << "Now you must decide whether you want to eat or sleep first. " << endl;
	
	cout << "Do you want to sleep or go out in search of food? " << endl << endl
	 << "Enter 0 for sleep and 1 for food. " << endl << endl; // ---------------------------------- First Question ------------------------

	int user1 = 0;
	int user2 = 0;
	int user3 = 0;

	cin >> user1;

	srand(time(NULL));
	int x,b;
	x = rand();
	b = x%2;
	
	
	if (user1 == 0){//----------------------------------------------------------------------------- Sleep Outcome-----------------------
		cout << endl << "You missed the adventure... But, hey sleep is important. " << endl;}
	else {
		cout << endl << "You leave your home and you can't decide whether to go left or right."  << endl<< "You decide to leave it to fate (aka a coin toss)." << endl;
		cout << "Heads is right. Left is tails" << endl << endl << endl << "You throw it up in the air and it turns out to be............ " << endl <<  endl << endl; //-------------- Heads or tails
	
					
		if (b == 0){
			cout << "It was heads! So we will go right" << endl << endl ; //--------------------------------turning right
			
			cout << "So you go walking around in search of bamboo and you can't seem to find any really good bamboo plots" << endl << "But then you find an empty and abandoned car with it's keys in. " << endl <<  "Maybe..." << endl << endl << "You should drive the car and find the bamboo because that would be faster... " << endl << endl;

			cout << endl << "If you want to hijack the car enter 0, and if you'd rather keep walking press 1" << endl << endl;
			
			cin >> user2;
			cout << endl;
//			if (user1 == 1) {
//				cout << "Hm okay... You go another half a mile and find a decent plot of bamboo where you decide to take a nap in. The end" << endl;}

			if (user2 == 0) {

				cout << "Great decision." << endl << endl << "So you hop into the car, turn that bad boy on and blast some sweet tunes." << endl << "Oh no! You have such a great time riding around in that car that you fail to realize you run out of gas!" << endl << "So you get out of the car and see a sign in the distance that says Oregon State University and you see someone in the distance" << endl;
				    
				    cout << endl << endl << "Should you ask for their help or should you wander and find the nearest gas station?" << endl << endl;

				    cout << endl <<"Enter 0 for help and 1 for wandering" << endl << endl;
				    
				    cin >> user3;

				    if (user3 == 0) {
					    cout << endl <<  "You go up to the girl and ask her where the nearest gas station is on her phone. She helps you get there and you guys become fast friends. You decide not to return home and become her new roommate at OSU. #GoBeavs!" << endl << endl << "The end" << endl;
					    }
					else {
						cout << endl << "You eventually stumble upon a gas station and figure that it's probably not best to fill up a car you don't own so instead of filling it up you fill up on junk food from the gas station and call an uber. What a day." << endl << endl << "The end" << endl; 
						}
			 }
			 else {
				 cout <<  endl << endl<< " Hm.. okay. You go another half a mile and find a decent plot of bamboo where you decide to take a nap. " << endl;
				 }
}
		else { cout << endl << "It was tails so let's go left" << endl;
		
			cout << endl << endl << "Oh frickity frack. You fall into a river. Ah! " << endl << "It turns out to be a cool while rocky water slide that takes you down the stream to a bamboo paradise. The end " << endl;
		} }
	return 0;
}
