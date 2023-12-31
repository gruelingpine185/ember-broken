#include "token.h"


namespace mbr {
    token::token(const token_type _type,
                const std::string_view _lexeme,
                token_value _value):
        _type(_type), _lexeme(_lexeme), _value(_value) {}

    token::token():
        _type(token_type::tok_unknown), _lexeme(nullptr), _value{} {}

    token::~token() {}
}
