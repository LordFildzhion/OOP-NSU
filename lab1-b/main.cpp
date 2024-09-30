#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class CircularBuffer{
public:
    CircularBuffer(): cap {0}, arr{{}}, current_size{0}
    { }

    CircularBuffer(const CircularBuffer &a_): cap{a_.capacity()}, arr{new T[cap]}, current_size{a_.size()}
    { for (size_t it = 0; it < current_size; it++) arr[it] = a_[it]; }

    CircularBuffer(const size_t cap_, T def = T()):  cap{cap_}, arr{new T[cap_] }, current_size{cap_}
    { for(size_t it = 0; it < cap; it++) arr[it] = def; }

    CircularBuffer(initializer_list<T> init_list): cap{init_list.size()}, arr{new T[cap]}, current_size{init_list.size()} 
    { for (size_t it = 0; it < cap; it++) arr[it] = *(init_list.begin() + it); }

    ~CircularBuffer() { delete[] arr; }

    T& at(size_t index) {
        if (index >= current_size) {
            cerr << "Error: Invalid buffer index" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[index];
    }

    const T& at(size_t index) const {
        if (index >= current_size) {
            cerr << "Error: Invalid buffer index" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[index];
    }

    T& operator[](size_t index) { return arr[index]; }

    const T& operator[](size_t index) const { return arr[index]; }

    T& operator=(const CircularBuffer &new_buffer) {
        if (this == new_buffer)
        cap = new_buffer.capacity();
        current_size = new_buffer.size();
        delete[] arr;
        arr = new T[cap];
        for (size_t i = 0; i < cap; i++)
        {
            arr[i] = new_buffer[i];
        }
    }

    bool operator==(CircularBuffer &b) {
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

    T& front() { return arr[0]; }

    const T& front() const {return arr[0]; }

    T& back() { return arr[current_size - 1]; }

    const T& back() const { return arr[current_size - 1]; }

    T *begin() const { return &arr[0]; }

    T *end() const { return &arr[cap]; }

    bool full() const { return current_size == cap; }

    bool empty() const { return current_size == 0; }

    size_t size() const { return current_size; }

    size_t capacity() const { return cap; }

    size_t reserve() const { return capacity - current_size; }

    void set_capacity(const size_t &new_capacity) {
        T *newarr = new T[new_capacity];
        for (size_t i = 0; i < current_size; i++)
            newarr[i] = arr[i];
        
        delete[] arr;
        arr = newarr;
        current_size = new_capacity;
        cap = new_capacity;
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

int main()
{
    CircularBuffer<int> a(10, 5);
    CircularBuffer <int> b = a;
    b.set_capacity(15);
    for (auto &x : b)
        cout << " " << x;
}
