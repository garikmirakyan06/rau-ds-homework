#include <iostream>
#include <vector>

void workWithEmptyVector() {
    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
        std::cout << vec.size() << " " << vec.capacity() << "\n";
    }
    std::cout << "\n";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void test_workWithEmptyVector() {
    workWithEmptyVector();

    std::cout << "workWithEmptyVector passed\n"; 
}

int main() {
    test_workWithEmptyVector();
    return 0;
}
