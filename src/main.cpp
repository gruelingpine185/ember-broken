#include <fstream>
#include <sstream>

#include "lexer.h"


int main(int _argc, char** _argv) {
    if(_argc < 2) return 1;

    std::stringstream ss;
    std::fstream input(_argv[1], std::ios::in);
    ss << input.rdbuf();

    mbr::lexer lexer(ss.str());
    lexer.lex();
    return 0;
}
