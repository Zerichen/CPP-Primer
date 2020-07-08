//
// Created by Chen Zhao on 7/8/20.
//

#include <iostream>
#include "chapter5.h"

using namespace std;

void statement() {
    char ch = 'c';
    int ival = 8;
//    switch requires integral const expression
    switch (ival) {
//        case 3.14: // not a integral type expression
//            break;
//        case ival: // not a const expression
//            break;

//        will print 567, since once the case matched
//        the following cases will all be executed unitl a break
        case 5:
            cout << 5;
        case 6:
            cout << 6;
        case 7:
            cout << 7;
//        if no match, the default condition will be executed
        default:
            cout << "no match";
            break;
    }

//    we cannot initialize variable inside a case
//    we can avoid this by adding curly braces to qualify its scope

//    i is invalid in while condition since it is inside a block scope
//    do while loop does not support statement scope
//    do {
//        int i = 8;
//    } while (i == 8);

//    Unlike a break, a continue may appear inside a switch
//    only if that switch is embedded inside an iterative statement
}
