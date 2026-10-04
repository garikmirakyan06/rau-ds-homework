#include <iostream>
#include <string>

template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}

void test_printElement() {
    printElement<int>(12);
    printElement<double>(13.12);
    printElement<std::string>("asd");

    std::cout << "printElement passed" << std::endl;
}

int main() {
    test_printElement();
    return 0;
}
