#include "CurveDef1.h"
#include <iostream>

using namespace std;

int main(){
	
	int x0, xf, numberSections;
	double x_left, x_right;
	double area = 0.0;
	double areaTrap;
	
	cout << "Enter left x coordinate : ";
	cin >> x0;
	cout << "Enter right x coordinate : ";
	cin >> xf;
	cout << "Enter the number of sections : ";
	cin >> numberSections;
	x_left = x0; //sets initial x value
	
	
	double del_x = static_cast<double>((xf - x0))/numberSections; //interval between each trapezoid ie the width
	x_right = x0 + del_x; //final value for each individual trapezoid 
	
	for (int i = 0;i<numberSections;i++){ //approximates integral of function
		areaTrap = (del_x/2)*(FXL+FXR); //area of each trapezoid where FXL and FXR are the left and right heights of the respective trapezoid
		x_left = x_right; //shifts the left x point to where the old right one was
		x_right += del_x; //adds the interval to the old right x to the new right x
		area += areaTrap; //adds the previous values of the area of the trapezoids with each new iteration
		
	}
	cout << "The trapezoid method gives the approximate integral as = " << area << endl;
	return 0;
}