//
// Created by Zeynalabdinov Mikayil on 20.06.26.
//

#ifndef MEMORY_ALLOCATOR_MEMORYPOOL_H
#define MEMORY_ALLOCATOR_MEMORYPOOL_H


#pragma once

#include <cstddef>


class MemoryPool
{

private:

    char* memory;

    size_t size;


public:

    MemoryPool(size_t size);

    ~MemoryPool();


    char* getMemory();

};


#endif //MEMORY_ALLOCATOR_MEMORYPOOL_H
