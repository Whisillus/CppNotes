// This file shows:
// 1. substitution failure is not an error

struct sfinae_t {
    /* data */
    using foo = int;
};

template <typename T>
void f(typename T::foo) {}

template <typename T>
void f(T) {}

int main(int argc, char *argv[]) {
    f<sfinae_t>(10); // f #1
    f<int>(10); // f #2
    return 0;
}
