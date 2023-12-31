#include "token.h"
#include "lexer.h"


namespace mbr {
    lexer::lexer(const std::string& _data):
        _data(_data), _tokens{} {}

    lexer::~lexer() {}
}
