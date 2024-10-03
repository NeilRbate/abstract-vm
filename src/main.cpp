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

    OperandFactory factory;

    auto a = factory.createOperand(eOperandType::Int8, "42");

    std::cout << "get precision -> "<< a->getPrecision() << std::endl;
    std::cout << "getValue -> "<< a->toString() << std::endl;
    

    return 0;
}