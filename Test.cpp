//
// Created by shira on 30/04/2020.
//
#include <iostream>
#include "solver.hpp"
#include "doctest.h"

using namespace  std;
using solver::RealVariable, solver::ComplexVariable;

TEST_CASE("Test: RealVariable Linear Function") {
    RealVariable x;
    CHECK(solve(x == 3) == 3);
    CHECK(solve(2 * x == 6) == 3);
    CHECK(solve(10 * x == 0) == 0);
    CHECK(solve(2 * x + x + 4 = -2) == -3);
    CHECK(solve(x + x + x == 9) == 3);
    CHECK(solve(x + 3 + 4 - x + 2*x - 3 - 4 == 0) == 0);
    CHECK(solve(x = 2) == 2);
    CHECK(solve(3 * x + 0 == 3) == 1);
    CHECK(solve(x / 2 + 2 + x == 0) == 0.75);
    CHECK(solve(x*(-1) - 2*x == 3) == -1);
    CHECK(solve(x == 0) == 0);
    CHECK(solve(4 + 3 == x) == 7);
    CHECK(solve(2 * x - 4 == 10) == 3);
    CHECK(solve(88 * x == 88) == 1);
    CHECK(solve(42.5 * x + 13 * x + 0.5 * x == 224) == 4);
    CHECK(solve((0.5 * x + 0.5 * x) / 2 * x + x == 0) == -0.5);
    CHECK(solve(8 * x / 2 * x / 2 * x == 0) == 2);
    CHECK(solve(10 + 10 - 10 * x == 0) == 2);
    CHECK(solve(x - x + x - x + x == 2) == 2);
    CHECK(solve(x + 1 == 4) == 3);
    CHECK(solve(4 * x + 2 * x == 6) == 1);
    CHECK(solve(18 * x == 9) == 0.5);
    CHECK(solve(99*x = x) == 0);
    CHECK(solve(12 * x + 13 = -2 * x / 2) == -1);
    CHECK(solve(120 * x / 2 / 2 / 2 == 0) == 15);
    CHECK(solve(x + x + x + x + 1 + 0 == -3) == -1);
    CHECK(solve(45 * x * 2 == 180) == 2);
    CHECK(solve(67 * x + 67 * x == 134) == 2);
    CHECK(solve(x + 1 == x*-1)==0.5);
    CHECK(solve(x*2+2*x==8)==2);
    CHECK(solve(x+2+x+2==2)==-1);
    CHECK(solve(x+x+0==16)==8);
    CHECK(solve(x+1=0)==-1);
    CHECK(solve(2*x=x+2)==2);
    CHECK(solve(x==0)==0); CHECK(0==0);
    CHECK(solve(x+8==0)==-8);
    CHECK(solve(x+4+2*x/2*x==0)==-4);
    CHECK(solve(x*6+x==7)==1);
    CHECK(solve(x*0+x==0)==0);
}

TEST_CASE("Test: RealVariable Quadratic Function") {
    RealVariable x;
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve(2 * x +(x^2) == 0) == 0);
    CHECK(solve(10 * (x^2) == 0) == 0);
    CHECK(solve(2 * (x^2) + x + 4 = -2) == -1);
    CHECK(solve((x^2) + x + x == 9) == -4.16227766);
    CHECK(solve((x^2) + 3 + 4 - x + 2*x - 3 - 4 == 0) == -1);
    CHECK(solve((x^2)+ 3 * x + 0 == 3) == -3.791287847);
    CHECK(solve((x^4) / (x^2) + 16 + 8*x == 0) == -4);
    CHECK(solve((x^2)*(-1) - 2*x == 0) == -2);
    CHECK(solve((x^2) == 0) == 0);
    CHECK(solve(4 + 3+1 == (x^2)) == 4);
    CHECK(solve(2 * (x^2) - 4 == 4) == 2);
    CHECK(solve((x^2) == 7744) == 88);
    CHECK(solve((x^2)+ 42.5 * x + 13 * x + 0.5 * x == 224) == 3.749015733);
    CHECK(solve((x^2)-16==0)==4);
    CHECK(solve((x^2)+8+16==0)==4);
    CHECK(solve((x^2)+10*x+25==0)==-5);
    CHECK(solve((x^4)/(x^2)==16)==4);
    CHECK(solve((x^2)==25)==5);
    //
    CHECK(solve((0.5 * (x^4) + 0.5 * (x^4) )/ 2 * (x^2) + x == 0) == -0.5);
    CHECK(solve(8 * x / 2 * x / 2 * x == 0) == 2);
    CHECK(solve(10 + 10 - 10 * x == 0) == 2);
    CHECK(solve((x^4) - x + x - x + x == 2) == 2);
    CHECK(solve(x + 1 == 4) == 3);
    CHECK(solve(4 * (x^2) + 2 * x == 6) == 1);
    CHECK(solve(18 * (x^2) == 9) == 0.5);
    CHECK(solve(99*x = (x^2)) == 0);
    CHECK(solve(12 * (x^2) + 13 = -2 * x / 2) == -1);
    CHECK(solve(120 * (x^2) / 2 / 2 / 2 == 0) == 15);
    CHECK(solve((x^2) + x + x + x + 1 + 0 == -3) == -1);
    CHECK(solve(45 * (x^2) * 2 == 180) == 2);
    CHECK(solve(67 * (x^2) + 67 * x == 134) == 2);
    CHECK(solve((x^2) + 1 == x*-1)==0.5);
    CHECK(solve(x*2+2*(x^2)==8)==2);
}

TEST_CASE("Test: RealVariable Error"){
    RealVariable x;
    CHECK_THROWS(solve(x*0==4));
    CHECK_THROWS(solve(x + 1 == x));
    CHECK_THROWS(solve((x^0) == 0));
    CHECK_THROWS(solve(x == x));
    CHECK_THROWS(solve(x-x==0));
    CHECK_THROWS(solve(2*x/x==0));
    CHECK_THROWS(solve(34*x-34*x==67));
    CHECK_THROWS(solve(x==x-x+x));
    CHECK_THROWS(solve(x=2+x));
    CHECK_THROWS(solve(2*x==4*x/2*x));
    CHECK_THROWS(solve((x^2) == -16));
    CHECK_THROWS(solve((x*x+10==2)));
    CHECK_THROWS(solve(x*x==-1));
    CHECK_THROWS(solve(x+0=x));
    CHECK_THROWS(solve((x^2)==(x^2)));
    CHECK_THROWS(solve((x^2)+10==11));
    CHECK_THROWS(solve(0+0+x==1+x));
    CHECK_THROWS(solve(((x^3)/x)==-2));
    CHECK_THROWS(solve((x^4)/(x^2)==-1));
    CHECK_THROWS(solve(x+x==2*x));
    CHECK_THROWS(solve((x^2)==x*x));
    CHECK_THROWS(solve((x^2)==-0.5));
    CHECK_THROWS(solve(x=0+x));
    CHECK_THROWS(solve((x^4)==-3));
    CHECK_THROWS(solve((x^2)==-290));
    CHECK_THROWS(solve((x^2)==-3));
}

TEST_CASE("Test: ComplexVariable"){
    ComplexVariable x;
    CHECK(solve((x^2) == -2) == 1.414213562i);
}
//
//TEST_CASE("Test: Error ComplexVariable"){
//    ComplexVariable x;
//}