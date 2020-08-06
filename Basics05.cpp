/*  C++ Basics 5

	Explain what is the problem with the code below and how it should be avoided?
*/

#include <iostream>

using namespace std;

class Sample
{
public:
	int *ptr;
	Sample(int i)
	{
		ptr = new int(i);
	}
	~Sample()
	{
		delete ptr;
	}
	void PrintVal()
	{
		cout << "The value is " << *ptr;
	}
};

void SomeFunc(Sample& x)
{
	cout << "Say i am in someFunc " << endl;
}
int main()
{
	Sample s1(10);
	SomeFunc(s1);
	s1.PrintVal();
	return 0;
}

// the function SomeFunc has to have (Sample& x) as argument
// NOT (Sample x), becaute when it is without '&', it calls
// the destructor it is out of the scope of SomeFunc
// and the pointer is being deleted because that's what the
// destructor does