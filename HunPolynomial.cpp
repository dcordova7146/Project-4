// #include <HunPolynomial.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <string>

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
    bool addterm = true;
    int i;
    std::cout << buffer.length() << std::endl;

    for (i = hp.polynomial.size() - 1; i >= 0; i--) // for each term in vector
    {
        // // check pos or neg
        // if (hp.polynomial[i] > 1) //pos coefficient reguar
        // {
        // }
        // else if (hp.polynomial[i] == 1) //do not place coefficient
        // {
        // }
        // else if (hp.polynomial[i] < 1 && hp.polynomial[i] > 0) //  pos coefficients that are decimals
        // {
        // }
        // else if (hp.polynomial[i] == 0) // do not place a term
        // {
        // }
        // else if (hp.polynomial[i] < 0) // negative coefficient
        // {
        // }
        // else //invalid term?
        // {
        // }

        // buffer.append(std::to_string(hp.polynomial[i]) + "x" + "^" + std::to_string(i) + " ");

        if (buffer.length() == 0)
        { // base case
            switch (hp.polynomial[i])
            {
            case 1:
                // buffer.append("");
                break;
            case -1:
                buffer.append("- ");
                break;
            default:
                buffer.append(std::to_string(hp.polynomial[i]));
                buffer.append("*");
            }
        }
        else if (hp.polynomial[i] > 1)
        {
            buffer.append("+");
            buffer.append(" ");
            buffer.append(std::to_string(hp.polynomial[i]));
            buffer.append("*");
        }
        else if (hp.polynomial[i] == 1)
        {
            buffer.append("+");
            buffer.append(" ");
        }
        else if (hp.polynomial[i] == 0)
        {
            addterm = false;
        }
        else if (hp.polynomial[i] == -1)
        {
            buffer.append("-");
            buffer.append(" ");
        }
        else if (hp.polynomial[i] < -1)
        {
            buffer.append("-");
            buffer.append(" ");
            buffer.append(std::to_string(std::abs(hp.polynomial[i])));
        }

        if (addterm == true) //true if coefficient is not 0
        {
            switch (i)
            {
            case 1:
                buffer.append("x");
                buffer.append(" ");
                break;
            case 0:
                if(hp.polynomial[i] == 1){
                    buffer.append("1");
                }
                else if(hp.polynomial[i] > 1){//this is janky
                    buffer.pop_back();
                }
                break;
            default:
                buffer.append("x");
                buffer.append("^");
                buffer.append(std::to_string(i));
                buffer.append(" ");
            }
        }
        addterm = true;

        std::cout << "index: " << i << " num:  " << hp.polynomial[i] << " pow:  " << i <<std::endl;
        
    }

    std::cout << "index: " << i << " num:  " << hp.polynomial[i] << " pow:  " << i <<std::endl;
    
    out << buffer;
    return out;
}

HunPolynomial operator+(const HunPolynomial &p1, const HunPolynomial &p2)
{
	std::vector<int> buffer;
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

    return 0;
}