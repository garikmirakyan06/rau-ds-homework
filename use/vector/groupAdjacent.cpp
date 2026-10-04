#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& vec) {
    std::vector<std::vector<int>> groups;
    for (int i = 0; i < vec.size(); i++) {
        if (i == 0 || vec[i] != vec[i - 1]) {
            groups.push_back({});
        }
        groups.back().push_back(vec[i]);
    }
    return groups;
}

void test_groupAdjacent() {
    std::vector<std::vector<int>> expected = {{1, 1}, {2, 2, 2}, {3}, {1, 1}};
    assert(groupAdjacent({1, 1, 2, 2, 2, 3, 1, 1}) == expected);

    assert(groupAdjacent({}).empty());

    assert(groupAdjacent({5}) == std::vector<std::vector<int>>{{5}});

    std::cout << "groupAdjacent passed" << std::endl;
}

int main() {
    test_groupAdjacent();
    return 0;
}
