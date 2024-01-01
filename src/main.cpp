#include <fstream>
#include <sstream>
#include <iostream>

#include "token.h"
#include "lexer.h"


int main(int _argc, char** _argv) {
    if(_argc < 2) return 1;

    std::stringstream ss;
    std::fstream input(_argv[1], std::ios::in);
    ss << input.rdbuf();

    mbr::lexer lexer(ss.str());
    mbr::token tok;
    while(lexer.can_advance()) {
        tok = lexer.lex();
#if 1
        std::cout
            << "type: " << static_cast<int>(tok.get_type()) << std::endl
            << "lexeme: \'" << tok.get_lexeme() << "\'" <<
            std::endl;
        switch(tok.get_type()) {
            case mbr::token_type::tok_identifier:
                std::cout << "value: \'" << tok.get_value().as_str << "\'"
                    << std::endl;
                break;
            case mbr::token_type::tok_number:
                std::cout << "value: " << tok.get_value().as_i32
                    << std::endl;
                break;
            default:
                break;
        }
#endif
    }

    return 0;
}
