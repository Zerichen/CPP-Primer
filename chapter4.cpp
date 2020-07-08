//
// Created by Chen Zhao on 7/6/20.
//
#include <iostream>
#include <vector>
#include "chapter4.h"

using namespace std;

int getval() {
    return 5;
}

void order() {
    int i = 0;
//    the order of executing i / ++i is not guaranteed
//    cout << i << ++i;
//    only &&, ||, ?:, , operators will promise the order

//    a && b, b will be evaluated only if a is true
//    this is useful when we use the left true condition to evaluate the right condition
//    for example: i < s.size() && s[i] != "" ensures that the index will never go out of range
//    a || b, b will be evaluated only if a is false

    bool t = true; // 1
    bool tn = -t; // tn is -1, non-zero value hence true as well

    int m = -21 / 8; // -2
    int n = -21 % 8; // -5

    int val = 0;
    bool valu = true;
    if (val); // when val is non-zero
    if (!val); // when val is zero
    if (val == true); // when int val is 1!!!
    if (valu == true); // when valu is true as a boolean

//    without parenthese, i = (getval() != 1) = 1
    if (i = getval() != 1) {
        cout << "no () " << i;
    } else if ((i = getval()) != 1) {
        cout << "with () " << i;
    }

    vector<int> s = {1, 2, 3, 4, 5};
    int ival = 0;
    auto beg = s.begin();
    while (beg != s.end() && !isspace(*beg))
//   error: this assignment is undefined
//   we are both changing the left and right side of the assignment of beg
        *beg = toupper(*beg++);

//    this expression is also undefined, <= does not specify the order of evaluation
    if (s[ival++] <= s[ival]); // this expression is undefined,
    if (s[ival] <= s[++ival]); // this is also undefined, we are changing the value of ival

    int grade = 59;
    cout << ((grade > 90) ? "high pass" : ((grade < 60) ? "fail" : "pass")) << endl;

//    sizeof() returns 24 for vector, it is actually 3 pointer size
//    https://stackoverflow.com/questions/34024805/c-sizeof-vector-is-24#:~:text=The%2024%20size%20you%20see,end%20of%20vector
    cout << sizeof(s) << " " << s.size() << endl;

    int someValue = 1, x = 0, y = 0;
    someValue ? ++x, ++y : --x, --y;
//    the same as (someValue ? ++x, ++y : --x), --y
    cout << x << " " << y << endl; // 1, 0
}

void typeConversion() {
//    implicit conversion, 3 is converted to double, then double to int
    int a = 3.41 + 3; // a = 6
//    non-bool value is converted to bool

//    the result is promised to be accurate
    unsigned int b = 3;
    int c = -3;
    int d = b + c; // d = 0

//    static cast
    double slope = static_cast<double>(b);
    void *p = &d;
    double *dp = static_cast<double*>(p);

//    const_cast, cast away const
    const char *pc;
    char *pcc = const_cast<char*>(pc);
}

