// This file shows:
// 1. define a templatized aggregates
// 2. define aggregate class with deduction guide
#include <iomanip>
#include <iostream>
#include <type_traits>

template <typename T>
struct Agg {
    T value;
};

Agg(int)->Agg<double>;

int main() {
    Agg ai{1};
    std::cout << std::boolalpha;
    std::cout << "ai is a Agg<double>: "
              << std::is_same_v<decltype(ai),
                                Agg<double>> << std::endl;  // true
    std::cout << "ai is a Agg<int>: "
              << std::is_same_v<decltype(ai), Agg<int>> << std::endl;  // false
    return 0;
}
