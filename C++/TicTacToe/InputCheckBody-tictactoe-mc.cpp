/*
 * InputCheckBody-tictactoe-mc.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Batman
 */

#include <iostream>
#include <iomanip>
#include "GlobalVar-tictactoe-mc.h"
#include "Draw-tictactoe-mc.h"
#include "Available-tictactoe-mc.h"
#include "InputCheck-tictactoe-mc.h"

using namespace std;

void InputCheck(){
	bool notValid=false;
	bool move;
	while(notValid!=true){
		cout << "Enter your position: ";
		cin >> position;
		if(position==999){
			gameOver=true;
			break;
		}
		if(position<=0||position>=10){
			cout << "Invalid input: the position indicator has to be in the range of 1 to 9" << endl;
		}
		else{
			move=Available(position, user);
			if(move==false)
				continue;
			else
				notValid=true;
		}
	}
}
