/*  C++ Basics 1

	Unify the definitions of the two sumArray functions into one template function.
*/

#include <iostream>

template <class T>
T sumArray(T *a, int count)
{
	T sum = 0;
	for (int i = 0; i < count; ++i)
		sum += a[i];
	return sum;
}

void main(int argc, char* argv[])
{
	int a[5] = { 1, 2, 3, 4, 5 };
	float f[5] = { 0.f, 1.f, 2.f, 3.f, 4.f };

	std::cout << sumArray<int>(a, 5) << " " << sumArray<float>(f, 5) << std::endl;
}