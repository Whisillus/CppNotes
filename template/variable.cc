// This file shows:
// 1. how to use variable template
// 2. variable template with nontype paras

#include <iostream>
#include <array>

// normal define
template <typename T>
constexpr T pi{3.1415926535897};

// define with zero init
template <typename T>
T val{};

//define with default typename
template <typename T = int>
T val2{123};

// 2. with nontype paras and zero init
template<int N>
std::array<int, N> arr{};

int main(int argc, char *argv[]) {
    std::cout << pi<double> << std::endl;
    std::cout << pi<float> << std::endl;

    // assignment of template var
    val<long long> = 42;
    std::cout << val<long long> << std::endl;


    // std::cout << val2 << std::endl; // ERROR
    std::cout << val2<> << std::endl; // angle bracket must follow

    arr<10>[0] = 4124;
    for(size_t i = 0; i < arr<10>.size(); i++) {
        std::cout<<arr<10>[i]<<" ";
    }
    std::cout << std::endl;

    return 0;
}
