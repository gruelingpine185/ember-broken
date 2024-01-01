#include <string_view>
#include <cstring>

#include "token.h"
#include "lexer.h"


namespace mbr {
    lexer::lexer(const std::string& _data):
        _data(_data), _tokens{}, _pos{} {}

    lexer::~lexer() {}

    bool lexer::can_advance() const {
        return (this->_pos.offset < this->_data.length()); 
    }

    void lexer::advance() {
        (this->_data.at(this->_pos.offset) == '\n')?
            this->_pos.inc_nl():
            this->_pos.inc_col();
    }

    bool lexer::is_digit(int _c) const {
        return ((_c >= '0') && (_c <= '9'));
    }

    bool lexer::is_upcase(int _c) const {
        return ((_c >= 'A') && (_c <= 'Z'));
    }

    bool lexer::is_locase(int _c) const {
        return ((_c >= 'a') && (_c <= 'z'));
    }

    bool lexer::is_letter(int _c) const {
        return (this->is_upcase(_c) || this->is_locase(_c));
    }

    bool lexer::is_identidier(int _c) const {
        return ((_c == '_') || this->is_digit(_c) || this->is_letter(_c));
    }

    bool lexer::is_whitespace(int _c) const {
        return (
            (_c == '\t') || (_c == '\r') || (_c == '\n') ||
            (_c == '\v') || (_c == '\f') || (_c == ' ')
        );
    }

    void lexer::skip_whitespace() {
        do {
            if(!this->is_whitespace(this->_data.at(this->_pos.offset))) return;

            this->advance();
        } while(this->can_advance());
    }

    token lexer::collect_number() {
        const pos start_pos = this->_pos;
        token_value val;
        val.type = token_type::tok_number;
        val.as_i32 = 0;
        do {
            const char curr = this->_data.at(this->_pos.offset);
            if(!this->is_digit(curr)) break;

            val.as_i32 = (val.as_i32 * 10) + (curr - '0');
            this->advance();
        } while(this->can_advance());

        std::string_view lexeme(this->_data.c_str() + start_pos.offset,
                                (this->_pos.offset - start_pos.offset));
        token tok(lexeme, val, start_pos);
        return tok;
    }

    token lexer::collect_identifier() {
        const pos start_pos = this->_pos;

        do {
            const char curr = this->_data.at(this->_pos.offset);
            if(!this->is_identidier(curr)) break;


            this->advance();
        } while(this->can_advance());

        token_value val;
        val.type = token_type::tok_identifier;
        val.as_str = nullptr;

        const char* start_ptr = this->_data.c_str() + start_pos.offset;
        const size_t lexeme_len = (this->_pos.offset - start_pos.offset);
        std::string_view lexeme(start_ptr, lexeme_len);
        val.as_str = new char[lexeme_len + 1];
        std::strncpy(val.as_str, start_ptr, lexeme_len);
        token tok(lexeme, val, start_pos);
        return tok;
    }

        while(this->can_advance()) {
            }
    token lexer::lex() {
        if(is_whitespace(this->_data[this->_pos.offset])) {
            this->skip_whitespace();
        }

        if(is_letter(this->_data[this->_pos.offset])) {
            return this->collect_identifier();
        }

        if(is_digit(this->_data[this->_pos.offset])) {
            return this->collect_number();
        }

        if(this->can_advance()) this->advance();
        return {};
    }
}
