#include <iostream>
#include <vector>

class HunPolynomial{
  private:
        std::vector<int> polynomial;        

    public:
        HunPolynomial(/* args */);
        ~HunPolynomial();
        void Set(std::vector<int> input);
        std::string toString();
        friend std::ostream& operator<<(std::ostream& out, const HunPolynomial& hp);
};

