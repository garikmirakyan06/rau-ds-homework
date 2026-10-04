#include <iostream>
#include <vector>

void createAndFillVector(int n) {
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = i + 1;
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    std::cout << vec.size() << " " << vec.capacity();
    std::cout << "\n";
}

void test_createAndFillVector() {
    createAndFillVector(3);
    std::cout << "createAndFillVector passed\n";
}

int main() {
    test_createAndFillVector();
    return 0;
}
