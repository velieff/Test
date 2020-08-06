/*  C++ Basic 6

	Add code that will make the template function add() work for objects of class Vec3.
*/

#include <iostream>

template <typename T> T add(T a, T b)
{
	return a + b;
}

class Vec3
{
public:
	explicit Vec3(float _x = 0.f, float _y = 0.f, float _z = 0.f) : m_x(_x), m_y(_y), m_z(_z) {}

	float x() { return m_x; }
	float y() { return m_y; }
	float z() { return m_z; }
	Vec3& operator+=(const Vec3& right)
	{
		m_x += right.m_x;
		m_y += right.m_y;
		m_z += right.m_z;
		return *this;
	}
	friend Vec3 operator+(Vec3 left, const Vec3& right)
	{
		left += right;
		return left;
	}
private:
	float m_x, m_y, m_z;
};

void main(int argc, char* argv[])
{
	Vec3 a(1, 2, 3), b(4, 5, 6);
	Vec3 c;
	c = add<Vec3>(a, b);
	std::cout << c.x() << " " << c.y() << " " << c.z() << std::endl;
}

