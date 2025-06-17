#include <cstdint>
#include <iostream>

#include "disassembler.h"

#define PUSH_INSTR = 0xC0

// Turn formatting off for more intuitive formatting
// clang-format off
static const uint8_t SIZES[256] = {
//        0x0  0x1  0x2  0x3  0x4  0x5  0x6  0x7  0x8  0x9  0xA  0xB  0xC  0xD  0xE  0xF
/*0x0*/   255, 255, 255, 255, 255, 255, 255,   1,   1,   1,   1,   1,   1,   1,   1,   1,
/*0x1*/     1,   1,   1,   1,   1,   1, 255, 225, 225, 225, 225, 255, 255, 255, 255, 255,
/*0x2*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0x3*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0x4*/   255, 255, 255, 255, 255,   7, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0x5*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0x6*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0x7*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0x8*/   255, 255, 255, 255, 255, 255,   3, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0x9*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   1,   1,   1, 255,
/*0xA*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0xB*/   255, 255, 255, 255, 255, 255,   3,   3,   3, 255,   3,   3, 255, 255, 255, 255,
/*0xC*/    10, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0xD*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0xE*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
/*0xF*/   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   3,
};
// clang-format on

std::string byte_to_ident(uint8_t byte)
{
    if (SIZES[byte] == 255)
    {
        throw std::runtime_error("Invalid GM:S VM instruction found");
    }
    // TODO: FINISH
}

Disassembler::Bytecode::Bytecode(BoundedReader *_reader)
{
    reader = _reader;
}

void Disassembler::Bytecode::print_bytecode()
{
    reader->reset();
    uint32_t length = reader->length();
    while (reader->offset() < length)
    {
        uint8_t byte = *(uint8_t *)(reader->read_incr(sizeof(uint8_t)));
        if (SIZES[byte] == 255)
        {
            throw std::runtime_error("Invalid GM:S VM instruction found");
        }
    }
}

Disassembler::Bytecode::~Bytecode()
{
    delete reader;
}