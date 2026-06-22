#include <iostream>

#include "../include/allocator/MemoryAllocator.h"



int main()
{

    MemoryAllocator allocator(1024);



    int* a =
        (int*)allocator.allocate(100);



    int* b =
        (int*)allocator.allocate(200);



    int* c =
        (int*)allocator.allocate(50);



    *a = 10;

    *b = 20;

    *c = 30;



    std::cout << *a << std::endl;

    std::cout << *b << std::endl;

    std::cout << *c << std::endl;



    allocator.printMemory();



    allocator.deallocate(b);



    std::cout << "\nAfter Free b\n";

    allocator.printMemory();


    return 0;
}