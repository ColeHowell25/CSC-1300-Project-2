#include <cmath>
/*defines left y coordinate at the entered x value from the trapezoidal integration loop
  Pre: x_left
  Post: Function y(x_left)*/
#define FXL (0.8*pow(x_left, 4) - 6.3*pow(x_left, 3) + 4.1)
/*defines right y coordinate at the entered x value from the trapezoidal integration loop
  Pre : x_right
  Post : function y(x_right)*/
#define FXR (0.8*pow(x_right, 4) - 6.3*pow(x_right, 3) + 4.1)