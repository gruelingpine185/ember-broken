#include <string_view>

#include "token.h"
#include "lexer.h"


namespace mbr {
    lexer::lexer(const std::string& _data):
        _data(_data), _tokens{} {}

    lexer::~lexer() {}

    bool lexer::can_advance() const {
        return (this->_offset != this->_data.length()); 
    }

    void lexer::advance() {
        this->_offset++;
    }

    bool lexer::is_digit(int _c) const {
        return ((_c >= '0') && (_c <= '9'));
    }

    bool lexer::is_whitespace(int _c) const {
        return (
            (_c == '\t') || (_c == '\r') || (_c == '\n') ||
            (_c == '\v') || (_c == '\f') || (_c == ' ')
        );
    }

    void lexer::skip_whitespace() {
        do {
            if(!this->is_whitespace(this->_data.at(this->_offset))) return;

            this->advance();
        } while(this->can_advance());
    }

    token lexer::collect_number() {
        const size_t start = this->_offset;
        token_value val;
        val.as_i32 = 0;

        do {
            const char curr = this->_data.at(this->_offset);
            if(!this->is_digit(curr)) break;

            val.as_i32 = (val.as_i32 * 10) + (curr - '0');
            this->advance();
        } while(this->can_advance());

        std::string_view lexeme(this->_data.c_str(), (this->_offset - start));
        token tok(token_type::tok_number, lexeme, val);
        return tok;
    }
}
