#include "interpreter.hpp"

#include <string>
#include <fstream>

int main(int argc, char *argv[]) {
    
    if (argc == 1) {
        return 1;
    }
    std::string program = "";
    std::ifstream MyReadFile(argv[1]);
    std::getline (MyReadFile, program);

    Interpreter interp;
    interp.load(program);
    interp.run();

}