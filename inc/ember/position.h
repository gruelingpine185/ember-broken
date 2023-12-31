#ifndef EMBER_POSITION_H
#define EMBER_POSITION_H


#include <cstdint>
#include <cstddef>


namespace mbr {
    struct pos;


    struct pos {
        uint32_t ln;
        uint32_t col;
        size_t offset;
    };
}

#endif // EMBER_POSITION_H
