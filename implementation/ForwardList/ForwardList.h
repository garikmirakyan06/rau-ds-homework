#ifndef FORWARDLIST_H
#define FORWARDLIST_H


template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* _head;
    int _size;

public:
    /// 1. Конструктор по умолчанию
    ForwardList();

    /// 2. Деструктор
    ~ForwardList();

    /// 3. Конструктор копирования
    ForwardList(const ForwardList& other);

    /// 4. Оператор присваивания
    ForwardList& operator=(const ForwardList& other);

    /// 5. push_front(const T& x) - добавить в начало
    void push_front(const T& x);

    /// 6. pop_front() - удалить с начала
    void pop_front();

    /// 7. front() - первый элемент
    T& front();
    const T& front() const;

    /// 8. insert_after(Node* node, const T& value) - вставить после узла
    void insert_after(Node* node, const T& value);

    /// 9. erase_after(Node* node) - удалить после узла
    void erase_after(Node* node);

    /// 10. clear() - очистить
    void clear();

    /// 11. reverse() - развернуть
    void reverse();

    /// 12. size() - количество элементов
    int size() const;

    /// 13. empty() - пуст ли
    bool empty() const;

    /// 14. begin() - начало списка
    Node* begin();
    Node* begin() const;
};

/// 1. Конструктор по умолчанию
template <typename T>
ForwardList<T>::ForwardList() : _head(nullptr), _size(0) {}

/// 2. Деструктор
template <typename T>
ForwardList<T>::~ForwardList() {
    while (_head != nullptr) {
        Node* tmp = _head;
        _head = _head->next;
        delete tmp;
    }
}

/// 3. Конструктор копирования
template <typename T>
ForwardList<T>::ForwardList(const ForwardList& other) : _head(nullptr), _size(0) {
    Node* tail = nullptr;
    for (Node* cur = other._head; cur != nullptr; cur = cur->next) {
        Node* node = new Node(cur->data);
        if (tail == nullptr) {
            _head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        ++_size;
    }
}

/// 4. Оператор присваивания
template <typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& other) {
    if (this != &other) {
        ForwardList tmp(other);

        Node* old_head = _head;
        _head = tmp._head;
        tmp._head = old_head;

        int old_size = _size;
        _size = tmp._size;
        tmp._size = old_size;
    }
    return *this;
}

/// 5. push_front(const T& x)
template <typename T>
void ForwardList<T>::push_front(const T& x) {
    Node* node = new Node(x);
    node->next = _head;
    _head = node;
    ++_size;
}

/// 6. pop_front()
template <typename T>
void ForwardList<T>::pop_front() {
    if (_head == nullptr) {
        return;
    }
    Node* tmp = _head;
    _head = _head->next;
    delete tmp;
    --_size;
}

/// 7. front() - первый элемент
template <typename T>
T& ForwardList<T>::front() {
    return _head->data;
}

/// 7. front() const - первый элемент
template <typename T>
const T& ForwardList<T>::front() const {
    return _head->data;
}

/// 8. insert_after(Node* node, const T& value) - вставить после узла
template <typename T>
void ForwardList<T>::insert_after(Node* node, const T& value) {
    if (node == nullptr) {
        return;
    }
    Node* new_node = new Node(value);
    new_node->next = node->next;
    node->next = new_node;
    ++_size;
}

/// 9. erase_after(Node* node) - удалить после узла
template <typename T>
void ForwardList<T>::erase_after(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        return;
    }
    Node* tmp = node->next;
    node->next = tmp->next;
    delete tmp;
    --_size;
}

/// 10. clear() - очистить
template <typename T>
void ForwardList<T>::clear() {
    while (_head != nullptr) {
        pop_front();
    }
}

/// 11. reverse() - развернуть
template <typename T>
void ForwardList<T>::reverse() {
    Node* prev = nullptr;
    Node* cur = _head;
    while (cur != nullptr) {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    _head = prev;
}

/// 12. size() - количество элементов
template <typename T>
int ForwardList<T>::size() const {
    return _size;
}

/// 13. empty() - пуст ли
template <typename T>
bool ForwardList<T>::empty() const {
    return _head == nullptr;
}

/// 14. begin() - начало списка
template <typename T>
typename ForwardList<T>::Node* ForwardList<T>::begin() {
    return _head;
}

/// 14. begin() const - начало списка
template <typename T>
typename ForwardList<T>::Node* ForwardList<T>::begin() const {
    return _head;
}




#endif // FORWARDLIST_H
