/*  C++ Advanced 4

	Examine the code below and make as many optimizations as you can.
*/

#include <iostream>

double deg2rad(double deg)
{
	return (deg * 3.14159265) / 180;
}

double compute_value(double degrees)
{
	return sin(deg2rad(degrees)) / cos(deg2rad(degrees));
}

void main(int argc, char* argv[])
{
	for (int degrees = 0; degrees <= 360; degrees++)
	{
		std::cout << degrees << ": " << compute_value((double)degrees) << std::endl;
	}
}