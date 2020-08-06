/*  C++ Advanced 1

	Create an object of type 'Foo' using the memory already allocated by 'malloc'.
*/
#include <iostream>

class Foo
{
public:
	Foo(int value1, float value2) : m_value1(value1), m_value2(value2) {}
	void print() { std::cout << m_value1 << m_value2; }
private:
	int m_value1;
	float m_value2;
};

void main(int argc, char* argv[])
{
	void* mem = malloc(32);

	Foo* obj = new(mem) Foo(0, 1.0);
	obj->print();
	free((void*)obj);
}
