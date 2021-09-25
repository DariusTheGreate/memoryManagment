#include "linearAllocator.h"
#include "stackAllocator.h"
#include "stdio.h"
#include "stdint.h"

#include "string.h"

int main(){
	stack_allocator* sa = create_stack_allocator(1000);
	printf("%s\n", (char*)(sa->buffer_start));
	printf("end\n");	
	return 0;
}
