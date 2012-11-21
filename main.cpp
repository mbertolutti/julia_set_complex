#include <iostream>
#include "complex.hpp"


double julia(complex c)
{
	complex seed(-0.8, 0.156);
	double i = 0, n = 200;;

	do
	{
		c = c * c + seed;
	} while (++i < n && c.abs() < 5);

	return i / (n + 1);
}

int main()
{
	const char density[] = { ' ', '.', ',', '-', '~', '*', '+', '#', '$' };
	double width = 260, height = 80;

	for (std::size_t i = 0; i < height; ++i)
	{
		for (std::size_t j = 0; j < width; ++j)
		{
			complex pos(2 - 4 * j / width, 2 * i / height - 1);
			std::size_t symbol = julia(pos) * sizeof(density);
			std::cout << density[symbol];
		}

		std::cout << '\n';
	}

	std::cout << "Press any key to continue" << std::endl;
	std::cin.get();
}
