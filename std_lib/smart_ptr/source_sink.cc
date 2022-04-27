// this file shows:
// 1. use unique ptr as source and sink

#include <iostream>
#include <memory>
void sinkFunc(std::unique_ptr<int> upv) {
    // ... do something
    // upv will be deleted on function exit
}

auto sourceFunc() {
    auto upi = std::make_unique<int>(321);
    return upi;
}

int main(int argc, char *argv[]) {
    auto upi = std::make_unique<int>(114514);
    // sinkFunc(upi);
    sinkFunc(std::move(upi));
    upi = sourceFunc();
    return 0;
}
