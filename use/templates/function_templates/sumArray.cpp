#include <iostream>
#include <string>
#include <cassert>

template <typename T>
T sumArray(T* arr, int size) {
    T sum = T();
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void test_sumArray() {
    int arr1[3] = {3,4,2};
    int sum1 = sumArray<int>(arr1, 3);
    assert(sum1 == 9);

    double arr2[2] = {3.2,4};
    double sum2 = sumArray<double>(arr2, 2);
    assert(sum2 == 7.2);

    std::string arr3[3] = {"ab", "cd", "ef"};
    std::string sum3 = sumArray<std::string>(arr3, 3);
    assert(sum3 == "abcdef");

    std::cout << "sumArray passed" << std::endl;
}

int main() {
    test_sumArray();
    return 0;
}
