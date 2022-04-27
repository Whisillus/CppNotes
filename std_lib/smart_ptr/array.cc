// this file shows:
// 1.how to init the array with smart ptr
//

#include <functional>
#include <memory>

int main(int argc, char* argv[]) {
    std::shared_ptr<int> pint(new int[10], std::default_delete<int[]>());
    // auto ii = pint[1];
    auto i = *pint;

    // for unique_ptr
    // std::unique_ptr<int> pint_uni_1(new int[123]); // wrong
    std::unique_ptr<int[]> pint_uni(new int[100]);
    // auto i = *pint_uni; // wrong
    i = pint_uni[5];
    // or
    // second template aug can be specified
    auto del_uni = [](int* p) { delete[] p; };
    // 3 ways
    std::unique_ptr<int, void (*)(int*)>(new int[123], del_uni);
    std::unique_ptr<int, std::function<void(int*)>>(new int[123], del_uni);
    std::unique_ptr<int, decltype(del_uni)>(new int[123], del_uni);
    return 0;
}
