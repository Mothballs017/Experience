/*********************************************************************************/
/*** Title: PolarToRectangular_mc.cpp								 		   ***/
/*** Course: Computational Problem Solving CPET-121							   ***/
/*** Developer: Matthew Chu													   ***/
/*** Data: Feb 1, 2018                                                         ***/
/*** Description: Converting Polar <-> Rectangular Coordinates                 ***/
/*********************************************************************************/

#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main(){
	char type;
	float posx, posy;
	float rx, ry, px, py;

	cout << "Enter the coordinates followed by R/r or P/p";
	cin >> posx >> posy >> type;

	switch(type){
	case 'r':
	case 'R':
		rx = posx;
		ry = posy;
		cout << "Rectangular..: (" << fixed << setprecision(2) << rx << ", " << ry << ")";
		px = sqrt(pow(posx,2.0)+pow(posy,2.0));
		py = atan2(posy, posx)*180.0/M_PI;
		cout << "\nPolar........: (" << setprecision(2) << px << " @ " << py << ")";
	case 'p':
	case 'P':
		px = posx;
		py = posy;
		rx = posx*cos(posy*M_PI/180.0);
		ry = posx*sin(posy*M_PI/180.0);
		cout << "Rectangular..: (" << fixed << setprecision(2) << rx << ", " << ry << ")";
		cout << "\nPolar........: (" << setprecision(2) << px << " @ " << py << ")";
	}

	return 0;
}
/*********************************************************************************/

