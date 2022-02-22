// This file shows
// 1. friend in template class
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

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

    // way 1
    // instantiated wit hclass template if needed
    // operator<< is a nonmember function
    // templated entity
    friend std::ostream& operator<<(std::ostream& strm, Stack<T> const& s) {
        s.printOut(strm);
        return strm;
    }

    // way 2
    // alternative, we declare then define
    // use a different template parameter
    // here we cannot use T for template parameter
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, Stack<U> const&);

};  // class Stack

// way 3
// forward declare
// we first have to forward declare the template class

template <typename T>
class Test;
template <typename T>
void doSomething();

template <typename T>
class Test {
    friend void doSomething();
};

int main() { return 0; }
