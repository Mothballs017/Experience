/*********************************************************************************/
/*** Title: ImageRotation_mc.cpp									 		   ***/
/*** Course: Computational Problem Solving CPET-121							   ***/
/*** Developer: Matthew Chu													   ***/
/*** Data: Feb 1, 2018                                                         ***/
/*** Description: - Converting Polar <-> Rectangular Coordinates               ***/
/***			  - Image Rotation                                             ***/
/*********************************************************************************/

#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main(){

	float height, width, angle;

	cout << "Enter the Width of the Image: ";
	cin >> width;
	cout << "Enter the Height of the Image: ";
	cin >> height;
	cout << "Enter the Angle of Rotation: ";
	cin >> angle;

	//bottom left corner
	float Cx0 = 0;
	float Cy0 = 0;
	//bottom right corner
	float Cx1 = width;
	float Cy1 = 0;
	//top right corner
	float Cx2 = width;
	float Cy2 = height;
	//top left corner
	float Cx3 = 0;
	float Cy3 = height;
	//temp vars to store converted coord
	float tmpx0, tmpy0, tmpx1, tmpy1, tmpx2, tmpy2, tmpx3, tmpy3;
	float Dx0, Dy0, Dx1, Dy1, Dx2, Dy2, Dx3, Dy3;

	//rect to polar conversion
	Dx0 = sqrt(pow(Cx0,2.0)+pow(Cy0,2.0));
	Dy0 = atan2(Cy0, Cx0)*180.0/M_PI;
	Dx1 = sqrt(pow(Cx1,2.0)+pow(Cy1,2.0));
	Dy1 = atan2(Cy1, Cx1)*180.0/M_PI;
	Dx2 = sqrt(pow(Cx2,2.0)+pow(Cy2,2.0));
	Dy2 = atan2(Cy2, Cx2)*180.0/M_PI;
	Dx3 = sqrt(pow(Cx3,2.0)+pow(Cy3,2.0));
	Dy3 = atan2(Cy3, Cx3)*180.0/M_PI;

	//store polar coord
	tmpx0 = Dx0;
	tmpy0 = Dy0;
	tmpx1 = Dx1;
	tmpy1 = Dy1;
	tmpx2 = Dx2;
	tmpy2 = Dy2;
	tmpx3 = Dx3;
	tmpy3 = Dy3;

	//rewrite vars to hold rect coord
	Dx0 = tmpx0*cos(((tmpy0+angle)*M_PI/180.0));
	Dy0 = tmpx0*sin(((tmpy0+angle)*M_PI/180.0));
	Dx1 = tmpx1*cos(((tmpy1+angle)*M_PI/180.0));
	Dy1 = tmpx1*sin(((tmpy1+angle)*M_PI/180.0));
	Dx2 = tmpx2*cos(((tmpy2+angle)*M_PI/180.0));
	Dy2 = tmpx2*sin(((tmpy2+angle)*M_PI/180.0));
	Dx3 = tmpx3*cos(((tmpy3+angle)*M_PI/180.0));
	Dy3 = tmpx3*sin(((tmpy3+angle)*M_PI/180.0));

	cout << right;
	cout << fixed << setprecision(2) << "\nC0(" << setw(6) << Cx0 << ", " << setw(6) << Cy0 << ") --> D0(" << setw(6) << Dx0 << ", " << setw(6) <<Dy0 << ")";
	cout << "\nC1(" << setw(6) << Cx1 << ", " << setw(6) << Cy1 << ") --> D1(" << setw(6) << Dx1 << ", " << setw(6) << Dy1 << ")";
	cout << "\nC2(" << setw(6) << Cx2 << ", " << setw(6) << Cy2 << ") --> D2(" << setw(6) << Dx2 << ", " << setw(6) << Dy2 << ")";
	cout << "\nC3(" << setw(6) << Cx3 << ", " << setw(6) << Cy3 << ") --> D3(" << setw(6) << Dx3 << ", " << setw(6) << Dy3 << ")";
	return 0;
}
/*****************************************************************************************************/

