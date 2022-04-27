// this file shows:
// 1.how to define a deleter
// 2.use deleter with array

#include <iostream>
#include <memory>
#include <string>

int main(int argc, char* argv[]) {
    // delete
    auto del = [](std::string* p) {
        std::cout << "delete --->>> " << *p << std::endl;
    };
    std::shared_ptr<std::string> pname(new std::string("Chen"), del);
    pname = nullptr;

    // array
    // std::shared_ptr<int> p(new int[100]); // wrong prior to c++17
    std::shared_ptr<int> p(new int[100], std::default_delete<int[]>());
    p = nullptr;

    // for unique_ptr
    std::unique_ptr<int[]> pint_uni(new int[100]);
    // or
    // second template aug must be specified
    auto del_uni = [](int* p) { delete[] p; };
    std::unique_ptr<int, void (*)(int*)>(new int[123], del_uni);

    return 0;
}
