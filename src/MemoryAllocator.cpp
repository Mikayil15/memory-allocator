//
// Created by Zeynalabdinov Mikayil on 20.06.26.
//

#include "../include/allocator/MemoryAllocator.h"


#include <iostream>
#include <cstddef>

MemoryAllocator::MemoryAllocator(size_t size)
    : pool(size)
{

    head = reinterpret_cast<BlockHeader*>(pool.getMemory());



    head->size = size - sizeof(BlockHeader);

    head->free = true;

    head->next = nullptr;
}



void* MemoryAllocator::allocate(size_t size)
{

    BlockHeader* current = head;


    while(current != nullptr)
    {


        if(current->free && current->size >= size)
        {


            size_t remaining =
                    current->size
                    - size
                    - sizeof(BlockHeader);



            if(remaining > sizeof(BlockHeader))
            {

                BlockHeader* newBlock =
                        reinterpret_cast<BlockHeader*>(
                                reinterpret_cast<char*>(current)
                                + sizeof(BlockHeader)
                                + size
                        );



                newBlock->size = remaining;


                newBlock->free = true;


                newBlock->next = current->next;



                // Update current block

                current->next = newBlock;


                current->size = size;

            }





            current->free = false;





            return reinterpret_cast<char*>(current)
                    + sizeof(BlockHeader);

        }


        current = current->next;

    }


    return nullptr;
}





void MemoryAllocator::deallocate(void* ptr)
{

    if(ptr == nullptr)
        return;



    BlockHeader* block =
            reinterpret_cast<BlockHeader*>(
                    reinterpret_cast<char*>(ptr)
                    - sizeof(BlockHeader)
            );


    block->free = true;

}






void MemoryAllocator::printMemory()
{

    BlockHeader* current = head;


    int index = 0;


    while(current)
    {

        std::cout
            << "Block "
            << index++
            << std::endl;


        std::cout
            << "Size: "
            << current->size
            << std::endl;


        std::cout
            << "Free: "
            << current->free
            << std::endl;


        std::cout
            << "-------------------"
            << std::endl;



        current = current->next;

    }

}