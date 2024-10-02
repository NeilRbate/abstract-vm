#include <iostream>
#include "../include/abstarct-vm.hpp"


int main(int argc, char **argv) {

    if (argc == 1) {
        std::cout << "STDIN mode" << std::endl;
    } else if (argc == 2) {
        FileParse file(argv[1]);
        std::cout << file;
    } else {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }

    return 0;
}