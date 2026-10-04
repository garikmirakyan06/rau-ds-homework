#include <iostream>
#include <vector>

std::vector<int> createVectorFromInput() {
    std::vector<int> vec;
    int x;
    std::cin >> x;
    while (x != 0) {
        vec.push_back(x);
        std::cin >> x;
    }
    return vec;
}

void test_createVectorFromInput() {
    std::vector<int> vec = createVectorFromInput();
    std::cout << vec.size() << "\n";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    test_createVectorFromInput();
    return 0;
}
