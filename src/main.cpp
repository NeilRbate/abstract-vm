#include "../include/abstarct-vm.hpp"


int main(int argc, char **argv) {

    if (argc == 1) {
        std::cout << "STDIN mode" << std::endl;
    } else if (argc == 2) {
        FileParse file(argv[1]);
        Lexer   lexer(file.getData());
        try {
            Execute exec(lexer.getMdata());
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }

    OperandFactory factory;

    return 0;
}
