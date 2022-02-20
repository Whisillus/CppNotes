// This file shows:
// 1. specialization of template class
// 2. partial specialization of template class
// 3. partial specialization with multiple paras

#include <cassert>
#include <deque>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// if we specialize a class template, we must specialize all member functions
// we can specialize a single member function of class template
// if do so, we can no longer specialize the whole class template instance
//

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

// 1. specialization of template class
// declare with leading template<>
template <>
class Stack<std::string> {
    // add std::string above
    // the specification of the type
private:
    std::deque<std::string> elems;

public:
    // change original T to std::string
    void push(std::string const& elem);
    void pop();
    std::string const& top() const;
    bool empty() const { return elems.empty(); }
};

// we have no template <typename T> here
std::string const& Stack<std::string>::top() const {
    assert(!elems.empty());
    return elems.back();
}
// 1 done

// 2. partial specialization of class template
// we have typename T in the <>
template <typename T>
class Stack<T*> {
    // we have T* in the <>
private:
    std::vector<T*> elems;

public:
    void push(T*);
    T* pop();
    T* top() const;
    bool empty() const { return elems.empty(); }
};

// we have template <typename T> here
template <typename T>
T* Stack<T*>::top() const {
    assert(!elems.empty());
    return elems.back();
}
// 2 done

// specializaton with multiple parameters
template <typename T1, typename T2>
class Test {};

// type 1
template <typename T>
class Test<T, T> {};

// type 2
template <typename T>
class Test<T, int> {};

// type 3
template <typename T1, typename T2>
class Test<T1*, T2*> {};

int main() {
    Test<int, double> tid;     // use Test<T1, T2>
    Test<double, double> tdd;  // use Test<T, T> type 1
    Test<double, int> tdi;     // use Test<T, int> type 2
    Test<int*, double*> tpp;   // use Test<T1*, T2*>

    // careful : ambiguous
    // Test<int, int> tii;
    // Test<int*, int*> tpp;

    return 0;
}
