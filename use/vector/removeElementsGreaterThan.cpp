#include <vector>
#include <iostream>
#include <cassert>

int removeElementsGreaterThan(std::vector<int>& vec, int x) {
    int count = 0;
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] <= x) {
            break;
        }
        count++;
        vec.pop_back();
    }
    return count;
}

void test_removeElementsGreaterThan() {
    std::vector<int> v1 = {2, 5, 2, 6, 4, 8, 7, 6};
    assert(removeElementsGreaterThan(v1, 5) == 3);
    assert((v1 == std::vector<int>{2, 5, 2, 6, 4}));

    std::vector<int> v2 = {1, 2, 3};
    assert(removeElementsGreaterThan(v2, 5) == 0);

    std::vector<int> v3;
    assert(removeElementsGreaterThan(v3, 5) == 0);

    std::cout << "removeElementsGreaterThan passed" << std::endl;
}

int main() {
    test_removeElementsGreaterThan();
    return 0;
}
