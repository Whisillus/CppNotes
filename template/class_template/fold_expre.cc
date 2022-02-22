// This file shows:
// 1. define and use fold expression

#include <iostream>

// (... op pack) => (((pack1 op pack2) op pack3) ... op packN)
// (pack op ...) => (pack1 op (...(packN-1 op packN)))
// (init op ... op pack) => (((init op pack1) op pack2) ... op packN)
// (pack op ... op init) => (pack1 op (... (packN op init)))

template <typename... Types>
void print(Types const&... args) {
    (std::cout << ... << args) << std::endl;
}

int main() {
    print("123123", 987, "fajkdsl");
    return 0;
}
