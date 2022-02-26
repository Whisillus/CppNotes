#include <iostream>
#include <string>

template <typename T>
T max(T v1, T v2) {
    return v1 < v2 ? v2 : v1;
}

// Default arguments for deduction
template <typename T>
int defaultFunctionValue(T = "");
// It is okay:
// int i = defaultFunctionValue(1);
// we cannot use like this for type deduction reason:
// int i = defaultFunctionValue();
// but we can do following
template <typename T = std::string>
void defaultTemplateValue(T = "");
// It is okay:
// defaultTemplateValue();
//

// paras. type deduction
// rule 1: When declaring call parameters by reference, even trivial conversions
// do not apply to type deduction.
// rule 2: when declaring call parameters by value, only trivial conversions
// that decay are supported:
// const/volatile are ignored
// references => referenced type
// raw array/functions => pointer

int main() {
    int i = 123;
    int const ci = 1234;
    int& ri = i;
    int arr[3];

    ::max(i, ci);    // T is int
    ::max(ci, ci);   // T is int
    ::max(i, ri);    // T is int
    ::max(&i, arr);  // T is int*

    //::max(4, 1.2); error
    // std::string s;
    //::max("123", s); error

    return 0;
}
