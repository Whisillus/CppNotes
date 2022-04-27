// this file shows:
// 1.how to define a wear_ptr
// 2.how to use wear_ptr
//

#include <iostream>
#include <memory>

class Point {
public:
    int id;
    std::shared_ptr<Point> next;
    // std::shared_ptr<Point> last;
    // break cyclic reference
    std::weak_ptr<Point> last;

    Point(int const n, std::shared_ptr<Point> ne = nullptr,
          std::shared_ptr<Point> la = nullptr)
        : id(n), next(ne), last(la) {}
    ~Point() { std::cout << " delete: " << id << std::endl; }
};

auto initGraph() {
    auto pp1 = std::make_shared<Point>(1);
    auto pp2 = std::make_shared<Point>(2);
    pp1->next = pp2;
    pp2->last = pp1;
    return pp1;
}

int main(int argc, char *argv[]) {
    auto graph = initGraph();
    graph = nullptr;
    std::cout << "Done" << std::endl;

    // use lock() to access weak_ptr
    graph = initGraph();
    std::cout << "Point 1 count: " << graph.use_count() << std::endl;
    std::cout << "Point id: " << graph->next->last.lock()->id << std::endl;
    auto tmp = graph->next->last.lock();
    std::cout << "Point 1 count: " << graph.use_count() << std::endl;
    graph = nullptr;

    auto pi = std::make_shared<int>(132);
    std::weak_ptr<int> wpi = pi;
    pi.reset();
    std::cout << "count after reset: " << wpi.use_count()
              << std::endl;  // use_count() is not efficient
    std::cout << "if_expired after reset: " << std::boolalpha << wpi.expired()
              << std::endl;

    return 0;
}
