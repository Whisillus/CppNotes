// this file shows:
// 1.how to define a unique_ptr
// 2.how to use unique_ptr

#include <iostream>
#include <memory>
int main(int argc, char *argv[]) {
    // way 1
    auto upi = std::make_unique<int>(123);
    // way 2
    std::unique_ptr<int> upi_1;
    upi_1.reset(new int(222));
    // way 3
    std::unique_ptr<int> upi_2(new int(321));

    if (upi) std::cout << "upi is: " << *upi << std::endl;
    if (upi != nullptr) std::cout << "upi is: " << *upi << std::endl;
    if (upi_1.get() != nullptr) std::cout << "upi_1 is: " << *upi_1 << std::endl;
    return 0;
}
