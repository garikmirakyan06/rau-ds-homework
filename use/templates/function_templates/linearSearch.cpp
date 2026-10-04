#include <iostream>
#include <string>
#include <vector>
#include <cassert>

template <typename T>
int linearSearch(const std::vector<T>& v, const T& target) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            return i;
        }
    }
    return -1;
}

void test_linearSearch() {
    std::vector<int> v1 = {5, 3, 7, 3};
    assert(linearSearch<int>(v1, 3) == 1);
    assert(linearSearch<int>(v1, 9) == -1);

    std::vector<double> v2 = {1.5, 2.5, 3.5};
    assert(linearSearch<double>(v2, 3.5) == 2);
    assert(linearSearch<double>(v2, 4.5) == -1);

    std::vector<std::string> v3 = {"a", "b", "c"};
    assert(linearSearch<std::string>(v3, "b") == 1);
    assert(linearSearch<std::string>(v3, "z") == -1);

    std::cout << "linearSearch passed" << std::endl;
}

int main() {
    test_linearSearch();
    return 0;
}
