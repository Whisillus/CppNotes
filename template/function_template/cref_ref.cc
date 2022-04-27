// This file shows
// 1. how to use std::cref() and std::ref()
//

#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>

void printStr(std::string const& s) {
    std::cout << s << std::endl;
}

template <typename T>
void funcV(T v) {
    // not good for reference_wrapper<>
    // std::cout << v << std::endl;
    printStr(v); // do like this
    return;
}

int main(int argc, char *argv[]) {
    std::string s{"abc"};
    funcV(s);             // pass by value
    funcV(std::cref(s));  // pass as if by reference
    // type of std::cref(s) is std::reference_wrapper<string const>
    // therefore, we cannot directly operate on it

    return 0;
}
