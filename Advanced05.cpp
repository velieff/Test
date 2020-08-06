/*  C++ Advanced 5

	Make as many memory and performance optimizations as you can.
*/

#include <iostream>

#define WIDTH (128)
#define HEIGHT (128)
#define WIDTHMULTHEIGHT (16384) //128*128=16384

struct Pixel
{
	Pixel() {}
	Pixel(float value)
	{
		r = value;
		g = value;
		b = value;
		a = value;
	}
	Pixel& operator+=(const Pixel& p)
	{
		r += p.r;
		g += p.g;
		b += p.b;
		a += p.a;
		return *this;
	}
	float r;
	float g;
	float b;
	float a;
};

class Image
{

public:

	Image() { m_Pixels = new Pixel[WIDTHMULTHEIGHT]; }
	~Image() { delete[] m_Pixels; }

	void Clear(float value)
	{
		Pixel p(value);
		for (unsigned i = 0; i < WIDTHMULTHEIGHT; ++i)
		{
			SetPixel(p, i / WIDTH, i % WIDTH);
		}
	}

	void Add(Image* immageToAdd)
	{
		for (unsigned i = 0; i < WIDTHMULTHEIGHT; ++i)
		{
			AddImage(immageToAdd, i / WIDTH, i % WIDTH);
		}
	}

	void AddImage(Image* immageToAdd, unsigned x, unsigned y)
	{
		m_Pixels[y * WIDTH + x] += (immageToAdd->GetPixel(x, y));
	}

	Pixel GetPixel(unsigned x, unsigned y)
	{
		return m_Pixels[y * WIDTH + x];
	}

	void SetPixel(Pixel pixel, unsigned x, unsigned y)
	{
		m_Pixels[y * WIDTH + x] = pixel;
	}

private:
	Pixel* m_Pixels;
};

void main(int argc, char* argv[])
{
	Image imageA;
	imageA.Clear(0.5f);
	Image imageB;
	imageB.Clear(0.2f);

	imageA.Add(&imageB);
}