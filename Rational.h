//
// Лабораторная работа №2
//
//  Rational.h

#ifndef lab1_2_Rational_h
#define lab1_2_Rational_h

#include <cmath>
#include <iostream>

class Rational {
public:
    Rational();
    Rational(int numer, int denom);
    void print();
    int greatestCommonDiviser(int first, int second);
    bool operator==(const Rational& right);
    bool operator!=(const Rational& right);
    const Rational operator+(const Rational& right);
    const Rational operator-(const Rational& right);
    const Rational operator*(const Rational& right);
    const Rational operator/(const Rational& right);
    bool operator<(const Rational& right);
    bool operator>(const Rational& right);
    
private:
    int numerator;
    int denominator;
};

#endif
