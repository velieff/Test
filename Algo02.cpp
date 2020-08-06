/*  C++ Algorithms 2

	Write a function that removes K random elements from a std::vector.
	The function should work in place, but does not need to preserve the order of elements.
*/

#include <iostream>
#include <vector>
#include <stdlib.h>

void removeK(std::vector<int>& v, unsigned k)
{
	for (int i = 0; i < k; i++)
	{
		int temp = rand() % v.size();
		v.erase(v.begin() + temp);
	}
}

void main(int argc, char* argv[])
{
	std::vector<int> arr;
	for (int i = 0; i < 50; ++i)
		arr.push_back(i);

	removeK(arr, 5);

	for (auto i : arr)
		std::cout << i << std::endl;
}
