/*********************************************************************************/
/*** Title: Hangman_mc.cpp													   ***/
/*** Course: Computational Problem Solving CPET-121							   ***/
/*** Developer: Matthew Chu													   ***/
/*** Data: April 19, 2018                                                      ***/
/*** Description: Final Project: Hangman			                       	   ***/
/*********************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;

int gamestate=0;
bool game=true;
string word,strlog,guess,result,gallows[9]={"+\n|\n|\n|\n|\n|\n|","+----+\n|\n|\n|\n|\n|\n|",
					"+----+\n|    |\n|\n|\n|\n|\n|","+----+\n|    |\n|    O\n|\n|\n|\n|",
					"+----+\n|    |\n|    O \n|    | \n|    |\n| \n|",
					"+----+\n|    |\n|    O \n|   \\| \n|    |\n| \n|",
					"+----+\n|    |\n|    O \n|   \\|/ \n|    |\n| \n|",
					"+----+\n|    |\n|    O \n|   \\|/ \n|    |\n|   / \n|",
					"+----+\n|    |\n|    O \n|   \\|/ \n|    |\n|   / \\\n|"};

void SelectWord(){
	string tmp;
	srand(time(NULL));
	int n=rand()%30;
	ifstream inFile;
	inFile.open("words.txt");
	if(inFile.fail())
		exit(1);
	for(int i=0;i<30;i++){
		inFile >> tmp;
		if(i==n)
			word=tmp;
	}
	guess=word;
	result.insert(0,"The chosen word is "+word+".\n");
	for(unsigned int i=0;i<word.length();i++)
		guess.replace(i,1,"*");
	inFile.close();
}

void Draw(){
	cout << gallows[gamestate] << "\n+-------\n" << endl;
	for(unsigned int i=0;i<guess.length();i++)
		cout << guess[i] << " ";
	cout << endl;
	for(unsigned int i=0;i<guess.length();i++)
		cout << "- ";
	cout << endl;
}

void Guess(){
	int proceed=1;
	do{
		string input;
		int found=-1;
		cout << "Enter a letter: ";
		getline(cin,input);
		if(input.size()>1){
			if(input==word){
				cout << "You guessed the word!" << endl;
				guess=word;
				int in=result.size();
				result.insert(in,"\nThe string "+input+" is the word!");
				break;
			}
			else{
				cout << "That is not a letter!" << endl;
				int in=result.size();
				result.insert(in,"\nThe string "+input+" was not a letter!");
				continue;
			}
		}
		int out=strlog.size(), filled=-1;
		for(int i=0;i<out;i++){
			if((signed)strlog.find(input)==i){
				cout << "Already guessed." << endl;
				int in=result.size();
				result.insert(in,"\nThe character "+input+" was already guessed!");
				filled=out;
			}
		}
		if(filled==out)
			continue;
		strlog.insert(out,input);
		for(unsigned int i=0;i<guess.length();i++)
			if(word.find(input)==i)
				found=i;
		if(found>=0){
			guess.replace(found,1,input);
			int in=result.size();
			result.insert(in,"\nThe character "+input+" was found!");
			break;
		}
		else{
			gamestate++;
			int in=result.size();
			char err = '0' + gamestate;
			result.insert(in,"\nThe character "+input+" was not found! The error count is "+err+".");
			break;
		}
	}while(proceed==1);
}

void GameOver(){
	if(gamestate>=8){
		Draw();
		int in=result.length();
		result.insert(in,"\n\nThe user failed to find the word.");
		cout << "\n\nSorry. You've lost. :(\nThe word was " << word << ".\n\n" << endl;
		game=false;
	}
	if(word==guess){
		Draw();
		int in=result.length();
		result.insert(in,"\n\nThe user successfully found the word.");
		cout << "\n\nCongratulations!!! You Won!!!\n\n" << endl;
		game=false;
	}
}

int main(void)
{
	bool replay=false;
	while(replay==false){
		string play;
		SelectWord();
		do{
			Draw();
			Guess();
			GameOver();
		}while(game!=false);
		cout << "Do you want to play another game? (Y/N)";
		getline(cin,play);
		if(play=="yes" || play=="Yes" || play=="Y" || play=="y"){
			gamestate=0;
			game=true;
			result.erase(0);
			strlog.erase(0);
			continue;
		}
		else break;
	}
	ofstream outFile;
	outFile.open("result.txt");
	if(outFile.fail())
		exit(1);
	outFile << result;
	outFile.close();
	return 0;
}
/*********************************************************************************/
/
