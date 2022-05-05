// #include <HunPolynomial.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <string>
#include <algorithm>

class HunPolynomial
{
private:
    std::vector<int> polynomial;

public:
    HunPolynomial(/* args */);
    HunPolynomial(std::vector<int> input);
    ~HunPolynomial();
    void Set(std::vector<int> input);
    friend std::ostream &operator<<(std::ostream &out, const HunPolynomial &hp);
    friend HunPolynomial operator+(const HunPolynomial &p1, const HunPolynomial &p2);
    friend HunPolynomial operator-(const HunPolynomial &p1, const HunPolynomial &p2);
    friend HunPolynomial operator*(const HunPolynomial &p1, const HunPolynomial &p2);
};

HunPolynomial::HunPolynomial(/* args */) {}

HunPolynomial::HunPolynomial(std::vector<int> input)
{
    while (input.size() > 0)
    {
        polynomial.push_back(input.back());
        input.pop_back();
    }
};

HunPolynomial::~HunPolynomial(){};

void HunPolynomial::Set(std::vector<int> input)
{
    while (input.size() > 0)
    {
        polynomial.push_back(input.back());
        input.pop_back();
    }
}

std::ostream &operator<<(std::ostream &out, const HunPolynomial &hp)
{
    std::string buffer = "";
    int i;
    // std::cout << buffer.length() << std::endl;

    for (i = hp.polynomial.size() - 1; i >= 0; i--) // for each term in vector
    {
        if (hp.polynomial[i] != 0) // add term if coefficient is not zero
        {
            if (buffer.length() != 0) // base case
            /*check if not base case to add sign, otherwise are all these operations the same?*/
            {
                buffer.append(" ");
                if (hp.polynomial[i] < 0)
                {
                    buffer.append("-");
                }
                else if (hp.polynomial[i] > 0)
                {
                    buffer.append("+");
                }
                buffer.append(" ");
            }
            else if (buffer.length() == 0 && hp.polynomial[i] < 0)
            {
                buffer.append("-");
                buffer.append(" ");
            }

            if ((hp.polynomial[i] == 1) || (hp.polynomial[i] == -1))
            {
                if (i == 0)
                {
                    buffer.append("1");
                }
            }
            else
            {
                buffer.append(std::to_string(std::abs(hp.polynomial[i])));
                if (i != 0)
                {
                    buffer.append("*");
                }
            }

            if (i == 1)
            {
                buffer.append("x");
            }
            else if (i != 0)
            {
                buffer.append("x");
                buffer.append("^");
                buffer.append(std::to_string(i));
            }
        }

        // std::cout << "index: " << i << " num:  " << hp.polynomial[i] << " pow:  " << i <<std::endl;
    }

    // std::cout << "index: " << i << " num:  " << hp.polynomial[i] << " pow:  " << i <<std::endl;

    out << buffer;
    return out;
}

HunPolynomial operator+(const HunPolynomial &p1, const HunPolynomial &p2)
{
    std::vector<int> buffer = p1.polynomial.size() > p2.polynomial.size() ? p1.polynomial : p2.polynomial;
    std::vector<int> smallerVector = p1.polynomial.size() < p2.polynomial.size() ? p1.polynomial : p2.polynomial;
    for (int i = smallerVector.size(); i >= 0; i--)
    {
        std::cout << "index: " << i << " num:  " << buffer[i] << " pow:  " << i << std::endl;
        buffer[i] += smallerVector[i];
    }
    std::reverse(buffer.begin(), buffer.end());
    return buffer;
}

int main()
{
    HunPolynomial defPol;

    // Printing tests. Make sure your output matches the expected output EXACTLY
    defPol.Set({1, 15, -1, 20});
    std::cout << defPol << std::endl;
    std::cout << "x^3 + 15*x^2 - x + 20  <= that is what you should see above exactly\n\n";

    HunPolynomial defPol2;

    defPol2.Set({-1, 0, 1});
    std::cout << defPol2 << std::endl;
    std::cout << "- x^2 + 1  <= that is what you should see above exactly\n\n";

    // Testing operator()
    // std::cout << "The value is " << defPol(-2.5) << ". The correct value is -5.25\n\n";

    // Testing addition
    HunPolynomial X{{-4, 0, 1, 0, -31}};
    HunPolynomial Y{{5, 3, -1, 0}};
    HunPolynomial Result;
    HunPolynomial Empty; // that would be an empty polinomial

    Result = X + Y;
    std::cout << Result << std::endl;
    std::cout << "- 4*x^4 + 5*x^3 + 4*x^2 - x - 31  <= that is what you should see above exactly\n\n";

    return 0;
}