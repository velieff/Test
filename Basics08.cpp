/*  C++ Basics 8

	1.	Write a specialization for type int for the 'add' template function.
	2.	Give an example of partial template specialization for class 'Fu' . For example if both array1 and array2 store pointers make them twice as big.
*/

#include<iostream>


template <typename T> T add(T a, T b)
{
	return a + b;
}
template <>
int add<int>(int a, int b)
{
	std::cout << "This is template for int: ";
	return a + b;
}


template <typename T, typename U, int n> class Fu
{
public:
	T array1[n];
	U array2[n];

	void f() { std::cout << "Fu<T,U,n>"; }
};

template<class T, class U, int n>
class Fu<T*, U*, n>
{
public:
	T array1[2 * n];
	U array2[2 * n];
	void f() { std::cout << "Fu<T*,U*,n>"; }
};


void main(int argc, char* argv[])
{
	std::cout << add<int>(1, 2);
}