#ifndef EMBER_TOKEN_H
#define EMBER_TOKEN_H


#include <cstddef>
#include <string>
#include <string_view>


namespace mbr {
    enum class token_type;
    union token_value;
    class token;


    enum class token_type {
        tok_unknown,
        tok_number,
        tok_eof
    };

    union token_value {
        int as_i32;
    };

    class token {
    public:
        token(const token_type _type,
                const std::string_view _lexeme,
                token_value _value);
        token();
        ~token();
    private:
        token_type _type;
        std::string_view _lexeme;
        token_value _value;
    };
}

#endif // EMBER_TOKEN_H
