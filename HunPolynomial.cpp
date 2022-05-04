// #include <HunPolynomial.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

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
    for(int i = hp.polynomial.size() - 1; i >= 0; i--){
        out << hp.polynomial[i] << "x" << "^" << i << " ";
    }
    
    return out;
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