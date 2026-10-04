#include <iostream>
#include <vector>
#include <cassert>

int findSubsequence(const std::vector<int>& vec, const std::vector<int>& sub) {
    if (sub.size() > vec.size())
        return -1;

    for (int i = 0; i <= vec.size() - sub.size(); ++i) {
        bool found = true;
        for (int j = 0; j < sub.size(); j++) {
            if (vec[i + j] != sub[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return -1;
}

void test_findSubsequence() {
    assert(findSubsequence({1, 2, 3, 4, 5, 6}, {3, 4, 5}) == 2);

    assert(findSubsequence({1, 2, 3}, {2, 4}) == -1);

    assert(findSubsequence({1}, {1, 2}) == -1);

    std::cout << "findSubsequence passed" << std::endl;
}

int main() {
    test_findSubsequence();
    return 0;
}
