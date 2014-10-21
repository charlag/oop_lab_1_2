//
//  Rational.cpp
//  lab1_2
//
//  Created by Иван Купалов on 30.09.14.
//  Copyright (c) 2014 avalank. All rights reserved.
//

#include "Rational.h"

Rational::Rational() {
    numerator = 1;
    denominator = 1;
}

Rational::Rational(int numer, int denom) {
    int gcd = greatestCommonDiviser(numer, denom);
    if (gcd != 0) {
        numerator = numer / gcd;
        denominator = denom / gcd;
    }
}

void Rational::print() {
    if (denominator == 1) {
        std::cout << std::to_string(numerator) << std::endl;
    } else {
        std::cout << std::to_string(numerator) + "/" + std::to_string(denominator) << std::endl;
    }
}

int Rational::greatestCommonDiviser(int first, int second) {
    while (first != 0 && second != 0) {
        if (first > second) {
            first = first % second;
        } else {
            second = second % first;
        }
    }
    return first + second;
}

bool Rational::operator==(const Rational& right) {
    return right.numerator == numerator && right.denominator == denominator;
}

const Rational Rational::operator+(const Rational& right) {
    int lcm = abs(denominator * right.denominator)/Rational::greatestCommonDiviser(denominator, right.denominator);
    int mul1 = lcm / denominator;
    int mul2 = lcm / right.denominator;
    int newNumerator = numerator * mul1 + right.numerator * mul2;
    return Rational(newNumerator, lcm);
}

const Rational Rational::operator-(const Rational& right) {
    int lcm = abs(denominator * right.denominator)/Rational::greatestCommonDiviser(denominator, right.denominator);
    int mul1 = lcm / denominator;
    int mul2 = lcm / right.denominator;
    int newNumerator = numerator * mul1 - right.numerator * mul2;
    return Rational(newNumerator, lcm);
}

const Rational Rational::operator*(const Rational& right) {
    return Rational(numerator * right.numerator, denominator * right.denominator);
}

const Rational Rational::operator/(const Rational& right) {
    return Rational(numerator * right.denominator, denominator * right.numerator);
}


bool Rational::operator<(const Rational& right) {
    int lcm = abs(denominator * right.denominator)/Rational::greatestCommonDiviser(denominator, right.denominator);
    int mul1 = lcm / denominator;
    int mul2 = lcm / right.denominator;
    return (numerator * mul1) < (right.numerator * mul2);
}

bool Rational::operator>(const Rational& right) {
    return !(*this < right);
}

bool Rational::operator!=(const Rational& right) {
    return !(*this == right);
}
