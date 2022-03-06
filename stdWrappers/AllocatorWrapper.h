#ifndef _ALLOCATOR_WRAPPER_
#define _ALLOCATOR_WRAPPER_

#include "../generalAllocators/stackAllocator.h"

class AllocatorWrapper{
public:
    AllocatorWrapper() {};
    AllocatorWrapper(int) {};
    virtual void* allocate(int sz){return reinterpret_cast<void*>(new char[sz]);};
     
    virtual void deallocate(void* ptr){ delete[] reinterpret_cast<char*>(ptr); };
};

class StackAllocatorWrapper : AllocatorWrapper{
public:
    StackAllocatorWrapper(int sz){
        allocer = create_stack_allocator(sz);
    }    

    void* allocate(int sz){
        return s_alloc(allocer, sz);
    }    

    void deallocate(void* ptr, int sz){
        s_free_chunk(allocer, sz);
    }

    void destroy(){
        destroy_stack_allocator(allocer);
    }

private:
    stack_allocator* allocer;

};

#endif

