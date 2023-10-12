//
// Created by Jasmine Tang on 10/11/23.
//

#ifndef STD_VECTOR_VECTOR_H
#define STD_VECTOR_VECTOR_H

#include <cstddef>
#include <memory>
#include <stdexcept>

template<class T, class Allocator = std::allocator<T>>
class vector {
private:
    static inline size_t INIT_CAPACITY {8};
    std::size_t _capacity {};
    std::size_t _size {};
    std::unique_ptr<T[]> ptr;
public:
    vector();
    explicit vector(std::size_t N);
    std::size_t size();
    std::size_t capacity();
    constexpr void push_back(const T& value);
    constexpr void push_back(T&& value);

    T& operator[](size_t index);
    T& at(size_t index);

    T& front();
    T& back();
};

template<class T, class Allocator>
T &vector<T, Allocator>::back() {
    return this->ptr[_size-1];
}

template<class T, class Allocator>
T &vector<T, Allocator>::front() {
    return this->ptr[0];
}

template<class T, class Allocator>
T &vector<T, Allocator>::at(size_t index) {
    if (index >= this->_size) {
        throw std::out_of_range("Attempted to access vector at invalid index");
    }
    return this->ptr[index];
}

template<class T, class Allocator>
T &vector<T, Allocator>::operator[](size_t index) {
    return this->ptr[index];
}

template<class T, class Allocator>
constexpr void vector<T, Allocator>::push_back(T &&value) {
    ptr[this->_size++] = std::move(value);
}

template<class T, class Allocator>
constexpr void vector<T, Allocator>::push_back(const T &value) {
    ptr[this->_size++] = value;
}



template<class T, class Allocator>
std::size_t vector<T, Allocator>::size() {
    return _size;
}

template<class T, class Allocator>
std::size_t vector<T, Allocator>::capacity() {
    return _capacity;
}

template<class T, class Allocator>
vector<T, Allocator>::vector() : vector(INIT_CAPACITY) {}

template<class T, class Allocator>
vector<T, Allocator>::vector(std::size_t N) {
    this->ptr = std::make_unique<T[]>(N);
    this->_capacity = N;
    this->_size = 0;
}




#endif //STD_VECTOR_VECTOR_H
