#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <tuple>

class word_counter{
public:

    word_counter(std::string input_filename = "in.txt", std::string output_filename= "out.csv")
    {
        
        in.open(input_filename);
        if (!in.is_open())
        {
            std::cerr << "Input file can't be open" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        out.open(output_filename);
        if (!out.is_open())
        {
            std::cerr << "Output file can't be open" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void reader();

    void writer();

    ~word_counter()
    {
        in.close();
        out.close();
        counter.clear();
        word_list.clear();
    }

private:
    std::ifstream in;
    std::ofstream out;
    std::map <std::string, size_t> counter;
    std::list<std::tuple<std::string, size_t, double>> word_list;
};