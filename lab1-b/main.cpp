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
            cerr << "Error: Invalid buffer subscript" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[index];
    }

    T& at(size_t index) const {
        if (index >= current_size) {
            cerr << "Error: Invalid buffer subscript" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[index];
    }

    T& operator[](size_t index) { return arr[index]; }

    const T& operator[](size_t index) const { return arr[index]; }

    void operator=(CircularBuffer arr_) {
        cap = arr_.capacity();
        current_size = arr_.size();
        arr = new T[cap];
    }

    void operator=(initializer_list<T> init_list) {
        cap = init_list.size();
        arr = new T[cap];
        current_size = cap;
        copy(init_list.begin(), init_list.end(), &arr[0]);
    }

    bool operator==(CircularBuffer &b) {
        if (current_size != b.size())
            return false;
        for (size_t i = 0; i < b.size(); i++)
            if (b[i] != arr[i])
                return false;
        return true;
    }

    bool operator!=(CircularBuffer &b) {
        if (current_size != b.size())
            return true;
        for (size_t i = 0; i < b.size(); i++)
            if (b[i] != arr[i])
                return true;
        return false;
    }

    T& front() { return arr[0]; }

    T& front() const {return arr[0]; }

    T& back() { return arr[current_size - 1]; }

    T& back() const { return arr[current_size - 1]; }

    T *begin() const { return &arr[0]; }

    T *end() const { return &arr[cap]; }

    bool full() const { return current_size == cap; }

    bool empty() const { return current_size == 0; }

    size_t size() const { return current_size; }

    size_t capacity() const { return cap; }

    size_t reserve() const { return capacity - current_size; }

    void set_capacity(const size_t new_capacity) {
        T *newarr = new T[new_capacity];
        current_size = min(new_capacity, current_size);
        for (size_t i = 0; i < current_size; i++)
            newarr[i] = arr[i];
        
        if (arr) delete[] arr;
        arr = newarr;
        cap = new_capacity;
    }

    void clear() { delete[] arr; arr = nullptr; cap = 0; current_size = 0; }

private:
    mutable size_t cap;
    T *arr;
    size_t current_size;
    size_t first_element;
};

int main()
{
    CircularBuffer<int> a {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    CircularBuffer <int> b = a;
    b.clear();
    cout << b.empty() << endl;
    b.set_capacity(10);
    for (int i = 0; i < 10; i++)
        b[i] = i;
    cout << a.size() << " " << b.size() << endl;

    for (auto &x : a)
        cout << x << " ";
    cout << endl;

    for (auto &x : b)
        cout << x << " ";
    cout << endl;
    
    cout << (b == a);
}
