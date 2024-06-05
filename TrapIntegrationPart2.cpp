#include "CurveDef2.h"
#include <iostream>

using namespace std;



int main(){
	int t0, tf, numberSections;
	double tv_left, tv_right;
	double Velocity = 0.0;
	double Position = 0.0;
	double Velocity_new, Position_new;
	double tp_left, tp_right;
	double vtemp;
	double slope_v, offset;
	slope_v = 0;
	cout << "Enter t0 : ";
	cin >> t0;
	cout << "Enter tf : ";
	cin >> tf;
	cout << "Enter the number of sections : ";
	cin >> numberSections;
	tv_left = t0; //initial time for the velocity
	tp_left = t0; //initial time for the position
	
	double del_t = static_cast<double>((tf - t0))/numberSections; //calculates the interval for the integral of the acceleration wrt t
	double del_t2 = static_cast<double>(tf-t0)/numberSections/numberSections; //calculates the interval for the integral of the velocity wrt t
	tv_right = t0 + del_t; //final time for each trapezoid
	tp_right = t0 + del_t2;
	
	for (int i = 0;i<numberSections;i++){ //integrate the given acceleration functions
		Velocity_new = (del_t/2)*(FXL+FXR); //trapezoid with width delta t and height the sum of the function at the the initial and final points 
		tv_left = tv_right; //shifts the initial time for the velocity trapezoid to old final time 
		tv_right += del_t; //shifts the final point of trapezoid to new point
		vtemp = Velocity; //temporary velocity kept for slope calculation
		
		Velocity += Velocity_new; //adds the new velocity to the previous velocity from past iterations
		slope_v = (Velocity - vtemp)/del_t; //slope of line made between final velocity and the previous starting velocity
		offset = abs((vtemp-(slope_v*(tv_left-del_t)))); //offset required to take into account that using a line to approximate function will give a slightly wrong value for the slope
		
		for (int j=0;j<numberSections;j++){ //integrate the approximate function of the velocity
			Position_new = (del_t2/2)*((slope_v*tp_left-offset)+(slope_v*tp_right-offset)); //uses trapezoids where the new function is the line that approximates each original segment of the velocity graph as the height
			tp_left = tp_right; //updates the time intervals for the position
			tp_right = tp_left + del_t2;
			Position += Position_new; //adds calculated position for iteration to previous positions
		}
		
	}
	cout << "This is the Velocity : " << Velocity << endl;
	cout << "The trapezoid method gives the approximate position as = " << Position << endl;
	return 0;
}