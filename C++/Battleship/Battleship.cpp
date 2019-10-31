/*********************************************************************************/
/*** Title: Battleship_mc.cpp										 		   ***/
/*** Course: Computational Problem Solving CPET-121							   ***/
/*** Developer: Matthew Chu													   ***/
/*** Data: March 29, 2018                                                      ***/
/*** Description: Battleship Game								               ***/
/*********************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>

using namespace std;

/* 7x7 grid
 * Destroyer : 2 pos
 * Submarine : 3 pos
 * Battleship: 4 pos
 */

char ocean[7][7]; //display ocean
char print[7][7];
int shiplog[7][7]; //log of finished hits
int guesscount=0;
int destroyer=2,submarine=3,battleship=4;

void Draw(){
	char y[7]={'A','B','C','D','E','F','G'};
	int letter=0;
	cout << "  | 1 | 2 | 3 | 4 | 5 | 6 | 7 |" << endl;
	for(int i=0;i<15;i++){
		if(i%2==0 || i==0)
			cout << "--+---+---+---+---+---+---+---+" << endl;
		if(i%2==1){
			cout << y[letter] << " | ";
			for(int m=0;m<7;m++){
				cout << ocean[letter][m] << " | ";     //
			}
			cout << "\n";
			letter++;
		}
	}
}

void PlaceShip(int ship){
	//random location - done
	//check occupied - done
	//check direction (up/down)
	//check overlap
	bool placed=false;
	while(placed!=true){
		srand(time(NULL));
		//chose a spot
		int shipx=(rand()%(7-ship))+ship;
		int shipy=(rand()%(7-ship))+ship;
		//makes sure it isnt occupied
		do{
			shipx=(rand()%(7-ship))+ship;
			shipy=(rand()%(7-ship))+ship;
		}while(shiplog[shipy][shipx]!=0);
		//pick direction
		int direction=rand()%2; //0 is up, 1 is left
		//if direction is up/0, then checks occupied
		for(int i=shipy;i>shipy-ship;i--)
			if(shiplog[i][shipx]!=0)
				direction=2;
		//if occupied, repeat loop
		if(direction==2)
			continue;
		//if empty, place ship
		if(direction==0){
			for(int i=shipy;i>shipy-ship;i--)
				shiplog[i][shipx]=ship;
//				print[i][shipx]='H';
			break;
		}
		//if direction is down/1, then checks occupied
		for(int i=shipx;i>shipx-ship;i--)
			if(shiplog[shipy][i]!=0)
				direction=2;
		//if occupied, repeat loop
		if(direction==2)
			continue;
		//if empty, place ship
		if(direction==1){
			for(int i=shipx;i>shipx-ship;i--)
				shiplog[shipy][i]=ship;
//				print[shipy][i]='H';
			break;
		}
	}
}

void Shoot(){
	int col, rownum;
	char row, letter[7]={'A','B','C','D','E','F','G'};
	bool valid=false;
	do{
		int sank=0;
		cout << "Enter Your Guess (C [1-7] / R [A-G]) : ";
		cin >> col >> row;
		guesscount++;
		if((col<=7 && col>=1) && (row=='A' || row=='a' || row=='B' || row=='b' ||
				row=='C' || row=='c' || row=='D' || row=='d' || row=='E' || row=='e' ||
				row=='F' || row=='f' || row=='G' || row=='g')){
			col-=1;
			for(int i=0;i<7;i++)
				if(letter[i]==row)
					rownum=i;
			cout << "********************************\n";
			if(shiplog[rownum][col]>1){
				cout << "**           HIT              **\n";
				if(shiplog[rownum][col]==destroyer){
					shiplog[rownum][col]=1;
					ocean[rownum][col]='H';
					for(int i=0;i<7;i++)
						for(int k=0;k<7;k++)
							if(shiplog[i][k]==destroyer)
								sank=1;
					if(sank==0)
						cout << "**   YOU SANK MY DESTROYER    **\n";

				}
				if(shiplog[rownum][col]==submarine){
					shiplog[rownum][col]=1;
					ocean[rownum][col]='H';
					for(int i=0;i<7;i++)
						for(int k=0;k<7;k++)
							if(shiplog[i][k]==submarine)
								sank=1;
					if(sank==0)
						cout << "**   YOU SANK MY SUBMARINE    **\n";
				}
				if(shiplog[rownum][col]==battleship){
					shiplog[rownum][col]=1;
					ocean[rownum][col]='H';
					for(int i=0;i<7;i++)
						for(int k=0;k<7;k++)
							if(shiplog[i][k]==battleship)
								sank=1;
					if(sank==0)
						cout << "**   YOU SANK MY BATTLESHIP   **\n";
				}
				cout << "********************************\n"
						"Press any key to continue . . .\n\n";
				valid=true;
			}
			else{
				if(shiplog[rownum][col]==1)
					cout << "**        ALREADY GUESSED     **\n";
				if(shiplog[rownum][col]==0){
					ocean[rownum][col]='M';
					shiplog[rownum][col]=1;
					cout << "**           MISS             **\n";
				}
				cout <<	"********************************\n"
					"Press any key to continue . . .\n\n";
				valid=true;
			}
		}
		else{
			cout << "Format Error... Please Reenter\nPress any key to continue . . .";
			continue;
		}
	}while(valid!=true);
}

bool GameOver(){
	for(int i=0;i<7;i++)
		for(int k=0;k<7;k++)
			if(shiplog[i][k]>1)
				return false;
	return true;
}

int main(){
	bool game=true;
	for(int i=0;i<7;i++)
		for(int k=0;k<7;k++){
			ocean[i][k]=' ';
			print[i][k]='M';
			shiplog[i][k]=0;
		}
	Draw();
	PlaceShip(destroyer);
	PlaceShip(submarine);
	PlaceShip(battleship);
//	Draw();
	while(game!=GameOver()){
		Shoot();
		Draw();
	}
	cout << setw(32) <<
			"********************************\n"
			"** GAME OVER                  **\n"
			"** GUESS COUNT       = " << guesscount << "     **\n"
			"** GUESS EFFICIENCY = " << setprecision(3) << 9.0/guesscount * 100.0 << "%   **\n"
			"********************************\n"
			"Press any key to continue . . .\n\n";
	return 0;
}
