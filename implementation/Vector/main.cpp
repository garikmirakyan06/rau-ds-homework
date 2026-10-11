#include "Vector.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Vector<T>:
//
//   1. Vector()                        - конструктор по умолчанию
//   2. ~Vector()                       - деструктор
//   3. Vector(const Vector& other)     - конструктор копирования
//   4. operator=(const Vector& other)  - оператор присваивания
//   5. push_back(const T& x)           - добавить в конец
//   6. pop_back()                      - удалить с конца
//   7. operator[](int index)           - доступ по индексу
//   8. back()                          - последний элемент
//   9. insert(int pos, const T& val)   - вставить
//  10. erase(int pos)                  - удалить
//  11. swap(Vector& other)             - обменять содержимое
//  12. clear()                         - очистить
//  13. resize(int new_size)            - изменить размер
//  14. front()                         - первый элемент
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }
//
// Каждый тест должен проверять:
//   - Нормальный случай
//   - Граничные случаи


void test_push_back() {
    Vector<int> v;

    // Нормальный случай
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);

    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v.back() == 15);

    std::cout << "test_push_back passed" << std::endl;
}

void test_pop_back() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);

    // Нормальный случай
    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 1);

    // Граничные случаи
    v.pop_back();
    assert(v.empty());

    bool caught = false;
    try { v.pop_back(); } catch (const std::out_of_range&) { caught = true; }
    assert(caught);

    std::cout << "test_pop_back passed" << std::endl;
}

void test_operator_bracket() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    // Нормальный случай
    assert(v[0] == 10);
    assert(v[1] == 20);

    v[1] = 25;
    assert(v[1] == 25);

    std::cout << "test_operator_bracket passed" << std::endl;
}

void test_back() {
    Vector<int> v;

    // Нормальный случай
    v.push_back(1);
    v.push_back(2);
    assert(v.back() == 2);

    // Граничные случаи
    Vector<int> empty;
    bool caught = false;
    try { empty.back(); } catch (const std::out_of_range&) { caught = true; }
    assert(caught);

    std::cout << "test_back passed" << std::endl;
}

void test_front() {
    Vector<int> v;

    // Нормальный случай
    v.push_back(1);
    v.push_back(2);
    assert(v.front() == 1);

    // Граничные случаи
    Vector<int> empty;
    bool caught = false;
    try { empty.front(); } catch (const std::out_of_range&) { caught = true; }
    assert(caught);

    std::cout << "test_front passed" << std::endl;
}

void test_insert() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(3);

    // Нормальный случай
    v.insert(2, 1);
    assert(v.size() == 3);
    assert(v[1] == 2);

    // Граничные случаи
    v.insert(0, 0);
    assert(v[0] == 0);

    v.insert(4, v.size());
    assert(v.back() == 4);

    std::cout << "test_insert passed" << std::endl;
}

void test_erase() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // Нормальный случай
    v.erase(1);
    assert(v.size() == 2);
    assert(v[1] == 3);

    // Граничные случаи
    v.erase(0);
    v.erase(0);
    assert(v.empty());

    std::cout << "test_erase passed" << std::endl;
}

void test_swap() {
    Vector<int> a;
    a.push_back(1);
    Vector<int> b;
    b.push_back(2);
    b.push_back(3);

    // Нормальный случай
    a.swap(b);
    assert(a.size() == 2);
    assert(a[0] == 2);
    assert(b.size() == 1);
    assert(b[0] == 1);

    // Граничные случаи
    Vector<int> empty;
    a.swap(empty);
    assert(a.empty());
    assert(empty.size() == 2);

    std::cout << "test_swap passed" << std::endl;
}

void test_clear() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);

    // Нормальный случай
    v.clear();
    assert(v.empty());

    // Граничные случаи
    v.clear();
    assert(v.empty());

    std::cout << "test_clear passed" << std::endl;
}

void test_resize() {
    Vector<int> v;
    v.push_back(1);

    // Нормальный случай
    v.resize(3);
    assert(v.size() == 3);
    assert(v[0] == 1);
    assert(v[2] == 0);

    // Граничные случаи
    v.resize(0);
    assert(v.empty());

    std::cout << "test_resize passed" << std::endl;
}

void test_copy_constructor() {
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);

    // Нормальный случай
    Vector<int> b(a);
    assert(b.size() == 2);
    assert(b[0] == 1);
    assert(b[1] == 2);

    b[0] = 100;
    assert(a[0] == 1);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    Vector<int> b;

    // Нормальный случай
    b = a;
    assert(b.size() == 2);
    assert(b[0] == 1);

    b[0] = 100;
    assert(a[0] == 1);

    // Граничные случаи
    a = a;
    assert(a.size() == 2);
    assert(a[0] == 1);

    std::cout << "test_assignment_operator passed" << std::endl;
}


int main() {
    std::cout << "Running Vector tests" << std::endl;

    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_back();
    test_front();
    test_insert();
    test_erase();
    test_swap();
    test_clear();
    test_resize();
    test_copy_constructor();
    test_assignment_operator();

    std::cout << "All tests passed" << std::endl;
    return 0;
}