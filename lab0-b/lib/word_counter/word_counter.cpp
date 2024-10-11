#include "./word_counter.hpp"
#include <iomanip>

void word_counter::reader() {
    std::string str;
    size_t largest_word_size = 0;
    size_t words_count = 0;

    while (in >> str) {
        for (size_t i = 0; i < str.size(); i++) {
            if (isalnum(str[i]))
                str[i] = std::tolower(str[i]);
            else
                str.erase(i, 1);
        }

        largest_word_size = std::max(str.size(), largest_word_size);
        counter[str]++;
        words_count++;
    }

    for (auto &x : counter) {
        std::string word = x.first;
        word[0] = toupper(word[0]);
        word += std::string(largest_word_size - word.size(), ' ');
        word_list.push_back({word, x.second, x.second / (double)words_count});
    }

    sort(word_list.begin(), word_list.end(),
    [](word_information &a, word_information &b) {
        return a.count > b.count;
    });
}

void word_counter::writer() {
    for (auto x : word_list) {
        out << x.word << " " << x.count << " "
        << std::setprecision(6) << x.percents * 100 << "%"
        << std::endl;
    }
}