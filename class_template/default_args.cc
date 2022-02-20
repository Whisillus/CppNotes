// This file shows
// 1. default calss template arguments

#include <cassert>
#include <deque>
#include <vector>

template <typename T, typename Cont = std::vector<T>>
class Stack {
private:
    Cont elems;

public:
    void push(T const&);
};

// even Cont has default value
// we need to specify here
template <typename T, typename Cont>
void Stack<T, Cont>::push(T const& elem) {
    elems.push_back(elem);
}

int main() {
    Stack<int> iv;
    Stack<int, std::deque<int>> id;

    iv.push(1);
    id.push(2);
    return 0;
}
