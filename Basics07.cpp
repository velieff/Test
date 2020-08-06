/*  C++ Basics 7

	Rewrite the implementation of the class Flags so it is more efficient in terms of memory and performance for the given value of MAX_FLAGS.
	Document any limitations this imposes on other possible MAX_FLAGS values.
*/

#include <iostream>
#include <random>

class Flags
{
public:
	static const int MAX_FLAGS = 32;

	Flags() { m_flags = 0; }

	bool getFlag(int i)
	{
		return (1 << i) & m_flags;
	}
	void setFlag(int i, bool v)
	{
		m_flags = v ? (m_flags | (1 << i)) : (m_flags & ~(1 << i));
	}
private:
	unsigned int m_flags;
};


void main(int argc, char* argv[])
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> randIndex(0, Flags::MAX_FLAGS - 1);

	Flags flags;
	flags.setFlag(randIndex(rng), true);
	flags.setFlag(randIndex(rng), true);

	for (int i = 0; i < Flags::MAX_FLAGS; ++i)
	{
		std::cout << i << "->" << flags.getFlag(i) << std::endl;
	}
}

