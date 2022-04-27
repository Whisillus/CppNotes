// this file shows:
// 1.how to transfer the ownership

#include <iostream>
#include <memory>
int main(int argc, char *argv[]) {
    auto upi = std::make_unique<int>(123);
    // cant copy or assign a uptr if use ordinary copy semantics
    // auto upi_1(upi); // error
    auto upi_1(std::move(upi));  // okay

    std::unique_ptr<int> upi_2(new int(114514));
    // upi_2 = upi_1; // error
    upi_2 = std::move(upi_2);  // okay

    upi_2 = nullptr;
    return 0;
}
