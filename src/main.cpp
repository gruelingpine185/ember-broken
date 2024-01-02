#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "token.h"
#include "lexer.h"


int main(int _argc, char** _argv) {
    if(_argc < 2) {
        std::cout << "Expected filepath." << std::endl;
        return 1;
    }

    std::cout << "tok_number: " << mbr::token_type::tok_number << std::endl;
    std::stringstream ss;
    std::fstream input(_argv[1], std::ios::in);
    ss << input.rdbuf();

    std::vector<mbr::token> tokens;
    mbr::lexer lexer(ss.str());
    size_t i = 0;
    while(lexer.can_advance()) {
        //tokens.push_back(lexer.lex());
        //mbr::token curr = tokens[i++];
        mbr::token* curr = lexer.lex();
#if 1
        std::cout
            << "type: " << static_cast<int>(curr->get_type()) << std::endl
            << "typeof: " << curr->type_to_str() << std::endl
            << "lexeme: \'" << curr->get_lexeme() << "\'"
            <<
        std::endl;
        switch(curr->get_type()) {
            case mbr::token_type::tok_identifier:
                std::cout << "value: \'" << curr->get_value().as_str << "\'"
                    << std::endl;
                break;
            case mbr::token_type::tok_number:
                std::cout << "value: " << curr->get_value().as_i32
                    << std::endl;
                break;
            default:
                std::cout << "value: <default>" << std::endl; 
                break;
        }
        delete curr;
#endif
    }

    return 0;
}
