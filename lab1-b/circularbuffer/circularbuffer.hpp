

#include <iostream>
#include <algorithm>
#include <concepts>
#include <type_traits>

#pragma once
template <typename T>
class CircularBuffer{
public:
    CircularBuffer(): cap {0}, arr{{}}, current_size{0}, first_element{0}
    { }
    
    CircularBuffer(const CircularBuffer &a_): cap{a_.capacity()}, arr{new T[cap]}, current_size{a_.size()}, first_element{0} {
        for (size_t it = 0; it < current_size; it++) {
            arr[it] = a_[it];
        }
    }
    
    CircularBuffer(const size_t cap_, T def = T()):  cap{cap_}, arr{new T[cap_] }, current_size{cap_}, first_element{0} {
        for (size_t it = 0; it < cap; it++) {
            arr[it] = def;
        }
    }
    
    ~CircularBuffer() { delete[] arr; }

    T& at(size_t index);

    const T& at(size_t index) const;

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

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

    void resize(size_t new_size, const T& item);

    void push_back(const T& new_element);

    void push_front(const T& new_element);
    //Work in progress
    void pop_back();

    void clear();

private:
    size_t cap;
    T *arr;
    size_t current_size;
    size_t first_element;
};
