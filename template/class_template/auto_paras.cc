// This file shows
// 1. template paras with auto
// 2. auto with template class member function

#include <array>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <type_traits>

template <typename T, auto MaxSize>
class Stack {
public:
    using size_type = decltype(MaxSize);

    Stack();
    void push(T const&);

    size_type size() const { return curr_size; }

    auto sizeMod() const {
        // with auto
        // since c++14
        return curr_size;
    }

private:
    std::array<T, MaxSize> elems;
    size_type curr_size;
};  // class Stack

template <typename T, auto MaxSize>
Stack<T, MaxSize>::Stack() : curr_size(0) {}

template <typename T, auto MaxSize>
void Stack<T, MaxSize>::push(T const& elem) {
    assert(curr_size < MaxSize);
    elems[curr_size] = elem;
    ++curr_size;
}

int main() {
    Stack<int, 10> st;
    st.push(1);
    std::cout << "Current stack size: " << st.size() << std::endl;
    st.push(1);
    std::cout << "Current stack size: " << st.sizeMod() << std::endl;
    auto size = st.sizeMod();
    std::cout << std::boolalpha;
    std::cout << "sizeMod() return int: "
              << std::is_same_v<decltype(size), int> << std::endl;
    return 0;
}
