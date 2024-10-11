#include <iostream>
#include "../lib/word_counter/word_counter.hpp"


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << (argc < 3 ? "More argumettes are needed"
                               : "Fewer arguments are needed");
        return 0;
    }

    word_counter wc(argv[1], argv[2]);
    wc.reader();
    wc.writer();

    return 0;
}
