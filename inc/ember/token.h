#ifndef EMBER_TOKEN_H
#define EMBER_TOKEN_H


namespace mbr {
    enum class token_type;
    union token_value;


    enum class token_type {
        tok_unknown,
        tok_number,
        tok_eof
    };

    union token_value {
        int as_i32;
    };
}

#endif // EMBER_TOKEN_H
