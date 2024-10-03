#include "word_counter.hpp"
#include <iomanip>

void word_counter::reader()
{
    std::string str;
    size_t largest_word_size = 0;
    double words_count = 0;

    while(in >> str)
    {
        size_t str_size = str.size();
        for (size_t i = 0; i < str_size; i++)
        {
            if (isalnum(str[i]))
                str[i] = std::tolower(str[i]);
            else
                str.erase(str.begin() + i);
        }
        largest_word_size = std::max(str.size(), largest_word_size);
        counter[str]++;
        words_count++;
    }

    for (auto &x : counter)
    {
        std::string word = x.first;
        word[0] = toupper(word[0]);
        word += std::string(largest_word_size - word.size(), ' ');
        word_list.emplace_front(std::tuple{word, x.second, x.second / words_count});
    }
}

void word_counter::writer()
{
    for (auto x : word_list)
    {
        out << std::get<std::string>(x) << " " <<  std::get<size_t>(x) << " " << std::setprecision(4) << std::get<double>(x) * 100 <<"%" << std::endl;
    }
}
