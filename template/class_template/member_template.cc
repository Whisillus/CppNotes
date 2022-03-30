// This file shows
// 1. define a template member function
// 2. specilize the template member function

#include <iostream>
#include <string>

class Str {
private:
    std::string s;

public:
    Str(std::string const &_s) : s(_s) {}

    // 1. define a template member function
    template <typename T = std::string>
    T get() const {
        return s;
    }
};

// 2. specilize the template member function
template<>
bool Str::get<bool>() const {
    return s == "on";
}

int main(int argc, char *argv[])
{
    Str s1{"on"};
    std::cout << s1.get() << std::endl; // output: on
    std::cout << s1.get<bool>() << std::endl; //output: 1
    return 0;
}
