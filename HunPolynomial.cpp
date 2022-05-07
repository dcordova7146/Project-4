#include <iostream>
#include "HunPolynomial.h"

HunPolynomial::HunPolynomial(std::vector<int> poly){
       
    for(int i = 0;i<poly.size();i++){
        //first term and last term are treated differently
        if(i = 0){ //first term cases
            if(poly[i] < 0){
                polynomial.push_back('-');
            }
        }
        if(i = poly.size() -1){//last term cases

        }
    }
}
void HunPolynomial::Set(std::vector<int> poly){
   polyvec = poly;
}
HunPolynomial HunPolynomial::operator+(HunPolynomial& b){

}
HunPolynomial HunPolynomial::operator-(HunPolynomial& b){

}
HunPolynomial HunPolynomial::operator*(HunPolynomial& b){

}
float HunPolynomial::operator()(float& b){

}
