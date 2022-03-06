#include "Allocator.h"
#include "AllocatorWrapper.h"
#include <iostream>
#include <vector>

class INT{};

void test1(){
    Allocator<int, StackAllocatorWrapper> alloc(15);
    auto ptr = alloc.allocate(5);
    std::cout << ptr << "\n";
    alloc.construct(ptr, 7);
    std::cout << *(ptr);   
    alloc.destroy(ptr);
    alloc.deallocate(ptr, 5);
}

int main(){
    test1();
    return 0;
}

