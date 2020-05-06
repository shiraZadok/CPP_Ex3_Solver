//
// Created by shira on 28/04/2020.
//
# pragma once
#include <iostream>
#include <complex>
using namespace std;

static complex<double> ZERO_COMPLEX (0,0);

namespace solver{
    class RealVariable;
    class ComplexVariable;
    double solve(RealVariable r);
    complex<double> solve(ComplexVariable c);
}

class solver::RealVariable{
    double _a,_b,_c;
public:
    //Constructors & explicit
    RealVariable ():_a(0),_b(1),_c(0){}
    RealVariable (double d):RealVariable(0,0,d){}
    RealVariable (double a,double b,double c):_a(a),_b(b),_c(c){}

    friend RealVariable operator+ (const RealVariable& , const RealVariable&);
    friend RealVariable operator- (const RealVariable&, const RealVariable&);
    friend RealVariable operator/ (const RealVariable&, const RealVariable&);
    friend RealVariable operator* (const RealVariable&, const RealVariable&);
    friend RealVariable operator^ (const RealVariable&, double);

    RealVariable operator== (const RealVariable& r2){
        return RealVariable(
        (this->_a!=0 && r2._a!=0) ?this->_a-r2._a : (r2._a!=0 ? -r2._a:this->_a),
        (this->_b!=0 && r2._b!=0) ? this->_b-r2._b : (r2._b!=0 ? -r2._b:this->_b),
        this->_c-r2._c);
    }

     friend ostream& operator<< (ostream& os, const RealVariable& r) {
         os << r._a << "x^2+" << r._b << "x+" << r._c;
         return os;
     }
    friend double solve(RealVariable r);
};

class solver::ComplexVariable{
    complex<double> _a,_b,_c;
public:
    //Constructors & explicit
    ComplexVariable ():_a(0),_b(1,0),_c(0){}
    ComplexVariable (double d):ComplexVariable(complex<double>(d,0)){}
    ComplexVariable (const complex<double>& d):_a(0),_b(0),_c(d){}
    ComplexVariable (const complex<double>& a,const complex<double>& b,const complex<double>& c):_a(a),_b(b),_c(c){}

    friend ComplexVariable operator+ (const ComplexVariable& ,const ComplexVariable&);
    friend ComplexVariable operator* (const ComplexVariable& ,const ComplexVariable&);
    friend ComplexVariable operator/ (const ComplexVariable& ,const ComplexVariable&);
    friend ComplexVariable operator- (const ComplexVariable& ,const ComplexVariable&);
    friend ComplexVariable operator^ (const ComplexVariable& , double a);
    
    ComplexVariable operator== (const ComplexVariable& c2){
        return ComplexVariable(
        (this->_a!=ZERO_COMPLEX && c2._a!=ZERO_COMPLEX) ?this->_a-c2._a : (c2._a!=ZERO_COMPLEX ? -c2._a:this->_a),
        (this->_b!=ZERO_COMPLEX && c2._b!=ZERO_COMPLEX) ? this->_b-c2._b : (c2._b!=ZERO_COMPLEX ? -c2._b:this->_b),
        this->_c-c2._c);
    }

    friend ostream& operator<< (ostream& os, const ComplexVariable& r) {
        os << r._a << "x^2+" << r._b << "x+" << r._c;
        return os;
    }
    friend complex<double> solve(ComplexVariable c);
};
