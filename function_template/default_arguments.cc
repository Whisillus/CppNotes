// Prior to c++11, default template args were only permitted in class tamplates
// This file shows
// 1. An example of default template arguments
//
#include <type_traits>
template <typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
RT max(T1 v1, T2 v2) {
    return v1 > v2 ? v1 : v2;
}
int main() {
    auto res = ::max(123, 123.321);  // return double
    auto res_2 = ::max<int, double,
                       long double>(123, 321.123);  // return long double
    auto res_3 = ::max<int, double>(123, 123.321);  // return double
    return 0;
}
