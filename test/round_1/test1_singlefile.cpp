#include <bits/stdc++.h>
using namespace std;

/**
 * @brief A's discription
 * 
 */
class A {
public:
    void A_method_1() {

    }
    void A_method_2() {

    }
    void A_function_1() {

    }
private:
    int A_int;
    double A_double;
};

class B : A {  // no discription
public:
    void B_method_1() {

    }
    void B_method_2() {

    }
    void B_function_1() {

    }
private:
    int B_int;
    double B_double;
};

class C{

};

class D: public A, private B{

};

class E{}

void f() {
    
}
int main() {
    return 0;
}