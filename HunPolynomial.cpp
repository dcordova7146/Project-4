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
    float result = 0.00;

    for(int i = 0; i < polynomial.size(); i++){
        result +=  polynomial[i] * pow(xval, i);
    }
    return result;
}

