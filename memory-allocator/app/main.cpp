#include <iostream>

#include "../include/allocator/MemoryAllocator.h"



int main()
{

    MemoryAllocator allocator(1024);


    int* number =
        (int*)allocator.allocate(sizeof(int));


    *number = 100;


    std::cout
        << *number
        << std::endl;


    allocator.deallocate(number);


    allocator.printMemory();


    return 0;
}
