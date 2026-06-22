//
// Created by Zeynalabdinov Mikayil on 20.06.26.
//

#include "../include/allocator/MemoryAllocator.h"


#include <iostream>
#include <cstddef>

MemoryAllocator::MemoryAllocator(size_t size)
    : pool(size)
{
    head = (BlockHeader*)pool.getMemory();


    head->size = size - sizeof(BlockHeader);
    head->free = true;
    head->next = nullptr;
}

void* MemoryAllocator::allocate(size_t size)
{
    BlockHeader* current = head;

    while (current)
    {
        if (current->free && current->size >= size)
        {
            current->free = false;

            return (void*)((char*)current + sizeof(BlockHeader));
        }

        current = current->next;
    }

    return nullptr;
}


void MemoryAllocator::deallocate(void* ptr)
{
    if (!ptr) return;

    BlockHeader* block =
        (BlockHeader*)((char*)ptr - sizeof(BlockHeader));

    block->free = true;
}


void MemoryAllocator::printMemory()
{
    BlockHeader* current = head;
    int index = 0;

    while (current)
    {
        std::cout << "Block " << index++ << "\n";
        std::cout << "Size: " << current->size << "\n";
        std::cout << "Free: " << current->free << "\n";
        std::cout << "-------------------\n";

        current = current->next;
    }
}
