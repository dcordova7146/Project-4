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

HunPolynomial::HunPolynomial(/* args */)
{
    polynomial = {0};
}

HunPolynomial::HunPolynomial(std::vector<int> input)
{
    polynomial = input;
    std::reverse(polynomial.begin(), polynomial.end());
};

HunPolynomial::~HunPolynomial(){};

void HunPolynomial::Set(std::vector<int> input)
{
    polynomial = input;
    std::reverse(polynomial.begin(), polynomial.end());
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
    std::vector<int> bigBuffer = p1.polynomial.size() >= p2.polynomial.size() ? p1.polynomial : p2.polynomial;
    std::vector<int> smallBuffer = p1.polynomial.size() < p2.polynomial.size() ? p1.polynomial : p2.polynomial;

    while (bigBuffer.size() != smallBuffer.size())
    {
        smallBuffer.push_back(0);
    }

    std::transform(bigBuffer.begin(), bigBuffer.end(), smallBuffer.begin(), bigBuffer.begin(), std::plus<int>());

    std::reverse(bigBuffer.begin(), bigBuffer.end());
    return bigBuffer;
}

HunPolynomial operator-(const HunPolynomial &p1, const HunPolynomial &p2)
{
    std::vector<int> tmp1 = p2.polynomial;

    for (int i = 0; i < tmp1.size(); i++)
    {
        tmp1[i] *= -1;
    }

    std::vector<int> bigBuffer = p1.polynomial.size() >= p2.polynomial.size() ? p1.polynomial : tmp1;
    std::vector<int> smallBuffer = p1.polynomial.size() < p2.polynomial.size() ? p1.polynomial : tmp1;

    while (bigBuffer.size() != smallBuffer.size())
    {
        smallBuffer.push_back(0);
    }

    std::transform(bigBuffer.begin(), bigBuffer.end(), smallBuffer.begin(), bigBuffer.begin(), std::plus<int>());

    std::reverse(bigBuffer.begin(), bigBuffer.end());
    return bigBuffer;
}

HunPolynomial operator*(const HunPolynomial &p1, const HunPolynomial &p2)
{
    std::vector<int> bigBuffer = p1.polynomial.size() >= p2.polynomial.size() ? p1.polynomial : p2.polynomial;
    std::vector<int> smallBuffer = p1.polynomial.size() < p2.polynomial.size() ? p1.polynomial : p2.polynomial;
    std::vector<int> resultBuffer;

    for(int a = 0; a < (bigBuffer.size() + smallBuffer.size() - 2) ; a++){
        resultBuffer.push_back(0);
    }

    while (bigBuffer.size() != smallBuffer.size())
    {
        smallBuffer.push_back(0);
    }

    for (int i = 0; i < bigBuffer.size(); i++)
    {
        for (int j = 0; j < smallBuffer.size(); j++)
        {
            resultBuffer[i + j] += bigBuffer[i] + smallBuffer[j];
        }
    }

    std::reverse(resultBuffer.begin(), resultBuffer.end());
    return resultBuffer;
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

    // Result = X + Y;
    // std::cout << Result << std::endl;
    // std::cout << "- 4*x^4 + 5*x^3 + 4*x^2 - x - 31  <= that is what you should see above exactly\n\n";

    // Result = Y + X;
    // std::cout << Result << std::endl;
    // std::cout << "- 4*x^4 + 5*x^3 + 4*x^2 - x - 31  <= that is what you should see above exactly\n\n"; // testing for deconstruction? or clear cache?

    // Result = X + Empty; // segmentation default core dump
    // std::cout << Result << std::endl;
    // std::cout << "- 4*x^4 + x^2 - 31  <= that is what you should see above exactly\n\n";

    // Result = Empty + Y;
    // std::cout << Result << std::endl;
    // std::cout << "5*x^3 + 3*x^2 - x  <= that is what you should see above exactly\n\n";

    // HunPolynomial Z{{-5, -4, 2, 0}};
    // Result = Y + Z;
    // std::cout << Result << std::endl;
    // std::cout << "- x^2 + x  <= that is what you should see above exactly\n\n";

    // // Testing subtraction
    // Result = X - Y;
    // std::cout << Result << std::endl;
    // std::cout << "- 4*x^4 - 5*x^3 - 2*x^2 + x - 31  <= that is what you should see above exactly\n\n";

    // Result = Y - X;
    // std::cout << Result << std::endl;
    // std::cout << "4*x^4 + 5*x^3 + 2*x^2 - x + 31  <= that is what you should see above exactly\n\n";

    // Result = Y - Empty;
    // std::cout << Result << std::endl;
    // std::cout << "5*x^3 + 3*x^2 - x  <= that is what you should see above exactly\n\n";

    // Result = Empty - Y;
    // std::cout << Result << std::endl;
    // std::cout << "- 5*x^3 - 3*x^2 + x  <= that is what you should see above exactly\n\n";

    // Testing multiplication
    HunPolynomial A{{2, 0, 0, 0, 1, 6}};
    HunPolynomial B{{1, -4, 0}};

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