#pragma once

#include <iostream>
#include <algorithm>
#include <concepts>
#include <type_traits>

template <typename T>
//requires std::default_initializable<T>
class CircularBuffer{
public:
    CircularBuffer();

    CircularBuffer(const CircularBuffer &a_);

    CircularBuffer(const size_t cap_, T def = T());

    ~CircularBuffer();

    T& at(size_t index);

    const T& at(size_t index) const;

    T operator[](size_t index);

    const T operator[](size_t index) const;

    CircularBuffer& operator=(CircularBuffer &new_buffer);

    bool operator==(const CircularBuffer &b);

    bool operator!=(CircularBuffer &b);

    T& front();

    const T& front() const;

    T& back();

    const T& back() const;

    T *linearize();

    bool is_linearized() const;

    void rotate(size_t new_begin);

    void swap(CircularBuffer &b);

    bool full() const;

    bool empty() const;

    size_t size() const;

    size_t capacity() const;

    size_t reserve() const;

    void set_capacity(const size_t &new_capacity);

    void resize(size_t new_size, const T& item = T());

    void push_back(const T& new_element = T());

    void push_front(const T& new_element = T());
    //Work in progress
    void pop_back();

    void clear();

private:
    size_t cap;
    T *arr;
    size_t current_size;
    size_t first_element;
};
