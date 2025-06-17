#pragma once

#include <map>
#include <string>

#include "./chunk.h"

class GMString : public Deserializable
{
private:
    std::string value;

public:
    GMString(BoundedReader &reader);
    std::string get_value();
};

class StrgChunk : public Chunk
{
private:
    std::map<uint32_t, GMString> string_map;

public:
    StrgChunk(BoundedReader &_reader);
    void dump_strings();
    ~StrgChunk();
};