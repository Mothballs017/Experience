/*
 * AvailableBody-tictactoe-mc.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Batman
 */

#include <iostream>
#include <iomanip>
#include "GlobalVar-tictactoe-mc.h"
#include "Draw-tictactoe-mc.h"
#include "Available-tictactoe-mc.h"

using namespace std;

bool Available(int spot, char player){
	bool unavailable=false;
	if(spot==1){
		if(pos1==user || pos1==comp){
			if(player==user)
				cout << "Invalid input: position already occupied." << endl;
			return unavailable;
		}
		else{
			if(player==comp)
				cout << "Computer chose position " << pos1 << endl;
			pos1=player;
			return !unavailable;
		}
	}
	if(spot==2){
		if(pos2==user || pos2==comp){
			if(player==user)
				cout << "Invalid input: position already occupied." << endl;
			return unavailable;
		}
		else{
			if(player==comp)
				cout << "Computer chose position " << pos2 << endl;
			pos2=player;
			return !unavailable;
		}
	}
	if(spot==3){
		if(pos3==user || pos3==comp){
			if(player==user)
				cout << "Invalid input: position already occupied." << endl;
			return unavailable;
		}
		else{
			if(player==comp)
				cout << "Computer chose position " << pos3 << endl;
			pos3=player;
			return !unavailable;
		}
	}
	if(spot==4){
		if(pos4==user || pos4==comp){
			if(player==user)
				cout << "Invalid input: position already occupied." << endl;
			return unavailable;
		}
		else{
			if(player==comp)
				cout << "Computer chose position " << pos4 << endl;
			pos4=player;
			return !unavailable;
		}
	}
	if(spot==5){
		if(pos5==user || pos5==comp){
			if(player==user)
				cout << "Invalid input: position already occupied." << endl;
			return unavailable;
		}
		else{
			if(player==comp)
				cout << "Computer chose position " << pos5 << endl;
			pos5=player;
			return !unavailable;
		}
	}
	if(spot==6){
		if(pos6==user || pos6==comp){
			if(player==user)
				cout << "Invalid input: position already occupied." << endl;
			return unavailable;
		}
		else{
			if(player==comp)
				cout << "Computer chose position " << pos6 << endl;
			pos6=player;
			return !unavailable;
		}
	}
	if(spot==7){
		if(pos7==user || pos7==comp){
			if(player==user)
				cout << "Invalid input: position already occupied." << endl;
			return unavailable;
		}
		else{
			if(player==comp)
				cout << "Computer chose position " << pos7 << endl;
			pos7=player;
			return !unavailable;
		}
	}
	if(spot==8){
		if(pos8==user || pos8==comp){
			if(player==user)
				cout << "Invalid input: position already occupied." << endl;
			return unavailable;
		}
		else{
			if(player==comp)
				cout << "Computer chose position " << pos8 << endl;
			pos8=player;
			return !unavailable;
		}
	}
	if(spot==9){
		if(pos9==user || pos9==comp){
			if(player==user)
				cout << "Invalid input: position already occupied." << endl;
			return unavailable;
		}
		else{
			if(player==comp)
				cout << "Computer chose position " << pos9 << endl;
			pos9=player;
			return !unavailable;
		}
	}
	else return unavailable;
}
