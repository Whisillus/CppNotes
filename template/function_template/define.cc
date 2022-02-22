
#include <iostream>
#include <string>
// Define a template
template <typename T>
T max(T v1, T v2) {
    return v1 < v2 ? v2 : v1;
}

template <typename T>
T maxConst(T const &cv1, T const &cv2) {
    return cv1 < cv2 ? cv2 : cv1;
}

int main() {
    // Use a template
    // The process of repalcing template paras. by concrete types is called
    // instantiation It results in an instance of a template
    //
    // TODO
    // Names will be checked twice => two-phase loopup
    // This leads to a problem
    // When a funciton template is used in a way that triggers its
    // instatiation, a compiler will need to see that template's definition
    //
    int i = 421;
    std::string s1 = "hello!";
    std::string s2 = "leiho!";
    std::cout << "Example \"Use templates\"" << std::endl;
    // Use globla scope :: here
    std::cout << "max(i, 22): " << ::max(i, 22) << std::endl;
    std::cout << "max(s1, s2): " << ::max(s1, s2) << std::endl;
    std::cout << "max(1.23,32.1): " << ::max(1.23, 32.1) << std::endl;

    return 0;
}
