//
// Created by Zeynalabdinov Mikayil on 20.06.26.
//
#pragma once

#include <cstddef>
#ifndef MEMORY_ALLOCATOR_BLOCKHEADER_H
#define MEMORY_ALLOCATOR_BLOCKHEADER_H

struct BlockHeader
{
    size_t size;

    bool free;

    BlockHeader* next;
};


#endif //MEMORY_ALLOCATOR_BLOCKHEADER_H
