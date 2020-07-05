//
// Created by Chen Zhao on 7/2/20.
//
#include <iostream>
#include <string>
#include <vector>
#include "chapter3.h"

using namespace std;

void waysofinitialization() {
    string s1; // empty string initialization
    string s2 = s1; // a copy of s1, copy initialization
    string s3(s1); // direct initialization
    string s4("value"); // a copy of string literal, , copy initialization
    string s5 = "value"; // direct initialization
    string s6(5, 'a'); // 5 copies of 'a'
    string s8 = string(3, 'c'); // same as string temp(3, 'c'); string s8 = temp; more readable
//    when we mix strings and string or character literals, at least one operand to each + operator must be of string type
    string s9 = s1 + ", " + "world"; // ok: each + has a string operand
//    string s10 = "hello" + ", " + s2; // error: can't add string literals
}

void readwords() {
    string words;
    while(cin >> words) {
        cout << words << endl;
    }
}

void readline() {
    string line;
    string::size_type sz; // type returned by line.szie()
    while (getline(cin, line)) {
        if (line.empty() or (line.size() > 80)) {
            cout << "too little or too many" << endl;
            sz = line.size();
        }
        cout << line << endl;
    }
    cout << sz << endl;
}

void iteration() {
    string s("abcde");
    for (auto c : s) {
        cout << c << endl;
    }

    string h("Hello World");
    for (auto &c : h) { // we use reference because otherwise we cannot modifying the character in h but only a copy of it
        c = toupper(c);
    }
    cout << h << endl;

    string g("This is a test");
    for ( decltype(s.size()) i = 0; i < g.size(); i++)
    {
        g[i] = toupper((g[i]));
    }
    cout << g << endl;

    string str("randomstring"); // change all char into Y
    for (auto i = 0; i < str.size(); str[i++] = 'Y');
    cout << str << endl;
}

void vectorInitialization() {
//    we can have vector contains vector, but not reference, since it is not a type
    vector<int> ivec;
    vector<vector<int>> vvec;

//    ways of initialization
    vector<int> v1; // empty
    vector<int> v2(v1); // v2 has a copy of v1
    vector<int> v3 = v1; // same as v2, copy initialization
    vector<int> v4(10, 3); // 10 elements of 3
    vector<int> v5(10); // n copies of value initialized object, 0 for int and empty string for string
    vector<int> v6 = {1, 2, 3, 4, 5};
    vector<int> v7{1, 2, 3, 4, 5}; // same as v6

//    no type confusion, so {} can be used for initialization
    vector<string> v8{10}; // 10 elements
    vector<string> v9{10, "hi"}; // 10 elements of "hi"

    string c;
    while (cin >> c) {
        v8.push_back(c);
    }
}

void vectorOperation() {
    string c;
    vector<string> words;
    while (cin >> c) {
        words.push_back(c);
    }
    cout << words[1] << endl;

//    a vector type always includes its element type
    vector<int>::size_type a;
//    vector::size_type b; // error

//    we can only compare two vectors when their elements are comparable
//    we can only use push back to add elements for a size 0 vector
}

void iterators() {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4, 5};
    vector<int> ve;
    auto a = ++v.begin(), b = v.end(); // 2
    auto c = ve.begin(), d = ve.end(); // c == d
    cout << *(--a) << " " << *(++a) << endl; // 1, 2

    v2[0] = 2;
    cout << v[0] << " " << v2[0] << endl;

    string s("some string");
    if (s.begin() != s.end()) { // make sure s is not empty
        auto it = s.begin(); // we don't need reference since iterator is an object, cann't be copied
        *it = toupper(*it); // make first character uppercase
    }
    cout << s << endl;

//    if vector or string is const, we can only use const_iterator
	vector<int>::iterator it; // it can read and write vector<int> elements 
	string::iterator it2; // it2 can read and write characters in a string
	vector<int>::const_iterator it3; // it3 can read but not write elements, like a const pointer
	string::const_iterator it4; // it4 can read but not write characters
	
//	the type returned by begin and end depends on the object is whether const or nor
	vector<int> v3;
	auto it5 = v3.cbegin(); // it has type vector<int>::const_iterator
	
	vector<string> vstr;
	vstr.push_back("Hello");
	vstr.push_back("World");
	vstr.push_back("!!!");
	auto it6 = vstr.begin();
	cout << it6->empty() << " " << (*it6).empty() << endl;
//	(*it).empty is the same as it->empty()
	
	auto mid = vstr.begin() + vstr.size() / 2;
//	when comparing iterators, they must be valid and are from the same vector or string, except for vstr.end()
	if (it6 < mid) {
		cout << "prior to mid" << endl;
	}
}

constexpr int get_size() {
    return 5;
}

int array1[2]; // array1 will have default value 0, just like variable initizialzation
string array2[2]; // array1 will have default value ""

void arrays() {
    unsigned cnt = 42; // not a const expression
    constexpr unsigned sz = 42; // const expression
//    dimension is part of array type, hence needed during compile time
    int arr[sz]; // cnt2 is a constexpr, hence can be used for array declaration
    int arr2[10]; // initial value of arr without initizalization is undefined
    string strs[get_size()]; // ok if get_size is constexpr, error otherwise

//    auto arr[2] = {1, 2} // error
//    array cannot hold reference since it is not an object
    int a3[5] = {0, 1, 2}; // {0, 1, 2, 0, 0}

    char a4[] = {'C', '+', '+'};
    char a5[] = {'C', '+', '+', '\0'};
    char a6[] = "C++";
//    char a7[3] = "C++"; // no space for null, because there is a hiding \0 character
    char a8[3] = {'C', '+', '+'}; // with space, but the array does not have \0, could be a bit dangerous

//    char acopy[5] = a3; we cannot initialize an array from another array

    int (*Parray)[5] = &a3; // Parray is a pointer to an array of 5 int
    int (&arrayRef)[5] = a3; // arrayRef is a reference to a3
    int *ptrs[5];
    int *(&arrRef)[5] = ptrs; // arrRef is a reference to an array of 5 pointers

//    if we do not initizalize scores, the value is undefined
//    if we declare it outside the function, the value is 0
    unsigned scores[3];
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10];
    }
}

void arrayPointer() {
    string nums[] = {"hello", "world"};
    string *p = nums; // same as string *p = &nums[0]
    int ap = 3;
    int *pa = &ap;
    int ia[] = {0, 1, 2, 3, 4, 5};
    // ia2 is a int pointer to the first element in ia, deduced by auto
    auto ia2(ia); // same as auto ia2(&ia[0])
    ia2 = pa; // ia2 can point to an int

//    type deduced by decltype is still array
    decltype(ia) ia3 = {0, 1, 2, 3, 4, 5};
//    ia3 = p; // error

    int *beg = begin(ia), *last = end(ia); // pointer one past the last element of ia
    while (beg != last && *beg >= 0) {
        ++beg;
    }

    int *pp = ia + 7; // error, exceeds the total length
//    negative index is equivalent to *(p - n), vector cannot have negative index, unsigned type

//    string comarison
    const char ca1[] = "a string example";
    const char ca2[] = "b string example";
    string ca11 = "a string example";
    string ca12 = "b string example";
//    ca1 and ca2 are two pointers
    if (ca1 < ca2) { // since we are comparing two unrelated addresses
        cout << "undefined comparsion";
    }
    if (ca11 < ca12) {
        cout << "small";
    }

//    initialize vector from array
//    vice versa is not allowed
    int int_arr[] = {1, 2, 3, 4, 5};
//    each element is a copy of int_arr
    vector<int> ivec(begin(int_arr), end(int_arr));
    vector<int> sub_ivec(int_arr + 1, int_arr + 3);
}

void multidimenArray() {
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int ia2[3][4] = {{ 0 }, { 4 }, { 8 }}; // the left are all 0
    int ix[3][4] = {0, 3, 6, 9}; // it initialize the first row only
    int (&row)[4] = ix[1]; // row is a reference to the second row of ix

//    if we use auto r : ia, it won't compile
//    because r will decay to a pointer rather than an array
    for (auto &r : ia) {
        for (auto c : r) {
            cout << c << " ";
        }
    }
}














