/*  C++ Maths 2
    
    Write a function WithinMaxAngle that checks if the angle between two arbitrary vectors is less than MAX_DEGREES.
*/

#include <iostream>

struct Vec3
{
    float x, y, z;
};

const float MAX_DEGREES = 43.f;

bool WithinMaxAngle(const Vec3 &v1, const Vec3 &v2)
{
	float a = acos((v1.x*v2.x + v1.y*v2.y + v1.z*v2.z) / (sqrt(v1.x*v1.x + v1.y*v1.y + v1.z*v1.z)*sqrt(v2.x*v2.x + v2.y*v2.y + v2.z*v2.z)));
	return (a*180.f / 3.14) <= MAX_DEGREES;
}

void main(int argc, char* argv[])
{
    Vec3 a = {1, 1, 1};
    Vec3 b = {0.3f, 0, 1};
    Vec3 c = {0.5f, 0, 1};
    std::cout << WithinMaxAngle(a, b) << std::endl;
    std::cout << WithinMaxAngle(a, c) << std::endl;
}