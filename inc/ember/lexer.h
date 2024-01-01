#ifndef EMBER_LEXER_H
#define EMBER_LEXER_H


#include <cstddef>
#include <string>
#include <vector>

#include "position.h"


namespace mbr {
    class token;
    class lexer;


    class lexer {
        public:
            lexer(const std::string& _data);
            ~lexer();
        public:
            token lex();
            bool can_advance() const;
        private:
            void advance();
            bool is_digit(int _c) const;
            bool is_upcase(int _c) const;
            bool is_locase(int _c) const;
            bool is_letter(int _c) const;
            bool is_identidier(int _c) const;
            bool is_whitespace(int _c) const;
            void skip_whitespace();
            token collect_number();
            token collect_identifier();
        private:
            const std::string _data;
            std::vector<token> _tokens;
            pos _pos;
    };
}

#endif // EMBER_LEXER_H
