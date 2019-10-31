/*
 * ComputerTurnBody-tictactoe-mc.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Batman
 */
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "GlobalVar-tictactoe-mc.h"
#include "Draw-tictactoe-mc.h"
#include "Available-tictactoe-mc.h"
#include "ComputerTurn-tictactoe-mc.h"

using namespace std;

void ComputerTurn(){
	bool notValid=false;
	bool move;
	srand(time(NULL));
	while(notValid!=true){
		int num=(rand()%10);
		move=Available(num, comp);
		if(move==false)
			continue;
		else
			notValid=true;
	}
}
