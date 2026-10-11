#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;

    void _resize_capacity(size_t new_capacity);

public:
    /// 1. Конструктор по умолчанию
    Vector();

    /// 2. Конструктор с начальным размером
    Vector(size_t initial_size);

    /// 3. Деструктор
    ~Vector();

    /// 4. Конструктор копирования
    Vector(const Vector& other);

    /// 5. Оператор присваивания
    Vector& operator=(const Vector& other);

    /// 6. push_back(const T& value) - добавить в конец
    void push_back(const T& value);

    /// 7. pop_back() - удалить последний элемент
    void pop_back();

    /// 8. operator[](size_t index) - доступ по индексу
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    /// 9. at(size_t index) - доступ с проверкой границ
    T& at(size_t index);
    const T& at(size_t index) const;

    /// 10. front() - первый элемент
    T& front();
    const T& front() const;

    /// 11. back() - последний элемент
    T& back();
    const T& back() const;

    /// 12. size() - количество элементов
    size_t size() const;

    /// 13. capacity() - выделенная память
    size_t capacity() const;

    /// 14. empty() - пуст ли вектор
    bool empty() const;

    /// 15. reserve(size_t new_capacity) - выделить память
    void reserve(size_t new_capacity);

    /// 16. clear() - очистить вектор
    void clear();

    /// 17. begin() - начало вектора
    T* begin();
    const T* begin() const;

    /// 18. end() - конец вектора
    T* end();
    const T* end() const;

    // 19. swap()
    void swap(Vector& other);

    // 20. insert()
    void insert(const T& value, size_t index);

    // 21. erase()
    void erase(size_t index);

    // 22. resize()
    void resize(size_t new_size);
};


template <typename T>
void Vector<T>::_resize_capacity(size_t new_capacity) {
    T* newData = new T[new_capacity];

    for (size_t i = 0; i < _size; i++) {
        newData[i] = _data[i];
    }

    delete[] _data;
    _data = newData;
    _capacity = new_capacity;
}

/// 1. Конструктор по умолчанию
template <typename T>
Vector<T>::Vector() : _data(nullptr), _size(0), _capacity(0) {}

/// 2. Конструктор с начальным размером
template <typename T>
Vector<T>::Vector(size_t initial_size) : _data(new T[initial_size]), _size(initial_size), _capacity(initial_size) {}

/// 3. Деструктор
template <typename T>
Vector<T>::~Vector() {
    delete[] _data;
    _size = 0;
    _capacity = 0;
}

/// 4. Конструктор копирования
template <typename T>
Vector<T>::Vector(const Vector& other) : _data(new T[other._capacity]), _size(other._size), _capacity(other._capacity) {
    for (size_t i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

/// 5. Оператор присваивания
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    Vector newVector(other); // "copy and swap" idiom
    swap(newVector);
    return *this;
}

/// 6. push_back(const T& value) - добавить в конец
template <typename T>
void Vector<T>::push_back(const T& value) {
    if (_size == _capacity) {
        T copy = value; // for case if vector is full and we write vec.push_back(v[0])
        _resize_capacity((_capacity == 0) ? 1 : 2 * _capacity);
        _data[_size++] = copy;
    }
    else {
        _data[_size++] = value;
    }
}

/// 7. pop_back() - удалить последний элемент
template <typename T>
void Vector<T>::pop_back() {
    if (_size == 0) {
        throw std::out_of_range("pop_back on empty Vector");
    }
    _size--;
}

/// 8. operator[](size_t index) - доступ по индексу
template <typename T>
T& Vector<T>::operator[](size_t index) {
    return _data[index];
}
template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return _data[index];
}

/// 9. at(size_t index) - доступ с проверкой границ
template <typename T>
T& Vector<T>::at(size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Vector::at");
    }
    return _data[index];
}
template <typename T>
const T& Vector<T>::at(size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Vector::at");
    }
    return _data[index];
}

/// 10. front() - первый элемент
template <typename T>
T& Vector<T>::front() {
    if (_size == 0) {
        throw std::out_of_range("Vector::front");
    }
    return _data[0];
}
template <typename T>
const T& Vector<T>::front() const {
    if (_size == 0) {
        throw std::out_of_range("Vector::front");
    }
    return _data[0];
}

/// 11. back() - последний элемент
template <typename T>
T& Vector<T>::back() {
    if (_size == 0) {
        throw std::out_of_range("Vector::back");
    }
    return _data[_size-1];
}
template <typename T>
const T& Vector<T>::back() const {
    if (_size == 0) {
        throw std::out_of_range("Vector::back");
    }
    return _data[_size - 1];
}

/// 12. size() - количество элементов
template <typename T>
size_t Vector<T>::size() const {
    return _size;
}

/// 13. capacity() - выделенная память
template <typename T>
size_t Vector<T>::capacity() const {
    return _capacity;
}

/// 14. empty() - пуст ли вектор
template <typename T>
bool Vector<T>::empty() const {
    return _size == 0;
}

/// 15. reserve(size_t new_capacity) - выделить память
template <typename T>
void Vector<T>::reserve(size_t new_capacity) {
    if (_capacity < new_capacity) {
        _resize_capacity(new_capacity);
    }
}

/// 16. clear() - очистить вектор
template <typename T>
void Vector<T>::clear() {
    _size = 0;
}

/// 17. begin() - начало вектора
template <typename T>
T* Vector<T>::begin() {
    return _data;
}
template <typename T>
const T* Vector<T>::begin() const {
    return _data;
}

/// 18. end() - конец вектора
template <typename T>
T* Vector<T>::end() {
    return (_data + _size);
}
template <typename T>
const T* Vector<T>::end() const {
    return (_data + _size);
}

// 19. swap()
template <typename T>
void Vector<T>::swap(Vector& other) {
    std::swap(_data, other._data);
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
}

// 20. insert()
template <typename T>
void Vector<T>::insert(const T& value, size_t index) {
    if (index > _size) {
        throw std::out_of_range("Vector::insert");
    }
    T copy = value;
    if (_size == _capacity) {
        _resize_capacity((_capacity == 0) ? 1 : 2 * _capacity);
    }
    for (size_t i = _size; i > index; i--) {
        _data[i] = _data[i - 1];
    }
    _data[index] = copy;
    ++_size;
}

// 21. erase()
template <typename T>
void Vector<T>::erase(size_t index) {
    if (index >= _size) {
        throw std::out_of_range("erase: index out of range");
    }
    for (size_t i = index; i + 1 < _size; ++i) {
        _data[i] = _data[i + 1];
    }
    --_size;
}

// 22. resize()
template <typename T>
void Vector<T>::resize(size_t new_size) {
    if (new_size > _capacity) {
        _resize_capacity(new_size);
    }
    for (size_t i = _size; i < new_size; ++i) {
        _data[i] = T();
    }
    _size = new_size;
}



#endif // VECTOR_H
