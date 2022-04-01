// This file shows
// 1. pass value by reference in template
// 2. special case with const
// 3. use enable_if<> to disable passing constant

#include <iostream>
#include <string>
#include <type_traits>

// 1.
template <typename T>
void passByRef(T& i) {
    std::cout << " passByRef is called" << std::endl;
    return;
}

// 3.
template <typename T, typename = std::enable_if_t<!std::is_const_v<T>>>
void passByRefNoConst(T& i) {
    std::cout << " passByRefNoConst is called" << std::endl;
    return;
}

std::string returnStr() { return std::string("abc"); }
std::string const returnConstStr() { return std::string("abc"); }

int main(int argc, char* argv[]) {
    std::string s{"common"};
    std::string const cs{"const"};

    passByRef(s);  // okay
    // passByRef(std::string{"hi"}); // not okay
    // passByRef(returnStr()); // not okay
    // passByRef(std::move(s)); // not okay

    // 2. special case
    // the follows are okay
    // but any modification inside the passByRef() will raise an error
    passByRef(cs);
    passByRef(returnConstStr());
    passByRef(std::move(cs));
    passByRef("hi");

    // error
    // passByRefNoConst(cs);

    return 0;
}

