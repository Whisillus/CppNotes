// this file shows:
// 1. some misusing shared ptr

#include <memory>

// note 
// if use shared_ptr in class 
// might need std::enable_shared_from_this<>


int main(int argc, char *argv[]) {
    // do not do follow
    // pi will be release twice
    auto pi = new int(123);
    std::shared_ptr<int> sp1(pi);
    std::shared_ptr<int> sp2(pi);

    // do this
    auto sp3 = std::make_shared<int>(321);
    auto sp4(sp3);

    return 0;
}
