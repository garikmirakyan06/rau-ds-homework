#include <iostream>
#include <string>
#include <cassert>

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void test_mySwap() {
    int a = 1, b = 2;
    mySwap<int>(a, b);
    assert(a == 2 && b == 1);

    double c = 1.5, d = 2.5;
    mySwap<double>(c, d);
    assert(c == 2.5 && d == 1.5);

    std::string s1 = "hello", s2 = "world";
    mySwap<std::string>(s1, s2);
    assert(s1 == "world" && s2 == "hello");

    std::cout << "mySwap passed" << std::endl;
}

int main() {
    test_mySwap();
    return 0;
}
