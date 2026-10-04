#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
std::vector<T> filterVector(const std::vector<T>& vec, bool (*predicate)(T)) {
    std::vector<T> result;
    for (const T& val : vec) {
        if (predicate(val)) {
            result.push_back(val);
        }
    }
    return result;
}

bool isEven(int x) { return x % 2 == 0; }

bool isPositive(double x) { return x > 0; }

void test_filterVector() {
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
    assert((filterVector(v1, isEven) == std::vector<int>{2, 4, 6}));

    std::vector<int> v2 = {1, 3, 5};
    assert(filterVector(v2, isEven).empty());

    std::cout << "filterVector passed" << std::endl;
}

int main() {
    test_filterVector();
    return 0;
}
