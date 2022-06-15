#include "HunPolynomial.h"


HunPolynomial::HunPolynomial()
{
    polynomial = {0};
}

HunPolynomial::HunPolynomial(std::vector<int> input)
{
    polynomial = input;
    std::reverse(polynomial.begin(), polynomial.end());
};

void HunPolynomial::Set(std::vector<int> input)
{
    polynomial = input;
    std::reverse(polynomial.begin(), polynomial.end());
}

std::ostream &operator<<(std::ostream &out, const HunPolynomial &hp)
{
    std::string expression = "";
    for (int i = hp.polynomial.size() - 1; i >= 0; i--) // for each term in vector
    {
        if (hp.polynomial[i] != 0) // add term if coefficient is not zero
        {
            if (expression.length() != 0) // base case
            /*check if not base case to add sign, otherwise are all these operations the same?*/
            {
                expression.push_back(' ');
                if (hp.polynomial[i] < 0)
                {
                    expression.push_back('-');
                }
                else if (hp.polynomial[i] > 0)
                {
                    expression.push_back('+');
                }
                expression.push_back(' ');
            }
            else if (expression.length() == 0 && hp.polynomial[i] < 0)
            {
                expression.push_back('-');
                expression.push_back(' ');
            }

            if ((hp.polynomial[i] == 1) || (hp.polynomial[i] == -1))
            {
                if (i == 0)
                {
                    expression.push_back('1');
                }
            }
            else
            {
                expression.append(std::to_string(std::abs(hp.polynomial[i])));
                if (i != 0)
                {
                    expression.push_back('*');
                }
            }

            if (i == 1)
            {
                expression.push_back('x');
            }
            else if (i != 0)
            {
                expression.push_back('x');
                expression.push_back('^');
                expression.append(std::to_string(i));
            }
        }

    }

    out << expression;
    return out;
}

HunPolynomial HunPolynomial::operator+(const HunPolynomial &b)
{
    //tempvec is always a
    std::vector<int> tempvec = polynomial;

    if(polynomial.size() < b.polynomial.size()){
        while(tempvec.size() != b.polynomial.size()){
            tempvec.push_back(0);
        }
    }
    std::transform(tempvec.begin(),tempvec.end(), b.polynomial.begin(), tempvec.begin(), std::plus<int>());       
    std::reverse(tempvec.begin(),tempvec.end());
    return tempvec;
}

HunPolynomial HunPolynomial::operator-(const HunPolynomial &b)
{
    //tempvec is always a
     std::vector<int> tempvec = polynomial;

    if(polynomial.size() < b.polynomial.size()){
        while(tempvec.size() != b.polynomial.size()){
            tempvec.push_back(0);
        }
    }
    std::transform(tempvec.begin(),tempvec.end(), b.polynomial.begin(), tempvec.begin(), std::minus<int>());       
    std::reverse(tempvec.begin(),tempvec.end());
    return tempvec;
    
}

HunPolynomial HunPolynomial::operator*(const HunPolynomial &b)
{
    std::vector<int> bigger = polynomial.size() >= b.polynomial.size() ? polynomial:b.polynomial;
    std::vector<int> smaller = polynomial.size() < b.polynomial.size() ? polynomial:b.polynomial;
    std::vector<int> result;

    for(int i = 0;i<(bigger.size()+smaller.size()-1);i++){
        result.push_back(0);
    }
    while(bigger.size() != smaller.size()){
        smaller.push_back(0);
    }
    for(int i=0; i<bigger.size(); i++){
        for(int j=0; j<smaller.size(); j++){
            result[i+j] += bigger[i] *smaller[j];
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

float HunPolynomial::operator()(float xval){
    float result = 0.000000000;

    for(int i = 0; i < polynomial.size(); i++){
        result +=  polynomial[i] * pow(xval, i);
    }
    return result;
}

int main()
{
HunPolynomial defPol;

	std::cout << "Printing tests. Make sure your output matches the expected output EXACTLY" << std::endl;
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
