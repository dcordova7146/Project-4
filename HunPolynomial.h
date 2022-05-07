#include <iostream>
#include <vector>


class HunPolynomial{

    private:
    std::vector<int> polyvec;
    std::string polynomial;
  
    public:
    HunPolynomial(); //creates an empty polynomial
    HunPolynomial(std::vector<int> poly); // set ppoly to poly
    void Set(std::vector<int> poly); // same as parameterized constructor
    HunPolynomial operator+ (HunPolynomial& b);
    HunPolynomial operator- (HunPolynomial& b);
    HunPolynomial operator* (HunPolynomial& b);
    float operator() (float& x);
    //friend std::ostream& operator<<(ostream& os, const hunpoly& dt);
    
};

