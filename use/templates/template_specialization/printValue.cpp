#include <iostream>
#include <cassert>

template <typename T>
void printValue(T value) {
    std::cout << value << std::endl;
}

template <>
void printValue<bool>(bool value) {
    if (value) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

template <>
void printValue<char*>(char* value) {
    std::cout << "\"" << value << "\"" << std::endl;
}

void test_printValue() {
    printValue<int>(42);
    printValue<double>(3.14);
    printValue<std::string>("abc");

    printValue<bool>(true);
    printValue<bool>(false);

    char str[] = "hello";
    printValue<char*>(str);
}

int main() {
    test_printValue();
    return 0;
}
