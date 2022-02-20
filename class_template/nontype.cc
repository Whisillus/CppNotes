// This file shows
// 1. define template with nontype paras
// 2. nontype paras are pointers
// 3. deduce type of nontype paras
#include <array>
#include <cassert>
#include <cstddef>

// the type of nontype template paras should be specified
// and default args can be specified too
//
// Note that the nontype paras can be only
// const int or enumerations
// pointers to obj/func/members
// lvalue references to obj or func
// std::nullpty_t
template <typename T, std::size_t size = 100>
class Stack {
    std::array<T, size> elems;
    std::size_t num_elems;

public:
    Stack();
    void push(T const& elem);
};  // class Stack
template <typename T, std::size_t size>
Stack<T, size>::Stack() : num_elems(0) {}

template <typename T, std::size_t size>
void Stack<T, size>::push(T const& elem) {
    assert(num_elems < size);
    elems[num_elems] = elem;
    ++num_elems;
}

// class template paras are pointers
template <char const* name>
class PtrClass {};
extern char const str3[] = "Hi";  // external linkage
char const str4[] = "hi!";        // internal linkage

// template with decltype(auto)
// TODO more detail needed
template <decltype(auto) N>
class Test {};

int n = 123;
Test<(n)> test;

int main() {
    // use the Stack<T ,size>
    Stack<int, 10> st;  // size = 10
    Stack<int> st2;     // size = 100
    // st and st2 have different types

    st.push(1);

    // when passing template args to pointers or refs
    // the objec must not be
    // string literals
    // temporaries
    // data member
    // subojects

    // PtrClass<"hello"> error_example;
    PtrClass<str3> s3;  // ok
    PtrClass<str4> s4;  // ok since c++11
    static char const str5[] = "hi!!";
    PtrClass<str5> s5;  // ok since c++17

    return 0;
}
