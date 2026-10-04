#include <iostream>
#include <vector>
#include <string>
#include <cassert>

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const T& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

template <typename T>
void resizeVector(std::vector<T>& vec, int newSize, T defaultValue) {
    std::cout << "Before: ";
    printVector(vec);

    vec.resize(newSize, defaultValue);

    std::cout << "After: ";
    printVector(vec);
}

void test_resizeVector() {
    std::vector<int> v1 = {1, 2, 3};
    resizeVector(v1, 5, 42);
    assert((v1 == std::vector<int>{1, 2, 3, 42, 42}));

    std::vector<int> v2 = {1, 2, 3};
    resizeVector(v2, 1, 42);
    assert((v2 == std::vector<int>{1}));

    std::cout << "resizeVector passed" << std::endl;
}

int main() {
    test_resizeVector();
    return 0;
}
