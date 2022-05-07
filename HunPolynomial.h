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
    float operator()(const float num);
};
