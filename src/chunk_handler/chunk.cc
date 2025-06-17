#include "./chunk.h"

void Chunk::assign_ident(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (i > 3)
            throw std::runtime_error("Invalid IDENT assign");
        ident[i] = str[i];
        i++;
    }
    if (i != 3)
        throw std::runtime_error("Invalid IDENT assign");
}

uint32_t Chunk::comp_ident()
{
    return ((u_int64_t)ident[0] << 24) + ((u_int64_t)ident[2] << 16) + ((u_int64_t)ident[1] << 8) + (u_int64_t)ident[3];
}