#include <iostream>
#include <algorithm>
#include <concepts>
#include "./circularbuffer/circularbuffer.hpp"

using namespace std;

int main()
{
    CircularBuffer<int> a(10, 5);
    for (int i = 0; i < 15; i ++)
    {
        for (int j = 0; j < a.size(); j++)
            cout << a[j] << " ";
        cout << endl;
        a.push_back(i);
    }
    for (int i = 0; i < 11; i ++)
    {
        for (int j = 0; j < a.size(); j++)
            cout << a[j] << " ";
        cout << endl;
        a.pop_back();
    }
    for (int j = 0; j < a.size(); j++)
        cout << a.at(j) << " ";
}
