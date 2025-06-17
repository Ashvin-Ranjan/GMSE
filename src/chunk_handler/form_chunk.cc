#include "./form_chunk.h"

FormChunk::FormChunk(BoundedReader &reader) : Chunk(reader)
{
    assign_ident("FORM");
}

FormChunk::~FormChunk()
{
    delete strg_chunk;
}