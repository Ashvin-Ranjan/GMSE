#include "./strg_chunk.h"

GMString::GMString(BoundedReader &reader) : Deserializable(reader)
{
    throw std::runtime_error("Unimplemented");
}

std::string GMString::get_value() { return value; }

StrgChunk::StrgChunk(BoundedReader &reader) : Chunk(reader)
{
    assign_ident("STRG");
    if (comp_ident() != *reader.read_incr<uint32_t>())
    {
        throw std::runtime_error("Invalid identifier for `STRG` chunk");
    }
    if (reader.length() != *reader.read_incr<uint32_t>())
    {
        throw std::runtime_error("Invalid reader length for `STRG` chunk");
    }

    reader.read_pointer_map(string_map);
}

void StrgChunk::dump_strings()
{
    // TODO: Implement
}

StrgChunk::~StrgChunk() {}