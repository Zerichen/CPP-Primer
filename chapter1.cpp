//
// Created by Chen Zhao on 6/30/20.
//
#include <iostream>
#include "chapter1.h"

using namespace std;

void iodemo(void) {
//        although length is only 1, but cout will continue to find the null character
//        it will print out the whole input regardless of the variable size
//        it is a dangerous undefined behavior
    char name[1];
    int age;
    cout << "What's your name?" << endl;
    cin >> name;
    cout << "What's your age?" << endl;
    cin >> age;
//         << will return its left operator, si the expression can be chained
    cout << "My Name is: " << name << ", who is " << age << " years old." << endl;
}

