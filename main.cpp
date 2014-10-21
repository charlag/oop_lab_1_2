//
//  main.cpp
//  lab1_2
//
//  Created by Иван Купалов on 30.09.14.
//  Copyright (c) 2014 avalank. All rights reserved.
//

#include <iostream>
#include "Rational.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    Rational test1(1,3);
    std::cout << "test1: ";;
    test1.print();
    Rational test2(2, 4);
    std::cout << "test2: ";;
    test2.print();
    
    if (test1 == test2) {
        cout << "test1 is equal to test2" << endl;
    }
    
    if (Rational() > test2) {
        cout << "1 is greater then ";
        test2.print();
    }
    
    Rational sum = test1 + test2;
    cout << "Sum: ";
    sum.print();
    
    Rational diff = test2 - test1;
    cout << "Diff: ";
    diff.print();
    
    Rational mul = test1 * test2;
    cout << "Mul: ";
    mul.print();
    
    Rational quot = test1 / test2;
    cout << "Quot: ";
    quot.print();
    return 0;
}
