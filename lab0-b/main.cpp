#include <iostream>
#include "word_counter.hpp"

int main(int argc, char* argv[])
{

    if (argc != 3)
    {
        std::cout << ( argc < 3 ? "More arguettes are needed" : "Fewer arguments are needed");
        return 0;
    }

    word_counter wc(argv[1], argv[2]);
    wc.reader();
    wc.writer();
}