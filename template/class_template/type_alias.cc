
// This file shows:
// 1. class type alias with typedef or using
// 2. alias with template

#include <deque>
#include <vector>

template <typename T, typename Cont = std::vector<T>>
class Stack {
    // keyword typename is necessary here!
    using iterator = typename Cont::iterator;
};

using IntStack = Stack<int>;  // since c++11
// typedef Stack<int> i_stack;

template <typename T>
using DequeStack = Stack<T, std::deque<T>>;

template <typename T>
using StackIterator = typename Stack<T>::iterator;

// suffix _t
// since c++14
// we can write
//
// std::add_const_t<T>
// instead of (c++11)
// typename std::add_const<T>::type
//
// the std define
// namespace std {
// template<typename T> using add_const_t = typename add_const<T>::type;
// }
