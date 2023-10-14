//
// Created by Jasmine Tang on 10/11/23.
//

#ifndef STD_VECTOR_VECTOR_H
#define STD_VECTOR_VECTOR_H

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <iterator>

template<class T, class Allocator = std::allocator<T>>
class vector {
private:
    static inline size_t INIT_CAPACITY{8};
    std::size_t _capacity{};
    std::size_t _size{};
    std::unique_ptr<T[]> ptr;
public:
    vector();

    explicit vector(std::size_t N);

    std::size_t size();

    std::size_t capacity();

    constexpr void push_back(const T &value);

    constexpr void push_back(T &&value);

    T &operator[](size_t index);

    T &at(size_t index);

    T &front();

    T &back();

    constexpr T *data() noexcept;

    constexpr const T *data() const noexcept;

    constexpr bool empty();

    void clear();

    // https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
    struct Iterator {
        using iterator_category = std::contiguous_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;  // or also value_type*
        using reference         = T&;  // or also value_type&

    private:
        pointer m_ptr;
    public:
        Iterator() = delete;
        explicit Iterator(pointer ptr) : m_ptr(ptr) {};
        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        // Add
        Iterator operator+(int n) { Iterator tmp = *this; tmp.m_ptr+=n; return tmp; }

        // Minus
        Iterator operator-(int n) { Iterator tmp = *this; tmp.m_ptr-=n; return tmp; }


        // Prefix increment
        Iterator& operator++() { m_ptr++; return *this; }

        // Postfix increment
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        // Prefix decrement
        Iterator& operator--() { m_ptr--; return *this; }

        // Postfix decrement
        Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
    };
    Iterator begin();
    Iterator end();
};

template<class T, class Allocator>
typename vector<T, Allocator>::Iterator vector<T, Allocator>::begin() {
    return Iterator(this->ptr.get());
}

template<class T, class Allocator>
typename vector<T, Allocator>::Iterator vector<T, Allocator>::end() {
    return Iterator(this->ptr.get()+this->capacity());
}

template<class T, class Allocator>
void vector<T, Allocator>::clear() {
    this->ptr.reset(std::make_unique<T>(this->capacity()));
    this->_size = 0;
}

template<class T, class Allocator>
constexpr bool vector<T, Allocator>::empty() {
    return this->size() == 0;
}

template<class T, class Allocator>
constexpr const T *vector<T, Allocator>::data() const noexcept {
    return ptr.get();
}

template<class T, class Allocator>
constexpr T *vector<T, Allocator>::data() noexcept {
    return ptr.get();
}

template<class T, class Allocator>
T &vector<T, Allocator>::back() {
    return this->ptr[_size - 1];
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
vector<T, Allocator>::vector() : vector(0) {}

template<class T, class Allocator>
vector<T, Allocator>::vector(std::size_t N) {
    this->ptr = std::make_unique<T[]>(N);
    this->_capacity = N;

    for(auto i=0; i < N; i++) {
        this->push_back(T{});
    }
}


#endif //STD_VECTOR_VECTOR_H
