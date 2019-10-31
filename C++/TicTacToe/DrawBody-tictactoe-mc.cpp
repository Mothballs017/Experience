/*
 * DrawBody-tictactoe-mc.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Batman
 */

#include <iostream>
#include <iomanip>
#include "GlobalVar-tictactoe-mc.h"
#include "Draw-tictactoe-mc.h"

using namespace std;

void Draw(){
	cout << left << "User (" << user << ")  -  Computer (" << comp << ")\n\n" << endl;
	for(int i=0; i<9; i++){
		if(i==0 || i==3 || i==6 || i==8)
			cout << "     |     |     " << endl;
		if(i==1)
			cout << "  " << pos1 << "  |  " << pos2 << "  |  " << pos3 << "  " << endl;
		if(i==4)
			cout << "  " << pos4 << "  |  " << pos5 << "  |  " << pos6 << "  " << endl;
		if(i==7)
			cout << "  " << pos7 << "  |  " << pos8 << "  |  " << pos9 << "  " << endl;
		if(i==2 || i==5)
			cout << "_____|_____|_____" << endl;
	}
}
