#ifndef EMBER_POSITION_H
#define EMBER_POSITION_H


#include <cstdint>
#include <cstddef>


namespace mbr {
    struct pos;


    struct pos {
    public:
        pos(uint32_t _ln, uint32_t _col, size_t _offset);
        pos();
        ~pos();
        void inc_nl();
        void inc_col();
    public:
        uint32_t ln;
        uint32_t col;
        size_t offset;
    };
}

#endif // EMBER_POSITION_H
