#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Bruh u deadass sold. W rizz usage is..." << std::endl;
        std::cerr << "zlang <input.zl>" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << argv[1] << std::endl;
    return EXIT_SUCCESS;
}