/*  C++ Algorithms 3

	Given the struct Vertex, representing vertices in a graph, write a function DFVisit() that traverses the graph and fills
	the vector result with all connected vertices in Depth First order. Write a comment with the time complexity of your implementation.

*/

#include <iostream>
#include <vector>

struct Vertex
{
	std::vector<Vertex*> m_adjacent;
};

// time complexity: O(n^2)
void DFVisit(Vertex* v, std::vector<Vertex*>& result)
{
	if (result.size() == 0)
	{
		result.push_back(v);
	}

	for (Vertex* vert : v->m_adjacent)
	{
		if (std::find(result.begin(), result.end(), vert) == result.end())
		{
			result.push_back(vert);
			DFVisit(vert, result);
		}
	}
}

void main(int argc, char* argv[])
{
	Vertex a, b, c, d;
	a.m_adjacent.push_back(&b);
	b.m_adjacent.push_back(&c);
	c.m_adjacent.push_back(&d);
	d.m_adjacent.push_back(&b);

	std::vector<Vertex*> visited;
	DFVisit(&d, visited);

	std::cout << "Number of visited vertices: " << visited.size() << std::endl;
}

