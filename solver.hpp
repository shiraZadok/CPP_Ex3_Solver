//
// Created by shira on 28/04/2020.
//
# pragma once
#include <iostream>
#include <complex>
using namespace std;

namespace solver{
////    class Function;
//    class RealVariable;
//    class ComplexVariable;
class RealVariable{
    double _re;
public:
    RealVariable(){}
    RealVariable(double re){
        _re=re;
    }
    friend RealVariable& operator+ (double, RealVariable&);
    friend RealVariable& operator+ (RealVariable&, double);
    friend RealVariable& operator+ (RealVariable& , RealVariable&);
    friend RealVariable& operator- (double, RealVariable&);
    friend RealVariable& operator- (RealVariable&, double);
    friend RealVariable& operator- (RealVariable&, RealVariable&);
    friend RealVariable& operator/ (double, RealVariable&);
    friend RealVariable& operator/ (RealVariable&, double);
    friend RealVariable& operator/ (RealVariable&, RealVariable&);
    friend RealVariable& operator* (double, RealVariable&);
    friend RealVariable& operator* (RealVariable&, double);
    friend RealVariable& operator* (RealVariable&, RealVariable&);
    friend RealVariable& operator== (double, RealVariable&);
    friend RealVariable& operator== (RealVariable&, double);
    friend RealVariable& operator== (RealVariable&, RealVariable&);
    friend RealVariable& operator^ (RealVariable&, double);
};

class ComplexVariable{
    double _re;
    complex<double> _im;
public:
    ComplexVariable(){}
    ComplexVariable(double re, complex<double> im){
        _re=re;
        _im=im;
    }
    friend ComplexVariable& operator+ (ComplexVariable& a, double b);
    friend ComplexVariable& operator+ (double a, ComplexVariable& b);
    friend ComplexVariable& operator+ (ComplexVariable& a, complex<double> b);
    friend ComplexVariable& operator+ (complex<double> a, ComplexVariable& b);
    friend ComplexVariable& operator+ (ComplexVariable& a, ComplexVariable& b);
    friend ComplexVariable& operator^ (ComplexVariable& f, double a);
    friend ComplexVariable& operator== (double a, ComplexVariable& b);
    friend ComplexVariable& operator== (ComplexVariable& a, double b);
    friend ComplexVariable& operator== (ComplexVariable& a, complex<double> b);
    friend ComplexVariable& operator== (complex<double> a, ComplexVariable& b);
    friend ComplexVariable& operator== (ComplexVariable& a, ComplexVariable& b);
    friend ComplexVariable& operator* (double a, ComplexVariable& b);
    friend ComplexVariable& operator* (ComplexVariable& a, double b);
    friend ComplexVariable& operator* (ComplexVariable& a, complex<double> b);
    friend ComplexVariable& operator* (complex<double> a, ComplexVariable& b);
    friend ComplexVariable& operator* (ComplexVariable& a, ComplexVariable& b);
    friend ComplexVariable& operator/ (double a, ComplexVariable& b);
    friend ComplexVariable& operator/ (ComplexVariable& a, double b);
    friend ComplexVariable& operator/ (ComplexVariable& a, ComplexVariable& b);
    friend ComplexVariable& operator/ (ComplexVariable& a, complex<double> b);
    friend ComplexVariable& operator/ (complex<double> a, ComplexVariable& b);
    friend ComplexVariable& operator- (double a, ComplexVariable& b);
    friend ComplexVariable& operator- (ComplexVariable& a, double b);
    friend ComplexVariable& operator- (ComplexVariable& a, ComplexVariable& b);
    friend ComplexVariable& operator- (ComplexVariable& a, complex<double> b);
    friend ComplexVariable& operator- (complex<double> a, ComplexVariable& b);
};

    double solve(RealVariable r);
    complex<double> solve(ComplexVariable c);
}