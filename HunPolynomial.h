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
    HunPolynomial();
    HunPolynomial(std::vector<int> input);
    void Set(std::vector<int> input);
    HunPolynomial operator+(const HunPolynomial &b);
    HunPolynomial operator-(const HunPolynomial &b);
    HunPolynomial operator*(const HunPolynomial &b);
    float operator()(const float xval);
    friend std::ostream &operator<<(std::ostream &out, const HunPolynomial &hp);
};
