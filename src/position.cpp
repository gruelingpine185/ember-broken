#include "position.h"


namespace mbr {
    pos::pos(uint32_t _ln, uint32_t _col, size_t _offset):
        ln(_ln), col(_col), offset(_offset) {}

    pos::pos():
        ln(1), col(1), offset(0) {}

    pos::~pos() {}
}
