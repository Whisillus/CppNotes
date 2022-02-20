// This file shows
// 1. how to define class template by example of stack
// 2. how to use class template
// 3. partial usage of template

#include <cassert>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// Type of class is Stack<T>
// we have to use Stack<T> whenever we use the type of this class
// except in cases there the template arguments can be deduced
template <typename T>
class Stack {
private:
    std::vector<T> elems;

public:
    // Inside a class tempalte
    // class name do not follow by template arguments
    Stack() = default;

    void push(T const& elem);
    void pop();
    T const& top() const;
    bool empty() const { return elems.empty(); }
    void printOut(std::ostream& os);
};  // class Stack

template <typename T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T>
T const& Stack<T>::top() const {
    assert(!elems.empty());
    return elems.back();
}

template <typename T>
void Stack<T>::printOut(std::ostream& os) {
    for (T const& elem : elems) {
        os << elem << " ";
    }
    os << "\n";
}

// Class template CANNOT define inside funtion or block scope
// In general, templates can only be defined in global, namespace scope or
// inside class declarations
//

int main() {
    // until c++17, the template arguments must be specified explicitly
    Stack<int> int_stack;

    int_stack.push(1);
    std::cout << int_stack.top() << std::endl;
    int_stack.pop();

    // Code is instantiated ONLY for template member functions that are called
    // Template arguments only have to provide all necessary operations taht are
    // needed
    //
    // we can still use this stack_stack
    // but we cannot use stack_stack.printOut
    // bcs. Stack<int> do not have operator <<
    Stack<Stack<int>> stack_stack;
    stack_stack.push(int_stack);
    // stack_stack.printOut(std::cout);

    return 0;
}

