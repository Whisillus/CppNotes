// This file shows
// 1. class template deduction  c++17
// 2. deduction guide

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template <typename T>
class Stack {
    std::vector<T> elems;

public:
    Stack() = default;
    Stack(T const& elem) : elems({elem}) {}
};
Stack(char const*)->Stack<std::string>;  // deduction guide
// whenever a string literal or C string is passed, the stack is instantiated
// for std::string

int main() {
    Stack<int> i_stack1;
    Stack<double> i_stack2;

    Stack i_stack3{i_stack1};  // since c++17
    Stack i_stack4{1.0};       // Stack<double> since c++17
    std::cout << std::boolalpha;
    std::cout << "i_stack3 is Stack<int>: "
              << std::is_same_v<decltype(i_stack3), Stack<int>> << std::endl;
    std::cout << "i_stack4 is Stack<float>: "
              << std::is_same_v<decltype(i_stack4),
                                Stack<float>> << std::endl;  // false bcs it's
                                                             // Stack<double>

    // Note that class template argument may not be deduced only partially

    Stack s_stack2{"hello"};      // Stack<std::string> deduced
    Stack s_stack3{s_stack2};     // Stack<std::string> deduced
    Stack s_stack4(s_stack2);     // Stack<std::string> deduced
    Stack s_stack5 = {s_stack2};  // Stack<std::string> deduced
    std::cout << "s_stack2 is Stack<std::string>: "
              << std::is_same_v<decltype(s_stack2),
                                Stack<std::string>> << std::endl;
    std::cout << "s_stack3 is Stack<std::string>: "
              << std::is_same_v<decltype(s_stack3),
                                Stack<std::string>> << std::endl;
    std::cout << "s_stack4 is Stack<std::string>: "
              << std::is_same_v<decltype(s_stack4),
                                Stack<std::string>> << std::endl;
    std::cout << "s_stack5 is Stack<std::string>: "
              << std::is_same_v<decltype(s_stack5),
                                Stack<std::string>> << std::endl;

    // Stack s_stack = "stack";
    // we cannot use copy init by language rules
    // Stack<char const[6]> deduced if passing T by reference (not decay)
    // Stack<char cosnt *> deduced if passing T by value (decay)

    return 0;
}
