#include <iostream>
#include <fstream>
#include "./instructions.h"

int main(int argc, char **argv)
{
    std::cout << "Hello, World!" << std::endl;
    if (argc == 1) {
        std::cout << "USAGE: emulator8080 [file_path]" << std::endl;
        return 1;
    }
    std::fstream file(argv[1], std::ios::binary | std::ios::in);
    int fsize;

    file.seekg(0, file.end);
    fsize = file.tellg();
    file.seekg(0, file.beg);
    std::cout << fsize << std::endl;
    char *buffer = new char[fsize];
    file.read(buffer, fsize);
    file.close();

    int pc = 0;
    while (pc < fsize) {
        pc += InstructionDisassembler(buffer, pc);
    }

    return 0;
}
