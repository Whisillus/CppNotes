// this file shows
// 1. remove reference especially in return

#include <type_traits>

// both T are possibliy deduced as reference
template <typename T>
T func(T v) {
    return 1123;
}

template <typename T>
T funcrv(T &&) {
    return T{};
}

// solution 1
template <typename T>
std::remove_reference_t<T> funcSolOne(T v) {
    return 123;
}

// solution 2
template <typename T>
auto funcSolTwo(T v) {
    return 123;
}

int main(int argc, char *argv[]) {
    int i{1};
    // func<int&>(i); // return int& ----> not good
    // funcrv(i); // return int& ----> not good
    funcSolOne<int&>(i);
    funcSolTwo<int&>(i);
    return 0;
}
