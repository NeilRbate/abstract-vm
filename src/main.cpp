#include "../include/abstarct-vm.hpp"


int main(int argc, char **argv) {

    if (argc == 1) {
        std::cout << "STDIN mode" << std::endl;
    } else if (argc == 2) {
        FileParse file(argv[1]);
        Lexer   lexer(file.getData());
        Execute exec(lexer.getMdata());
    } else {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }

    OperandFactory factory;

/*
    try
    {
        std::unique_ptr<IOperand const> a(factory.createOperand(eOperandType::Int8, "0"));
        std::unique_ptr<IOperand const> b(factory.createOperand(eOperandType::Double, "3"));
        std::unique_ptr<IOperand const> c (a.get()->operator%(*b.get()));
        std::cout << "getValue -> "<< c->toString() << std::endl;
        std::cout << "get precision -> "<< c->getPrecision() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
*/


    //std::unique_ptr<IOperand const> c (a.get()->operator+(*b.get()));
    //std::unique_ptr<IOperand const> c (a.get()->operator-(*b.get()));
    //std::unique_ptr<IOperand const> c (a.get()->operator*(*b.get()));
        
    return 0;
}
