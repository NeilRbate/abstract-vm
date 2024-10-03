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


    Int8 c(25, eOperandType::Int8, ePrecision::int8);
    IOperand    *a = new Int8(25, eOperandType::Int8, ePrecision::int8);

    std::cout << "get precision -> "<< a->getPrecision() << std::endl;
    std::cout << "getValue -> "<< a->toString() << std::endl;
    

    return 0;
}