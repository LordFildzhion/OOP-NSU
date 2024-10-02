#include <iostream>
#include <algorithm>
#include <concepts>

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

    T& at(size_t index) {
        if (index >= current_size) {
            std::cerr << "Error: Invalid buffer index" << std::endl;
            exit(EXIT_FAILURE);
        }
        return arr[index];
    }

    const T& at(size_t index) const {
        if (index >= current_size) {
            std::cerr << "Error: Invalid buffer index" << std::endl;
            exit(EXIT_FAILURE);
        }
        return arr[index];
    }

    T operator[](size_t index) { return arr[index]; }

    const T operator[](size_t index) const { return arr[index]; }

    CircularBuffer& operator=(CircularBuffer &new_buffer) {
        if (*this == new_buffer) {
            return *this;
        }

        cap = new_buffer.capacity();
        current_size = new_buffer.size();

        delete[] arr;
        arr = new T[cap];

        for (size_t i = 0; i < cap; i++) {
            arr[i] = new_buffer[i];
        }

        return *this;
    }

    bool operator==(const CircularBuffer &b) {
        if (current_size != b.size()) {
            return false;
        }

        for (size_t i = 0; i < b.size(); i++) {
            if (b[i] != arr[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(CircularBuffer &b) {
        return !(this == b);
    }

    T& front() {
        return arr[first_element];
    }

    const T& front() const {
        return arr[first_element];
    }

    T& back() {
        if (first_element == 0) {
            return arr[current_size - 1];
        } else {
            return arr[first_element - 1];
        }
    }

    const T& back() const {
        if (first_element == 0) {
            return arr[current_size - 1];
        } else {
            return arr[first_element - 1];
        }
    }

    T *linearize() {
        for (size_t i = first_element; i < current_size; i++) {
            std::swap(arr[i], arr[i - first_element]);
        }
        first_element = 0;
        return &arr[first_element];
    }

    bool is_linearized() const {
        return (first_element == 0);
    }

    void rotate(size_t new_begin) {
        for (size_t i = new_begin; i < first_element; i++) {
            std::swap(arr[i], arr[i - new_begin]);
        }
    }

    void swap(CircularBuffer &b) {
        CircularBuffer<T> c = b;
        b = *this;
        *this = c;
    }

    bool full() const { return current_size == cap; }

    bool empty() const { return current_size == 0; }

    size_t size() const { return current_size; }

    size_t capacity() const { return cap; }

    size_t reserve() const { return cap - current_size; }

    void set_capacity(const size_t &new_capacity) {
        T *newarr = new T[new_capacity];
        current_size = std::min(current_size, new_capacity);
        for (size_t i = 0; i < current_size; i++) {
            newarr[i] = arr[i];
        }
        
        delete[] arr;
        arr = newarr;
        cap = new_capacity;
    }

    void resize(size_t new_size, const T& item = T()) {
        (*this).set_capacity(new_size);

        for (size_t i = current_size; i < new_size; i++) {
            arr[i] = item;
        }

        current_size = new_size;
    }

    void push_back(const T& new_element = T()) {
        if (current_size < cap) {
            arr[current_size++] = new_element;
        }
        else {
            arr[first_element++] = new_element;
            if (first_element == current_size) {
                first_element = 0;
            }
        }
    }

    void push_front(const T& new_element = T()) {
        if (first_element == 0)
        {
            first_element = cap;
        }
        arr[--first_element] = new_element;

        if (current_size < cap) {
            current_size++;
        }
    }
    //Work in progress
    void pop_back() {
        if (first_element == 0) {
            if (!(*this).empty()) {
                arr[--current_size] = T();
            }
        } else {
            
        }
    }

    void clear() {
        delete[] arr;
        arr = nullptr;
        cap = 0;
        current_size = 0;
    }

private:
    size_t cap;
    T *arr;
    size_t current_size;
    size_t first_element;
};

using namespace std;

int main()
{
    
}
