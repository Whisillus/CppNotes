// this file shows:
// 1.how to init the array with smart ptr
//

#include <memory>

int main(int argc, char* argv[]) {
    std::shared_ptr<int> pint(new int[10], std::default_delete<int[]>());

    // for unique_ptr
    std::unique_ptr<int[]> pint_uni(new int[100]);
    // or
    // second template aug must be specified
    auto del_uni = [](int* p) { delete[] p; };
    std::unique_ptr<int, void (*)(int*)>(new int[123], del_uni);
    return 0;
}
