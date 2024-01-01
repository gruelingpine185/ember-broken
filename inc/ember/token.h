#ifndef EMBER_TOKEN_H
#define EMBER_TOKEN_H


#include <cstddef>
#include <string>
#include <string_view>

#include "position.h"


namespace mbr {
    enum class token_type;
    struct token_value;
    class token;


    enum class token_type {
        tok_none,
        tok_unknown,
        tok_number,
        tok_identifier,
        tok_eof
    };

    struct token_value {
    public:
        token_value(const token_value& _value);
        token_value();
        ~token_value();
    public:
        token_type type;
        union {
            int as_i32;
            char* as_str;
        };
    };

    class token {
    public:
        token(const std::string_view _lexeme,
                token_value _value,
                const pos& _pos);
        token();
        ~token();
    public:
        void set_type(const token_type _type);
        void set_lexeme(const char* _lexeme, size_t _len);
        void set_value(const token_value _value);
        void set_pos(const pos& _pos);
        token_type get_type() const;
        std::string_view get_lexeme() const;
        token_value get_value() const;
        pos get_pos() const;
        token& operator=(const token& _tok);
    private:
        token_type _type;
        std::string_view _lexeme;
        token_value _value;
        pos _pos;
    };
}

#endif // EMBER_TOKEN_H
