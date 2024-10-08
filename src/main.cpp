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

    std::unique_ptr<IOperand const> a(factory.createOperand(eOperandType::Int8, "42"));


    std::cout << "getValue -> "<< a.get()->toString() << std::endl;
    std::cout << "get precision -> "<< a.get()->getPrecision() << std::endl;
    

    return 0;
}
