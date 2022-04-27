// this file shows:
// 1.how to define a share_ptr
// 2.how to use share_ptr
// 3.use use_count()

#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    // define
    // way 1
    std::shared_ptr<std::string> pname_1(new std::string("Chen"));
    // constructor is explicit
    // dont use the assignment
    // std::shared_ptr<std::string> pname = new std::string("Chen"); // error

    // way 2
    std::shared_ptr<std::string> pname_2 =
        std::make_shared<std::string>("Wang");

    //  way 3
    std::shared_ptr<std::string> pname_3;
    pname_3.reset(new std::string("Li"));
    // pname_3 = new std::string("Li"); // error
    // pname_3 = nullptr; // OK

    // use like ordinary ptr
    (*pname_3)[0] = 'Y';
    pname_2->replace(0, 1, "C");

    // use with container
    std::vector<std::shared_ptr<std::string>> vname;
    vname.push_back(pname_1);
    vname.push_back(pname_3);
    vname.push_back(pname_2);
    vname.push_back(pname_3);
    vname.push_back(pname_2);

    for (auto p : vname) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;

    *pname_2 = "Ali";
    for (auto p : vname) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;

    // use use.count()
    std::cout<<"count : "<<pname_2.use_count()<<std::endl;

    return 0;
}
