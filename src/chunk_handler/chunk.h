#pragma once

#include "../utils/utils.h"

class Chunk
{
protected:
    BoundedReader &_reader;
    char ident[4];
    void assign_ident(const char *str);

public:
    explicit Chunk(BoundedReader &reader) : _reader(reader) {};
    uint32_t comp_ident();
    virtual ~Chunk() {};
};