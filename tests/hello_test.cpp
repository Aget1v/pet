#include <gtest/gtest.h>
#include "hello.hpp"
#include <sstream>
#include <iostream>

// Переопределение std::cout для перехвата вывода
class OutputCapture : public std::stringstream {
public:
    OutputCapture() {
        old_buf = std::cout.rdbuf(this->rdbuf());
    }
    ~OutputCapture() {
        std::cout.rdbuf(old_buf);
    }
private:
    std::streambuf* old_buf;
};

// Тест для функции say_hello
TEST(HelloTest, OutputTest) {
    OutputCapture output;
    hello::say_hello();
    std::string expected_output = "Hello, world!\n";
    EXPECT_EQ(output.str(), expected_output);
}