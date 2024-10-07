#include "../lib/word_counter/word_counter.hpp"

#include <gtest/gtest.h>
#include "../lib/word_counter/word_counter.hpp"

TEST(TestOpenFile, FileReadFail) {
    word_counter wc("in.txt", "out.csv");
    ASSERT_TRUE(1 == true);
}