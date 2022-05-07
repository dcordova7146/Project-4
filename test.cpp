#include "HunPolynomial.h"
#include <iostream>

int main()
{
	HunPolynomial defPol;

	// Printing tests. Make sure your output matches the expected output EXACTLY
	defPol.Set({ 1, 15, -1, 20 });
	std::cout << defPol << std::endl;
	std::cout << "x^3 + 15*x^2 - x + 20  <= that is what you should see above exactly\n\n";

	defPol.Set({ -1, 0, 1 });
	std::cout << defPol <<std::endl;
	std::cout << "- x^2 + 1  <= that is what you should see above exactly\n\n";

	// Testing operator()
	std::cout << "The value is " << defPol(-2.5) << ". The correct value is -5.25\n\n";

	// Testing addition
	HunPolynomial X{ { -4, 0, 1, 0, -31 } };
	HunPolynomial Y{ { 5, 3, -1, 0 } };
	HunPolynomial Result;
	HunPolynomial Empty; // that would be an empty polinomial

	Result = X + Y;
	std::cout << Result << std::endl;
	std::cout << "- 4*x^4 + 5*x^3 + 4*x^2 - x - 31  <= that is what you should see above exactly\n\n";

	Result = Y + X;
	std::cout << Result << std::endl;
	std::cout << "- 4*x^4 + 5*x^3 + 4*x^2 - x - 31  <= that is what you should see above exactly\n\n";

	Result = X + Empty;
	std::cout << Result << std::endl;
	std::cout << "- 4*x^4 + x^2 - 31  <= that is what you should see above exactly\n\n";

	Result = Empty + Y;
	std::cout << Result << std::endl;
	std::cout << "5*x^3 + 3*x^2 - x  <= that is what you should see above exactly\n\n";

	HunPolynomial Z{ { -5, -4, 2, 0 } };
	Result = Y + Z;
	std::cout << Result << std::endl;
	std::cout << "- x^2 + x  <= that is what you should see above exactly\n\n";

	// Testing subtraction
	Result = X - Y;
	std::cout << Result << std::endl;
	std::cout << "- 4*x^4 - 5*x^3 - 2*x^2 + x - 31  <= that is what you should see above exactly\n\n";

	Result = Y - X;
	std::cout << Result << std::endl;
	std::cout << "4*x^4 + 5*x^3 + 2*x^2 - x + 31  <= that is what you should see above exactly\n\n";

	Result = Y - Empty;
	std::cout << Result << std::endl;
	std::cout << "5*x^3 + 3*x^2 - x  <= that is what you should see above exactly\n\n";

	Result = Empty - Y;
	std::cout << Result << std::endl;
	std::cout << "- 5*x^3 - 3*x^2 + x  <= that is what you should see above exactly\n\n";

	// Testing multiplication
	HunPolynomial A{ { 2, 0, 0, 0, 1, 6 } };
	HunPolynomial B{ { 1, -4, 0 } };

	Result = A * B;
	std::cout << Result << std::endl;
	std::cout << "2*x^7 - 8*x^6 + x^3 + 2*x^2 - 24*x  <= that is what you should see above exactly\n\n";

	Result = B * A;
	std::cout << Result << std::endl;
	std::cout << "2*x^7 - 8*x^6 + x^3 + 2*x^2 - 24*x  <= that is what you should see above exactly\n\n";

	Result = A * Empty;
	std::cout << Result << std::endl;
	std::cout << "Above should be an empty line or any other indication of empty polinomial\n\n";

	Result = Empty * A;
	std::cout << Result << std::endl;
	std::cout << "Above should be an empty line or any other indication of empty polinomial\n\n";

	return 0;
}