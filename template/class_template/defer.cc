// This file shows:
// 1. defer the evaluation for incomplete type
//

#include <string>
#include <type_traits>
template <typename T>
class Cont {
private:
    T* elems;

public:
    template <typename D = T>
    std::conditional_t<std::is_move_constructible<D>::value, T&&, T&> foo();
    // using below makes Node incomplete
    // we can defer the evaluation
    // std::conditional_t<std::is_move_constructible<T>::value, T&&, T&> foo();
};

struct Node {
    std::string value;
    Cont<Node> next;
};

int main() { Node n{}; }
