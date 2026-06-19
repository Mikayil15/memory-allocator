//
// Created by Zeynalabdinov Mikayil on 20.06.26.
//

#ifndef MEMORY_ALLOCATOR_MEMORYALLOCATOR_H
#define MEMORY_ALLOCATOR_MEMORYALLOCATOR_H



#pragma once

#include "BlockHeader.h"
#include "MemoryPool.h"


class MemoryAllocator
{

private:

    MemoryPool pool;

    BlockHeader* head;


public:

    MemoryAllocator(size_t size);


    void* allocate(size_t size);


    void deallocate(void* ptr);


    void printMemory();

};



#endif //MEMORY_ALLOCATOR_MEMORYALLOCATOR_H
