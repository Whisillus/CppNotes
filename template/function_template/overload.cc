

int max(int v1, int v2) { return v1 > v2 ? v1 : v2; }

template <typename T>
T max(T v1, T v2) {
    return v1 > v2 ? v1 : v2;
}

// overload for return type
// not a good idea
template <typename RT, typename T>
RT max(T v1, T v2) {
    return v1 > v2 ? v1 : v2;
}

// overload for pointers
template <typename T>
T* max(T* v1, T* v2) {
    return v1 > v2 ? v1 : v2;
}

// overload for c-strings
char const* max(char const* v1, char const* v2) { return v1 > v2 ? v1 : v2; }

int main() {
    // The overload resolution process prefers the nontemplate over one
    // generated from the template
    ::max(1, 2);      // call non-template function
    ::max(1.2, 3.2);  // call max<double> by argument deduction

    // explicit use a template
    ::max<>(1, 2);  // call max<int> by argument deduction

    // automatic type conversion is not considered for deduced template paras.
    // but is considered for ordinary function paras
    ::max('a', 123);  // call non-template function

    // error
    // two templates match => ambiguous
    // ::max<int>(123,321);

    return 0;
}
