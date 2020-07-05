//
// Created by Chen Zhao on 6/30/20.
//
#include <iostream>
#include <string>
#include "chapter2.h"
#include "Sales_data.h"

using namespace std;

int e = 3;
extern const int f = 4;

void infiniteLoop() {
    // this is an infinite loop since i can never be less than 0
    unsigned int i;
    for (i = 10; i > 0; i--) {
        cout << "loop" << i << endl;
    }
}

void octalint() {
    int i = 01;
//    \145 is octal representation of e, which is 101 in decimal
    cout << i << "\nWho goes with F\145rgus?\012" << endl;
}

void variabledemo() {
    int a{1};
    int b(2);
//  3.14 produces error because {} requires no data loss
    int c = {3};
    int d;
    string empty;
//    e is defined outside function, the default value without initialization is 0
    cout << a << " " << b << " " << c << " " << e << endl;
//    string object is default to be empty string
    cout << empty << endl;
//    why d is also 0, which should be undefined
    cout << d << endl;
//    scope demo
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
}

void reference() {
    int a = 3;
    int &refb = a;
    a = 4;
//    we are using a as a initializer actually
    int &refc = refb;
//    reference must refer to object, not literal or expression, type of reference must match
//    int &referror = 3;
    cout << refc + 1 << endl;
}

void pointer() {
    int a = 3;
//    nullptr has value 0, hence can be used as condition testing
    int *p2 = nullptr; // int *p2 = 0 is the same
    int *p = &a;
    *p = 3;
    int &refp = *p;
    refp = 4;
    cout << *p << " " << refp << " " << a << endl;
    if (p2) {
        cout << "p2 is true" << endl;
    } else {
        cout << "p2 is false" << endl;
    }
//    we cannot operate on void pointer because the type is unknown
//    void *p3 = &a;
//    int b = *p3 + 1;
//    cout << b << endl;
    int i = 42;
    cout << i << endl;
    int *ptr;
    int *&r = ptr;
    r = &i;
    *r = 0; // change i to 0
    cout << i << endl;
}

int returnVal() {
    return 5;
}

void constQualifier() {
//    const must be initialized
    const int a = returnVal(); // runtime initialization
    const int b = 5; // compile time initialization
    int d = b;
    d = 6; // although b is const, d is not
//    reference to a const variable must also be a const and cannot be changed
    const int &r = b;
//    we can use const reference to refer to non const object
    int j = 3;
    const int &refj = j;

//    here compiler will create a temporary for conversion
//    because it assumes that const will not change
//    non-const variable can not be referred
    double dval = 3.14;
//    const int tem = dval;
//    const int &rii = tem;
    const int &ri = dval;

    const double pi = 3.14; // pi is const; its value may not be changed
//    double *ptr = &pi; // error: ptr is a plain pointer
    const double *cptr = &pi; // ok: cptr may point to a double that is const
//    *cptr = 42; // error: cannot assign to *cptr

//    pointer to const can point to non-const object
    double dval2 = 3.14;
//    we cannot change cptr afterwards
    cptr = &dval2;

//    const pointer
    int errnum = 0;
    int *const curErr = &errnum; // const pointer
    *curErr = 1; // we can use curErr to change errnum since it points to non-const value
    const double pi2 = 3.14159;
    const double *const pip = &pi2; // pip is a const pointer point to const double, unmodifiable

//    we can convert non-const to const but not vice versa
    int i = 1;
    const int *ptr = &i;
//    the value iptr points to will not change, but the value ptr points to might change
//    so we won't modify the value of i via *iptr, but i may change by itself
    const int *const iptr = ptr;
//    cout << *iptr << endl;
//    *ptr = 2;
//    cout << *iptr << *ptr << i << endl;

//    this is error since low level const is not ignored here
//    the value jptr points to might change, but the value ptr2 points to will not change
//    so when we want to use *jptr to modify the value of j, it contradicts the definition of ptr2
//    const int j = 2;
//    const int *ptr2 = &j;
//    int *const jptr = ptr2;
}

//    constexpr pointer can point to non const value
int j = 0;
constexpr int *p1 = &j;

constexpr int size() {
    return 5;
}

void constExpression() {
    const int i = 0;
//    constexpr int *nperror = &i; // error because i is defined inside a function
//    we cannot make a const pointer to such unfixed addressed variable
//but j is defined outside any functions, hence we can point to it even inside the function
    constexpr int *np = &j;

//    not only does const expression requires the constexpr
//    but it must be initialized from a const expression as well
    constexpr int sz = size(); // ok only if size is a constexpr function
    const int *p = nullptr; // p is pointer to const int
    constexpr int *q = nullptr; // q is const pointer to int
}

int test = 0;
int func() {
    return ++test;
}

void typeAlias() {
    typedef int wage;
    using wage2 = int;
    wage a = 1;
    wage2 b = 2;

    typedef char *pstring;
    const pstring *p; // p is a pointer to a const pointer that points to char
    const pstring cstr = 0; // cstr is a const pointer to char
    const char *cstr2 = 0; // cstr is a pointer to a const char

//    auto sz = 0, pi = 3.14; // error: inconsistent types for sz and pi
    int i = 0;
    const int ci = i, &cr = ci;
    auto c = ci; // ignores top level const, hence c is int
    auto d = &cr; // low level const not ignored, hence d is pointer to const int
    const auto e = ci; // manually adding const
//  auto &n = i, *p2 = &ci; // error: type deduced from i is int; type deduced from &ci is const int
    const int ir = 42;
    const auto &pr = ir;

    decltype(func()) sum = 0; // it will not evaluate func
    decltype(cr) x = 0; // top level const is NOT ignored!!! unlike auto
    int j = 42, *pj = &j;
    decltype(cr + 0) y = 0;
    decltype(j) g = j; // g is a int type

//    in decltype(e), if e is a expression, then decl gives the T& type
    decltype((j)) h = j; // h is a int& type, need to be initialized, equivalent with int &h = j
//    *pj returns a lvalue, since it is an expression referring to an object, lvalue has address
    decltype(*pj) z = j; // z is int& type, since *pj return a int reference type, int &z = j
    z++; h++; // adds 2 to j
    g++; // no effect
}

int sales_data() {
    Sales_data data1, data2;
    double price = 0;
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0) {
            cout << totalRevenue / totalCnt << endl;
            return 0;
        }
        else {
            cout << "(no sales)" << endl;
            return 0;
        }
    } else {
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }
}
