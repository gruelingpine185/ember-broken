#ifndef EMBER_TOKEN_H
#define EMBER_TOKEN_H


#include <cstddef>
#include <string_view>

#include "position.h"


namespace mbr {
    struct token_value;
    class token;

    namespace token_type {
        constexpr int tok_none          = 0;
        constexpr int tok_eof           = 1;
        constexpr int tok_unknown       = 2;
        constexpr int tok_number        = 3;
        constexpr int tok_identifier    = 4;
    }

    struct token_value {
    public:
        token_value(const token_value& _value);
        token_value();
        ~token_value();
    public:
        int type;
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
        void set_type(int _type);
        void set_lexeme(const char* _lexeme, size_t _len);
        void set_value(const token_value _value);
        void set_pos(const pos& _pos);
        int get_type() const;
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
