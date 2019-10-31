/*
 * MarkerBody-tictactoe-mc.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Batman
 */
#include <iostream>
#include <iomanip>
#include "GlobalVar-tictactoe-mc.h"
#include "Draw-tictactoe-mc.h"
#include "Marker-tictactoe-mc.h"

using namespace std;

//extra credit
void Marker(){
	bool validChoice=false;
	while(validChoice!=true){
		char choice;
		cout << "But first, would you like to be X? or O?\n";
		cin >> choice;
		if(choice==user || choice=='x'){
			cout << "Player is X  |  Computer is O\n" << endl;
			break;
		}
		if(choice==comp || choice=='o'){
			char tmp=comp;
			comp=user;
			user=tmp;
			cout << "Player is O  | Computer is X\n" << endl;
			validChoice=true;
		}
	}
}
