#include "token.h"
#include "lexer.h"


namespace mbr {
    lexer::lexer(const std::string& _data):
        _data(_data), _tokens{} {}

    lexer::~lexer() {}

    bool lexer::can_advance() const {
        return (this->_offset != this->_data.length()); 
    }

    void lexer::advance() {
        this->_offset++;
    }

    bool lexer::is_digit(int _c) const {
        return ((_c >= '0') && (_c <= '9'));
    }

    bool lexer::is_whitespace(int _c) const {
        return (
            (_c == '\t') || (_c == '\r') || (_c == '\n') ||
            (_c == '\v') || (_c == '\f') || (_c == ' ')
        );
    }

    void lexer::skip_whitespace() {
        do {
            if(!this->is_whitespace(this->_data.at(this->_offset))) return;

            this->advance();
        } while(this->can_advance());
    }
}
