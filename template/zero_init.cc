// this file shows:
// 1. zero init in template

// fundamental types do not init locally and have undefined value

template <typename T>
void foo() {
    // T can be fundamental type/built-in type
    // such as int
    // we explicitly call a constructor
    T x{};
}

template <typename T>
struct MyClass {
    T x;
    MyClass() : x{} {};
};

template <typename T>
struct MyClass2 {
    T x{};
};

template <typename T>
struct MyClass3 {
    T x;
    MyClass3() : x(){};  // before c++11, {} cannot be used
};

int main() {
    //
    return 0;
}
