#include <iostream>
#include "chapter1.h"
#include "chapter2.h"
#include "chapter3.h"
#include "chapter4.h"

using namespace std;
//using variable defined in chapter2.cpp
//it is error to write extern int e = 4;
extern int e;
extern const int f;
double Double = 3.145;

int main() {
    typeConversion();
    return 0;
}
