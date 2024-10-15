#include "../include/abstarct-vm.hpp"


int main(int argc, char **argv) {

    if (argc <= 2) {

        std::vector<std::string> vec;

        if (argc == 2) {
            FileParse file(argv[1]);
            vec = file.getData();
        } else
            vec = UserInput::getUserInput();
        try {
            if (vec.empty()) {
                std::cerr << "Empty arguments\n";
                return 1;
            }
            Lexer   lexer(vec);
            Execute exec(lexer.getMdata());
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }

    return 0;
}