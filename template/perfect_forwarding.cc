// This file shows:
// 1. how to use perfect forwarding
// 2. rules of T&&
//

// 2. rules of X&& and T&&
// - X&& for a specific type X declares a parameter to be an rvalue reference.
//   It can only be bount to a movable obj.
// - T&& for a template parameter T declares a forwarding reference(universal
// reference)

#include <iostream>
#include <utility>

void g(int &) { std::cout << "g(int&) is called" << std::endl; }
void g(int const &) { std::cout << "g(int const &) is called" << std::endl; }
void g(int &&) { std::cout << "g(int&&) is called" << std::endl; }

template <typename T>
void f(T &&val) {
    g(std::forward<T>(val));
}

int main(int argc, char *argv[])
{
    int i = 0;
    int ci = 123;

    f(i);
    f(ci);
    f(1);
    f(std::move(i));
    return 0;
}
