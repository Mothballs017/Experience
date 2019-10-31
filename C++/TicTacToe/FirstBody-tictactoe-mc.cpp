/*
 * FirstBody-tictactoe-mc.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Batman
 */
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include "GlobalVar-tictactoe-mc.h"
#include "Draw-tictactoe-mc.h"
#include "ComputerTurn-tictactoe-mc.h"
#include "First-tictactoe-mc.h"

using namespace std;

//extra credit
void First(){
	srand(time(NULL));
	int num=(rand()%2);
	int coin;
	char choice;
	bool validChoice=false;
	while(validChoice!=true){
		cout << "Who will go first? Enter 'h' or 't' to determine who will go first.\n";
		cin >> choice;
		if(choice=='h')
			coin=0;
		if(choice=='t')
			coin=1;
		if(coin==num){
			cout << "You win the toss. You will go first." << endl;
			validChoice=true;
		}
		if(coin!=num){
			cout << "You lose the toss. You will not go first." << endl;
			ComputerTurn();
			validChoice=true;
		}
	}
}
