// this file shows
// 1. how to use enable_if<>
//

#include <iostream>
#include <type_traits>

// 1
// if sizeof(T) > 4 yields false, the function template with enable_if expr. is
// ignored
// ... yields true, enable_if will return a prespecific type(2nd arg)
template <typename T>
std::enable_if_t<(sizeof(T) > 4), T> foo() {
    std::cout << "foo() is called" << std::endl;
    return T();
}

// or we can write in this way
template <typename T, typename = std::enable_if_t<(sizeof(T) > 4)>>
void foo2(){};

// or
template <typename T>
using EnableIfSizeGreater4 = std::enable_if_t<(sizeof(T) > 4)>;
template <typename T, typename = EnableIfSizeGreater4<T>>
void foo3() {
    std::cout << "foo3() is called" << std::endl;
};

int main(int argc, char *argv[]) {
    // foo<int>(); //raise no match function
    foo<double>();
    foo3<double>();

    return 0;
}
