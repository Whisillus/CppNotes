#include <type_traits>

// This file shows
// 1. the example of multiple template parameters
// 2. discussion of return type

// Deal with return type
template <typename RT, typename T1, typename T2>
RT max(T1 v1, T2 v2) {
    return v1 > v2 ? v1 : v2;
}

// since c++14, we can deduce return type from return statement
// multiple return statement must match
template <typename T1, typename T2>
auto maxDeduced(T1 v1, T2 v2) {
    return v1 > v2 ? v1 : v2;
}

// In c++11, we need trailing return type
template <typename T1, typename T2>
auto maxDeduced2(T1 v1, T2 v2) -> decltype(v1 > v2 ? v1 : v2) {
    return v1 > v2 ? v1 : v2;
}
// drawback: the return type is a reference type
// we need decayed type
template <typename T1, typename T2>
auto maxDeduced2(T1 v1,
                 T2 v2) -> typename std::decay<decltype(v1 > v2 ? v1
                                                                : v2)>::type {
    return v1 > v2 ? v1 : v2;
}

// Since c++11, we can use common_type<>
template <typename T1, typename T2>
typename std::common_type<T1, T2>::type maxCommonType(T1 v1, T2 v2) {
    return v1 > v2 ? v1 : v2;
}
// this can be simplified since c++14 by adding _t after common_type
template <typename T1, typename T2>
std::common_type_t<T1, T2> maxCommonTypeSimplified(T1 v1, T2 v2) {
    return v1 > v2 ? v1 : v2;
}

int main() {
    double d = 123.321;
    int i = 123;
    // RT is explicitly given
    // T1 and T2 are deduced
    ::max<double>(i, d);

    // res is a double
    auto res = maxCommonTypeSimplified(d, i); 

    return 0;
}
