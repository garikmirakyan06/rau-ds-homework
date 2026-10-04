#include <iostream>
#include <string>
#include <cassert>

template <typename T, int N>
class FixedArray {
private:
    T data[N];

public:
    void set(int index, T value) {
        data[index] = value;
    }

    T get(int index) {
        return data[index];
    }

    int size() {
        return N;
    }
};

void test_FixedArray() {
    FixedArray<int, 3> a1;
    a1.set(0, 10);
    a1.set(2, 30);
    assert(a1.get(0) == 10);
    assert(a1.get(2) == 30);
    assert(a1.size() == 3);

    FixedArray<double, 2> a2;
    a2.set(1, 2.5);
    assert(a2.get(1) == 2.5);
    assert(a2.size() == 2);

    FixedArray<std::string, 4> a3;
    a3.set(3, "hello");
    assert(a3.get(3) == "hello");
    assert(a3.size() == 4);

    std::cout << "FixedArray passed" << std::endl;
}

int main() {
    test_FixedArray();
    return 0;
}
