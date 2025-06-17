#include "reader.h"

BoundedReader::BoundedReader(uint8_t *start_bound, uint8_t *end_bound, uint32_t g_offset)
{
    if (end_bound < start_bound)
    {
        throw std::runtime_error("BoundedReader end bound is before the start bound");
    }
    start = start_bound;
    end = end_bound;
    reader = start_bound;
    _length = end_bound - start_bound;
    _global_offset = g_offset;
}

uint32_t BoundedReader::length()
{
    return _length;
}

uint32_t BoundedReader::offset()
{
    return reader - start;
}

uint32_t BoundedReader::global_offset()
{
    return _global_offset;
}

void BoundedReader::move(int32_t amount)
{
    if (reader + amount < start || reader + amount > end)
    {
        throw std::runtime_error("BoundedReader cannot read out of bounds");
    }
    reader += amount;
}

void BoundedReader::set(uint32_t loc)
{
    if (loc < 0 || loc > _length)
    {
        throw std::runtime_error("BoundedReader cannot be set out of bounds");
    }
    reader = start + loc;
}

void BoundedReader::reset()
{
    reader = start;
}