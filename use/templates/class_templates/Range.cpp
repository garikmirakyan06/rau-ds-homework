#include <iostream>
#include <cassert>

template <typename T>
class Range {
private:
    T start;
    T end;

public:
    Range(T s, T e) {
        start = s;
        end = e;
    }

    bool contains(const T& value) {
        return (value >= start && value <= end);
    }

    T length() {
        return (end - start);
    }

    void print() {
        std::cout << "[" << start << ", " << end << "]" << std::endl;
    }
};

void test_Range() {
    // int
    Range<int> r1(3, 10);
    assert(r1.contains(5));
    assert(r1.contains(3) && r1.contains(10));
    assert(!r1.contains(11));
    assert(r1.length() == 7);
    r1.print();

    // double
    Range<double> r2(1.5, 4.0);
    assert(r2.contains(2.5));
    assert(!r2.contains(4.5));
    assert(r2.length() == 2.5);
    r2.print();

    // char
    Range<char> r3('a', 'f');
    assert(r3.contains('c'));
    assert(!r3.contains('z'));
    assert(r3.length() == 5);
    r3.print();

    std::cout << "Range passed" << std::endl;
}

int main() {
    test_Range();
    return 0;
}
