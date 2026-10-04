#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(std::vector<int>& vec) {
    std::cout << "Before: " << vec.size() << " " << vec.capacity() << "\n";

    vec.reserve(vec.size() + 500);
    for (int i = 1; i <= 500; i++) {
        vec.push_back(i);
    }

    std::cout << "After: " << vec.size() << " " << vec.capacity() << "\n";
}

void test_manageCapacity() {
    std::vector<int> v1;
    manageCapacity(v1);
    assert(v1.size() == 500);
    assert(v1.capacity() >= 500);
    assert(v1[0] == 1 && v1[499] == 500);

    std::vector<int> v2 = {7, 8, 9};
    manageCapacity(v2);
    assert(v2.size() == 503);
    assert(v2[0] == 7 && v2[3] == 1);

    std::cout << "manageCapacity passed" << std::endl;
}

int main() {
    test_manageCapacity();
    return 0;
}
