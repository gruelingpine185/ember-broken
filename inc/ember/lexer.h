#ifndef EMBER_LEXER_H
#define EMBER_LEXER_H


#include <cstddef>
#include <string>
#include <vector>


namespace mbr {
    class token;
    class lexer;


    class lexer {
        public:
            lexer(const std::string& _data);
            ~lexer();
        private:
            bool can_advance() const;
            void advance();
            bool is_digit(int _c) const;
            bool is_whitespace(int _c) const;
            void skip_whitespace();
        private:
            const std::string _data;
            size_t _offset;
            std::vector<token> _tokens;
    };
}

#endif // EMBER_LEXER_H
