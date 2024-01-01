#include "token.h"


namespace mbr {    
    token_value::token_value(const token_value& _value):
        type(_value.type) {
        switch (this->type) {
            case token_type::tok_number:
                this->as_i32 = _value.as_i32;
                break;
            case token_type::tok_identifier:
                this->as_str = _value.as_str;
                break;
            default:
                break;
        }
    }

    token_value::token_value():
        type(token_type::tok_none) {
        }

    token_value::~token_value() {
        if(this->type == token_type::tok_identifier) {
            std::cout << "  deleting str" << std::endl;
#if 0
            delete[] this->as_str;
#endif
        }
    }

                token_value _value,
                const pos& _pos):
        _type(_type), _lexeme(_lexeme), _value(_value), _pos(_pos) {}

    token::token():
        _type(token_type::tok_unknown), _lexeme(nullptr), _value{}, _pos{} {}

    token::~token() {}

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

    token_type token::get_type() const {
        return this->_type;
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
}
