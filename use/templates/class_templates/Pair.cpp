#include <iostream>
#include <string>
#include <cassert>

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 a, T2 b) {
        first = a;
        second = b;
    }

    void print() {
        std::cout << first << " " << second << std::endl;
    }
};

void test_Pair() {
    Pair<int, double> p1(1, 2.5);
    assert(p1.first == 1 && p1.second == 2.5);
    p1.print();

    Pair<std::string, int> p2("age", 20);
    assert(p2.first == "age" && p2.second == 20);
    p2.print();

    Pair<char, std::string> p3('a', "hello");
    assert(p3.first == 'a' && p3.second == "hello");
    p3.print();

    std::cout << "Pair passed" << std::endl;
}

int main() {
    test_Pair();
    return 0;
}
