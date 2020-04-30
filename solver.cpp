//
// Created by shira on 28/04/2020.
//
#include <iostream>
//#include <complex>
#include "solver.hpp"
//using namespace std;
using namespace solver;

RealVariable& solver::operator+ (double d, RealVariable& r){return r;}
RealVariable& solver::operator+ (RealVariable& r, double d){return r;}
RealVariable& solver::operator+ (RealVariable& r1, RealVariable& r2){return r1;}
RealVariable& solver::operator- (double d, RealVariable& r){return r;}
RealVariable& solver::operator- (RealVariable& r, double d){return r;}
RealVariable& solver::operator- (RealVariable& r1, RealVariable& r2){return r1;}
RealVariable& solver::operator/ (double d, RealVariable& r){return r;}
RealVariable& solver::operator/ (RealVariable& r, double d){return r;}
RealVariable& solver::operator/ (RealVariable& r1, RealVariable& r2){return r1;}
RealVariable& solver::operator* (double d, RealVariable& r){return r;}
RealVariable& solver::operator* (RealVariable& r, double d){return r;}
RealVariable& solver::operator* (RealVariable& r1, RealVariable& r2){return r1;}
RealVariable& solver::operator== (double d, RealVariable& r){return r;}
RealVariable& solver::operator== (RealVariable& r, double d){return r;}
RealVariable& solver::operator== (RealVariable& r1, RealVariable& r2){return r1;}
RealVariable& solver::operator^ (RealVariable& r, double d){return r;}

ComplexVariable& solver::operator+ (ComplexVariable& c, double d){return c;}
ComplexVariable& solver::operator+ (double d, ComplexVariable& c){return c;}
ComplexVariable& solver::operator+ (ComplexVariable& c1, complex<double> c2){return c1;}
ComplexVariable& solver::operator+ (complex<double> c1, ComplexVariable& c2){return c2;}
ComplexVariable& solver::operator+ (ComplexVariable& c1, ComplexVariable& c2){return c1;}
ComplexVariable& solver::operator^ (ComplexVariable& c, double d){return c;}
ComplexVariable& solver::operator== (double d, ComplexVariable& c){return c;}
ComplexVariable& solver::operator== (ComplexVariable& c, double d){return c;}
ComplexVariable& operator== (ComplexVariable& c1, complex<double> c2) {return c1;}
ComplexVariable& operator== (complex<double> c1, ComplexVariable& c2){return c2;}
ComplexVariable& solver::operator== (ComplexVariable& c1, ComplexVariable& c2){return c1;}
ComplexVariable& solver::operator* (double d, ComplexVariable& c){return c;}
ComplexVariable& solver::operator* (ComplexVariable& c, double d){return c;}
ComplexVariable& solver::operator* (ComplexVariable& c1, complex<double> c2){return c1;}
ComplexVariable& solver::operator* (complex<double> c1, ComplexVariable& c2){return c2;}
ComplexVariable& solver::operator* (ComplexVariable& c1, ComplexVariable& c2){return c1;}
ComplexVariable& solver::operator/ (double d, ComplexVariable& c){return c;}
ComplexVariable& solver::operator/ (ComplexVariable& c, double d){return c;}
ComplexVariable& solver::operator/ (ComplexVariable& c1, ComplexVariable& c2){return c1;}
ComplexVariable& solver::operator/ (ComplexVariable& c1, complex<double> c2){return c1;}
ComplexVariable& solver::operator/ (complex<double> c1, ComplexVariable& c2){return c2;}
ComplexVariable& solver::operator- (double d, ComplexVariable& c){return c;}
ComplexVariable& solver::operator- (ComplexVariable& c, double d){return c;}
ComplexVariable& solver::operator- (ComplexVariable& c1, ComplexVariable& c2){return c1;}
ComplexVariable& solver::operator- (ComplexVariable& c1, complex<double> c2){return c1;}
ComplexVariable& solver::operator- (complex<double> c1, ComplexVariable& c2){return c2;}

double solver::solve(RealVariable r){return 0;}
complex<double> solver::solve(ComplexVariable c){return 3;}