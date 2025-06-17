#pragma once

#include <cstdint>
#include <stdexcept>
#include <map>

class Deserializable;

class BoundedReader
{
private:
    uint8_t *start, *end, *reader;
    u_int32_t _length, _global_offset;

public:
    BoundedReader(uint8_t *start_bound, uint8_t *end_bound, uint32_t global_offset);
    void move(int32_t size);
    void set(uint32_t location);
    u_int32_t length();
    u_int32_t offset();
    u_int32_t global_offset();
    void reset();

    template <typename T>
    void read_pointer_map(std::map<uint32_t, T> &map)
    {
        uint32_t num_strings = *read_incr<uint32_t>();

        for (int i = 0; i < num_strings; i++)
        {
            uint32_t absolute_location = *read_incr<uint32_t>();
            // TODO: calculation
            throw std::runtime_error("This is not implemented");
            map[absolute_location] = T(*this);
        }
    }

    template <typename T>
    T *read_incr()
    {
        if (end - reader < sizeof(T))
        {
            throw std::runtime_error("BoundedReader cannot read out of bounds");
        }
        T *out = (T *)reader;
        reader += sizeof(T);
        return out;
    }
};

class Deserializable
{
public:
    explicit Deserializable(BoundedReader &reader);
    virtual ~Deserializable() = 0;
};