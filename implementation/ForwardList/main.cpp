#include "ForwardList.h"
#include <cassert>
#include <iostream>

// Реализуйте методы ForwardList<T>:
//   1. ForwardList()                   - конструктор
//   2. ~ForwardList()                  - деструктор
//   3. ForwardList(const &)            - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push_front(const T&)            - добавить в начало
//   6. pop_front()                     - удалить с начала
//   7. front()                         - первый элемент
//   8. insert_after(Node*, const T&)   - вставить после узла
//   9. erase_after(Node*)              - удалить после узла
//  10. clear()                         - очистить
//  11. reverse()                       - развернуть
//  12. size()                          - размер
//  13. empty()                         - пусто ли
//  14. begin()                         - начало списка

void test_constructor() {
    ForwardList<int> list;
    list.push_front(1);
    assert(list.size() == 1);

    ForwardList<int> empty;
    assert(empty.size() == 0);
    assert(empty.begin() == nullptr);

    std::cout << "test_constructor passed" << std::endl;
}

void test_copy_constructor() {
    ForwardList<int> a;
    a.push_front(2);
    a.push_front(1);
    ForwardList<int> b(a);
    assert(b.size() == 2);
    assert(b.begin()->data == 1);
    assert(b.begin()->next->data == 2);

    ForwardList<int> empty;
    ForwardList<int> c(empty);
    assert(c.empty());

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment() {
    ForwardList<int> a;
    a.push_front(2);
    a.push_front(1);
    ForwardList<int> b;
    b = a;
    assert(b.size() == 2);
    assert(b.begin()->data == 1);
    assert(b.begin()->next->data == 2);

    b = b;
    assert(b.size() == 2);
    assert(b.front() == 1);

    std::cout << "test_assignment passed" << std::endl;
}

void test_push_front() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    assert(list.size() == 2);
    assert(list.begin()->data == 2);
    assert(list.begin()->next->data == 1);

    ForwardList<int> empty;
    empty.push_front(1);
    assert(empty.size() == 1);
    assert(empty.begin()->next == nullptr);

    std::cout << "test_push_front passed" << std::endl;
}

void test_pop_front() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 1);

    ForwardList<int> empty;
    empty.pop_front();
    assert(empty.empty());

    std::cout << "test_pop_front passed" << std::endl;
}

void test_front() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    assert(list.front() == 2);

    ForwardList<int> one;
    one.push_front(1);
    one.front() = 5;
    assert(one.front() == 5);

    std::cout << "test_front passed" << std::endl;
}

void test_insert_after() {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(1);
    list.insert_after(list.begin(), 2);
    assert(list.size() == 3);
    assert(list.begin()->next->data == 2);
    assert(list.begin()->next->next->data == 3);

    ForwardList<int> empty;
    empty.insert_after(empty.begin(), 1);
    assert(empty.empty());

    std::cout << "test_insert_after passed" << std::endl;
}

void test_erase_after() {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.erase_after(list.begin());
    assert(list.size() == 2);
    assert(list.begin()->next->data == 3);

    ForwardList<int> one;
    one.push_front(1);
    one.erase_after(one.begin());
    assert(one.size() == 1);

    std::cout << "test_erase_after passed" << std::endl;
}

void test_clear() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.clear();
    assert(list.empty());
    assert(list.begin() == nullptr);

    ForwardList<int> empty;
    empty.clear();
    assert(empty.empty());

    std::cout << "test_clear passed" << std::endl;
}

void test_reverse() {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.reverse();
    assert(list.begin()->data == 3);
    assert(list.begin()->next->data == 2);
    assert(list.begin()->next->next->data == 1);

    ForwardList<int> empty;
    empty.reverse();
    assert(empty.empty());

    std::cout << "test_reverse passed" << std::endl;
}

void test_size() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);

    ForwardList<int> empty;
    empty.pop_front();
    assert(empty.size() == 0);

    std::cout << "test_size passed" << std::endl;
}

void test_empty() {
    ForwardList<int> list;
    list.push_front(1);
    assert(!list.empty());

    ForwardList<int> one;
    one.push_front(1);
    one.pop_front();
    assert(one.empty());

    std::cout << "test_empty passed" << std::endl;
}

void test_begin() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    assert(list.begin()->data == 2);
    assert(list.begin()->next->data == 1);

    ForwardList<int> empty;
    assert(empty.begin() == nullptr);

    std::cout << "test_begin passed" << std::endl;
}

int main() {
    std::cout << "Running ForwardList tests" << std::endl;
    test_constructor();
    test_copy_constructor();
    test_assignment();
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_size();
    test_empty();
    test_begin();
    std::cout << "All tests passed" << std::endl;
    return 0;
}

