/*
 * CheckWinnerBody-tictactoe-mc.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Batman
 */

#include <iostream>
#include "GlobalVar-tictactoe-mc.h"
#include "Draw-tictactoe-mc.h"
#include "CheckWinner-tictactoe-mc.h"

using namespace std;

bool CheckWinner(){
	if(pos1==pos2 && pos2==pos3){
		if(pos1==user){
			winner=user;
		}
		else{
			winner=comp;
		}
		return true;
	}
	if(pos4==pos5 && pos5==pos6){
		if(pos4==user){
			winner=user;
		}
		else{
			winner=comp;
		}
		return true;
	}
	if(pos7==pos8 && pos8==pos9){
		if(pos7==user){
			winner=user;
		}
		else{
			winner=comp;
		}
		return true;
	}
	if(pos1==pos4 && pos4==pos7){
		if(pos1==user){
			winner=user;
		}
		else{
			winner=comp;
		}
		return true;
	}
	if(pos2==pos5 && pos5==pos8){
		if(pos2==user){
			winner=user;
		}
		else{
			winner=comp;
		}
		return true;
	}
	if(pos3==pos6 && pos6==pos9){
		if(pos7==user){
			winner=user;
		}
		else{
			winner=comp;
		}
		return true;
	}
	if(pos1==pos5 && pos5==pos9){
		if(pos5==user){
			winner=user;
		}
		else{
			winner=comp;
		}
		return true;
	}
	if(pos7==pos5 && pos5==pos3){
		if(pos7==user){
			winner=user;
		}
		else{
			winner=comp;
		}
		return true;
	}
	if(pos1!='1' && pos2!='2' && pos3!='3' && pos4!='4' && pos5!='5'
			&& pos6!='6' && pos7!='7' && pos8!='8' && pos9!='9'){
		winner='t';
		return true;
	}
	else return false;
}
