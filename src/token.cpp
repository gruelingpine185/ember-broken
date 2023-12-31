#include "token.h"


namespace mbr {
    token::token(const token_type _type,
                const std::string_view _lexeme,
                token_value _value):
        _type(_type), _lexeme(_lexeme), _value(_value) {}

    token::token():
        _type(token_type::tok_unknown), _lexeme(nullptr), _value{} {}

    token::~token() {}

    token_type token::get_type() const {
        return this->_type;
    }

    std::string_view token::get_lexeme() const {
        return this->_lexeme;
    }

    token_value token::get_value() const {
        return this->_value;
    void token::set_pos(const pos& _pos) {
        this->_pos = _pos;
    }

    void token::set_type(const token_type _type) {
        this->_type = _type;
    }

    void token::set_lexeme(const char* _lexeme, size_t _len) {
        this->_lexeme = {_lexeme, _len}; 
    }

    void token::set_value(const token_value _value) {
        this->_value = _value;
    }
    pos token::get_pos() const {
        return this->_pos;
    }
}
