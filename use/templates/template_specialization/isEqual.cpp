#include <iostream>
#include <cassert>
#include <cstring>

template <typename T>
bool isEqual(T element1, T element2) {
    return element1 == element2;
}

template <>
bool isEqual<const char*>(const char* element1, const char* element2) {
    return strcmp(element1, element2) == 0;
}

void test_isEqual() {
    assert(isEqual<int>(5, 5));
    assert(!isEqual<int>(5, 6));

    assert(isEqual<double>(2.5, 2.5));
    assert(!isEqual<double>(2.5, 3.5));

    assert(isEqual<std::string>("abc", "abc"));
    assert(!isEqual<std::string>("abc", "abd"));

    char s1[] = "hello";
    char s2[] = "hello";
    char s3[] = "world";
    assert(isEqual<const char*>(s1, s2));
    assert(!isEqual<const char*>(s1, s3));

    std::cout << "isEqual passed" << std::endl;
}

int main() {
    test_isEqual();
    return 0;
}
