## MemoryManagment library, absolutely useless. JFF. 

### Architecture:
 - [x] own concurrent (simple mutex, would be greate to use some lockfree algorithm) sbrk() malloc, called my_malloc()

```
	void* my_data = safe_malloc(20);
	void* my_data2 = safe_malloc(20);
	void* my_data3 = safe_malloc(20);

	safe_free(my_data2);
	safe_free(my_data);
	safe_free(my_data3);	
```

 - [x] some simple memory managment algorithms: stackAllocator, linearAllocator, poolAllocator (in progress, needs testing, review, etc)

```
    stack_allocator* sa = create_stack_allocator(1000);
	char* data = (char*)s_alloc(sa, 20);
	data = "122222222222222\0";

	destroy_stack_allocator(sa);
```

 - [x] some std wrapper

```
    Allocator<int, StackAllocatorWrapper> alloc(15);
    auto ptr = alloc.allocate(5);
    std::cout << ptr << "\n";
    alloc.construct(ptr, 7);
    std::cout << *(ptr);   
    alloc.destroy(ptr);
    alloc.deallocate(ptr, 5);
```

