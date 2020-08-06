/*  C++ Basic 4

	Explain the result of running the program. Explain how its execution will end.
*/

#include <iostream>

void main(int argc, char* argv[])
{
	int c = 0;
	while (c < 5, ++c)
		std::cout << c << std::endl;
}

// the program is endless, because of the '++c' in the while loop, because it always returns value > 0 and that means 'true' for the loop
// for example if it was 'c++' it even won't start because 'c++' when c=0 -> returns 0
// but when c=0, '++c' -> return 1 and on the other iterations it only increases and the loop doesn't end because '++c' when c>=0 is always true for the loop