#ifndef EMBER_TOKEN_H
#define EMBER_TOKEN_H


#include <cstddef>
#include <string_view>
#include <string>

#include "position.h"


namespace mbr {
    enum class token_type;
    struct token_value;
    class token;


    enum class token_type {
        tok_none,
        tok_eof,
        tok_unknown,
        tok_number,
        tok_identifier
    };

    struct token_value {
    public:
        token_value(const token_value& _value);
        token_value();
        ~token_value();
        token_value& operator=(const token_value& _value);
    public:
        token_type type;
        union {
            int as_i32;
            std::string as_str;
        };
    };

    class token {
    public:
        token(const std::string_view _lexeme,
                const token_value _value,
                const pos& _pos);
        token(const token& _token);
        token();
        ~token();
    public:
        void set_type(token_type _type);
        void set_lexeme(const char* _lexeme, size_t _len);
        void set_value(const token_value _value);
        void set_pos(const pos& _pos);
        token_type get_type() const;
        std::string_view get_lexeme() const;
        token_value get_value() const;
        pos get_pos() const;
        std::string type_to_str() const;
        token& operator=(const token& _tok);
    private:
        std::string_view _lexeme;
        token_value _value;
        pos _pos;
    };
}

#endif // EMBER_TOKEN_H
