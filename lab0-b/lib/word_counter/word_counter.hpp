#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <tuple>

class word_counter {
 public:
    explicit word_counter(std::string input_filename = "in.txt",
                std::string output_filename = "out.csv") {
        in.open(input_filename);
        if (!in.is_open()) {
            std::cerr << "ERROR: word_counter.hpp: Input file "<< input_filename << " can't be open" << std::endl;
            exit(EXIT_FAILURE);
        }

        out.open(output_filename);
        if (!out.is_open()) {
            std::cerr << "ERROR: word_counter.hpp: Output file " << output_filename << " can't be open" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void reader();

    void writer();

    ~word_counter() {
        in.close();
        out.close();
        counter.clear();
        word_list.clear();
    }

 private:
    struct word_information {
        std::string word;
        size_t count;
        double percents;
    };

    std::ifstream in;
    std::ofstream out;
    std::map <std::string, size_t> counter;
    std::vector<word_information> word_list;
};