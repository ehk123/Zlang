#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>
#include <stdlib.h>

#include "./tokenization.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Bruh u deadass sold. W rizz usage is..." << std::endl;
        std::cerr << "zlang <input.zl>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    Tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();

    return EXIT_SUCCESS;
}