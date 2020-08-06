/*  C++ Algorithms 1

	Consider the following sequence – 0,1,1,2,3,5,8,13,21,34,55,89,144...

	1. Write an iterative function to return the nth element of the sequence.
	2. Write a recursive function to return the nth element of the sequence.
*/

#include <iostream>

int sequence(unsigned n) //recursive function
{
	if (n < 2)
		return n;
	return sequence(n - 1) + sequence(n - 2);
}

int iterative_fibonacci(unsigned n)
{
	int* arr = new int[n + 1];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int result = arr[n];
	delete[] arr;
	return result;
}

void main(int argc, char* argv[])
{
	std::cout << sequence(25) << std::endl;
}

