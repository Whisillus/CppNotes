// This file shows
// 1. define function template with nontype paras

// Note that the nontype paras can be only
// const int or enumerations
// pointers to obj/func/members
// lvalue references to obj or func
// std::nullpty_t
template <typename T, int V = 0>
T addV(T x) {
    // this can be useful if functions or operations
    // are used as paras
    return V + x;
}

template <typename T, T V = T{}>
T addVMod1();

template <auto V, typename T = decltype(V)>
T addVMod2();

int main() { return 0; }
