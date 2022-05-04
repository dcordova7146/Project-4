#include <iostream>
#include <vector>


class hpoly{

    private:
    std::vector<int> ppoly;

    public:
    hpoly(); //creates an empty polynomial
    hpoly(std::vector<int> poly); // set ppoly to poly
    void set(std::vector<int> poly); // same as parameterized constructor
    hpoly operator+ (hpoly& b);
    hpoly operator- (hpoly& b);
    hpoly operator* (hpoly& b);
    float operator() (float& x);
    //ostream& operator<<(ostream& os, const hpoly& dt) not a class member
    
};

