// this file shows:
// 1.using typename to show xxx is a type

#include <iostream>
#include <vector>

template <typename T>
struct ExampleOne {
    // case 1
    // we need typename
    using iter = typename T::iterator;
    // case 2
    // we do not need it
    using iterv = std::vector<int>::iterator;
};

int main() { return 0; }

