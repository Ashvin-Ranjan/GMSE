#pragma once

#include "./chunk.h"
#include "./strg_chunk.h"

class FormChunk : public Chunk
{
private:
    StrgChunk *strg_chunk;

public:
    FormChunk(BoundedReader &_reader);
    ~FormChunk();
};