//
// Created by shira on 28/04/2020.
//
#include "solver.hpp"
using namespace solver;
using namespace std;

RealVariable solver::operator+ (const RealVariable& r1, const RealVariable& r2){
    return RealVariable(r1._a+r2._a,r1._b+r2._b,r1._c+r2._c);
}

RealVariable solver::operator- (const RealVariable& r1,const RealVariable& r2){
    return RealVariable(r1._a-r2._a,r1._b-r2._b,r1._c-r2._c);
}

RealVariable solver::operator/ (const RealVariable& r1, const RealVariable& r2){
    if(r2._a==0 && r2._c==0 && r2._b==0) throw runtime_error("Must not divide by 0");
    return RealVariable(r1._a/r2._c,r1._b/r2._c,r1._c/r2._c);
}

RealVariable solver::operator* (const RealVariable& r1, const RealVariable& r2){
    if((r1._a!=0&&(r2._a!=0||r2._b!=0)) || (r2._a!=0&&(r1._a!=0||r1._b!=0)))
        throw runtime_error("ERROR: The power of the quadratic equation are more then 2");
    if (r1._a==0&&r1._b==0)
        return RealVariable(r2._a*r1._c,r2._b*r1._c,r2._c*r1._c);
    if (r2._a==0&&r2._b==0)
        return RealVariable(r1._a*r2._c,r1._b*r2._c,r1._c*r2._c);
    return RealVariable(r1._b*r2._b,r1._b*r2._c+r1._c*r2._b,r1._c*r2._c);
}

RealVariable solver::operator^ (const RealVariable& r, double d){
    if((d>2 && r._b!=0) || (d>=2&&r._a!=0)|| d==0)
        throw runtime_error("ERROR: The power of the quadratic equation are more then 2");
    return RealVariable(pow(r._b,d),(2*r._b*r._c),pow(r._c,2));
}

RealVariable solver::operator== (const RealVariable& r1,const RealVariable& r2){
    return RealVariable(r1-r2);
}

double solver::solve(RealVariable r) {
    if (r._a==0&&r._b==0) throw runtime_error("ERROR: There is no solution");
    if (r._a != 0){
        double discriminant = pow(r._b, 2) - 4 * r._a * r._c;
        if (discriminant < 0) throw runtime_error("ERROR: There is no real solution");
        else return (-r._b + sqrt(discriminant)) / (2 * r._a);
    }
    else return (-r._c)/r._b;
}

///////////////////////////////////////////////COMPLEX///////////////////////////////////////////////

ComplexVariable solver::operator+ (const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable(c1._a+c2._a,c1._b+c2._b,c1._c+c2._c);
}

ComplexVariable solver::operator- (const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable(c1._a-c2._a,c1._b-c2._b,c1._c-c2._c);
}

ComplexVariable solver::operator/ (const ComplexVariable& c1, const ComplexVariable& c2){
    if(c2._a==ZERO_COMPLEX && c2._c==ZERO_COMPLEX && c2._b==ZERO_COMPLEX) throw runtime_error("Must not divide by 0");
    return ComplexVariable(c1._a/c2._c,c1._b/c2._c,c1._c/c2._c);
}

ComplexVariable solver::operator* (const ComplexVariable& c1, const ComplexVariable& c2){
    if((c1._a!=ZERO_COMPLEX&&(c2._a!=ZERO_COMPLEX||c2._b!=ZERO_COMPLEX)) ||
       (c2._a!=ZERO_COMPLEX&&(c1._a!=ZERO_COMPLEX||c1._b!=ZERO_COMPLEX)))
        throw runtime_error("ERROR: The power of the quadratic equation are more then 2");
    if (c1._a==ZERO_COMPLEX&&c1._b==ZERO_COMPLEX)
        return ComplexVariable(c2._a*c1._c,c2._b*c1._c,c2._c*c1._c);
    if (c2._a==ZERO_COMPLEX&&c2._b==ZERO_COMPLEX)
        return ComplexVariable(c1._a*c2._c,c1._b*c2._c,c1._c*c2._c);
    return ComplexVariable(c1._b*c2._b,c1._b*c2._c+c1._c*c2._b,c1._c*c2._c);
}

ComplexVariable solver::operator^ (const ComplexVariable& c, double d){
    if((d>2 && c._b!=ZERO_COMPLEX) || (d>=2&&c._a!=ZERO_COMPLEX) || d==0)
        throw runtime_error("ERROR: The power of the quadratic equation are more then 2");
    return ComplexVariable(pow(c._b,d),(2.0*c._b*c._c),pow(c._c,2));
}

ComplexVariable solver::operator== (const ComplexVariable& c1,const ComplexVariable& c2){
    return ComplexVariable(c1-c2);
}

complex<double> solver::solve(ComplexVariable c){
    if (c._a==ZERO_COMPLEX&&c._b==ZERO_COMPLEX) throw runtime_error("ERROR: There is no solution");
    if (c._a != ZERO_COMPLEX){
        complex<double> discriminant = sqrt(pow(c._b, 2) - 4.0 * c._a * c._c);
        return (-c._b + discriminant) / (2.0 * c._a);
    }
    return (-c._c)/c._b;
}
