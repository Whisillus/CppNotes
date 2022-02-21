// This file shows:
// 1. define a variadic template
// 2. overload with normal template
// 3. print number of remaining types
// 4. variadic indices
// 5. variadic class template

#include <iostream>
#include <vector>

// if two functions templates only differ by a trailing parameter pack
// the function template without paramter pack is preferred.
template <typename T>
void print(T arg) {
    std::cout << arg << "\n";
}

template <typename T, typename... Types>
void print(T first_arg, Types... args) {
    print(first_arg);
    print(args...);
}

template <typename... T>
void printDouble(T const&... args) {
    print(args + args...);
}

template <typename T, typename... Types>
void printNum(T first_arg, Types... args) {
    std::cout << "Number of remaining types: " << sizeof...(Types) << "\n";
    std::cout << "Number of remaining args: " << sizeof...(args) << "\n";
}

// indices
template <typename T, typename... Idx>
void printElems(T const& p, Idx... i) {
    print(p[i]...);
}

template <typename... T>
class Test {};

int main() {
    // use variadic
    std::string s{"asdfjkl"};
    print(s, 1.2, "ewrrewq");
    printDouble(s, 1.2);

    printNum(s, 1.2, "ewrrewq");

    std::vector<std::string> vs{"123", "abc", "4444"};
    printElems(vs, 0, 2);  // 123 4444

    return 0;
}
