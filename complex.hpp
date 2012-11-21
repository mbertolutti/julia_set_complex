#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <cmath>

class complex
{
public:
	complex(double real, double imag)
		: real(real), imag(imag)
	{
	}

	double abs()
	{
		return std::sqrt(real * real + imag * imag);
	}

	complex operator+ (complex other)
	{
		complex result(real + other.real, imag + other.imag);
		return result;
	}

	complex operator* (complex other)
	{
		// (a+bi)*(c+di) =a*c-bd+(a*d+b*c)i
		complex result(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
		return result;
	}

private:
	double real, imag;
};

#endif
