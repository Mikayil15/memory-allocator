//
// Created by Zeynalabdinov Mikayil on 20.06.26.
//

#include "../include/allocator/MemoryPool.h"



MemoryPool::MemoryPool(size_t size)
{

    this->size = size;

    memory = new char[size];

}


MemoryPool::~MemoryPool()
{

    delete[] memory;

}


char* MemoryPool::getMemory()
{
    return memory;
}
