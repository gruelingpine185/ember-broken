#include <iostream>

#include "token.h"


namespace mbr {
    static const std::string token_names[] = {
        "none", "eof", "unknown",
        "number", "identifier"
    };


    token_as_type::token_as_type():
        str("") {}

    token_as_type::~token_as_type() {}

    token_value::token_value(const token_value& _value):
        type(_value.type) {
            std::cout << "\x1b[32mcreate\x1b[0m " << token_names[(int)this->type] << " " << &*this << std::endl;
        switch (this->type) {
            case token_type::tok_number:
                this->as.i32 = _value.as.i32;
                break;
            case token_type::tok_identifier:
                this->as.str = _value.as.str;
                break;
            default:
                this->as.i32 = _value.as.i32;
                break;
        }
    }

    token_value::token_value():
        type(token_type::tok_none) {
            std::cout << "\x1b[32mcreate\x1b[0m " << token_names[(int)this->type] << " " << &*this << std::endl;
            this->as.i32 = 0;
        }

    token_value::~token_value() {
        std::cout << "\x1b[31mdelete\x1b[0m " << token_names[(int) this->type] << " " << &*this  << std::endl;
    }
    
    token_value& token_value::operator=(const token_value& _value) {
        this->type = _value.type;
        switch (this->type) {
            case token_type::tok_number:
                this->as.i32 = _value.as.i32;
                break;
            case token_type::tok_identifier:
                this->as.str = _value.as.str;
                break;
            default:
                break;
        }
   
        return *this;
    }

    token::token(const std::string_view _lexeme,
                const token_value _value,
                const pos& _pos):
       _lexeme(_lexeme), _value(_value), _pos(_pos) {}

    token::token(const token& _token):
        _lexeme(_token._lexeme), _value(_token._value), _pos(_token._pos) {}

    token::token() {}

    token::~token() {}

    void token::set_pos(const pos& _pos) {
        this->_pos = _pos;
    }

    void token::set_type(token_type _type) {
        this->_value.type = _type;
    }

    void token::set_lexeme(const char* _lexeme, size_t _len) {
        this->_lexeme = {_lexeme, _len}; 
    }

    void token::set_value(const token_value _value) {
        this->_value = _value;
    }

    token_type token::get_type() const {
        return this->_value.type;
    }

    std::string_view token::get_lexeme() const {
        return this->_lexeme;
    }

    token_value token::get_value() const {
        return this->_value;
    }

    pos token::get_pos() const {
        return this->_pos;
    }

    std::string token::type_to_str() const {
        const int type = static_cast<int>(this->_value.type);
        return (((this->_value.type > token_type::tok_none) &&
                (this->_value.type <= token_type::tok_identifier)))?
            token_names[type]: token_names[0];
    }
    
    token& token::operator=(const token& _tok) {
        this->_value.type = _tok._value.type;
        this->_lexeme = _tok._lexeme;
        this->_value = _tok._value;
        this->_pos = _tok._pos;
        return *this;
    }
}
