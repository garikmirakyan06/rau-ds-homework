#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> mergeSortedVectors(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }
    return result;
}

void test_mergeSortedVectors() {
    assert((mergeSortedVectors({1, 3, 5, 7}, {2, 4, 6, 8, 9}) == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));

    assert((mergeSortedVectors({}, {1, 2}) == std::vector<int>{1, 2}));

    std::cout << "mergeSortedVectors passed" << std::endl;
}

int main() {
    test_mergeSortedVectors();
    return 0;
}
