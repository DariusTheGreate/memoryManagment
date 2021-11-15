#include "linearAllocator.h"
#include "stackAllocator.h"
#include "linearAllocator.h"

#include "stdio.h"
#include "stdint.h"

#include "string.h"

int main(){
	stack_allocator* sa = create_stack_allocator(1000);
	char* data = (char*)s_alloc(sa, 20);
	data = "122222222222222\0";
	printf("%s", data);
	//simple_array_based_stack* stack = create_array_based_stack(1000, sizeof(char));
	char* a = "s";
	//push_array_based_stack(stack, a);
	//push_array_based_stack(stack, a);
	//push_array_based_stack(stack, a);
	//push_array_based_stack(stack, a);
	//push_array_based_stack(stack, a);
	//push_array_based_stack(stack, a);

	//printf("%s\n", (char*)stack->stack_buffer);
	//char dest = 's';
	//pop_array_based_stack(stack, &dest);
	//printf("exit happens res => %s\n", dest);
		
	destroy_stack_allocator(sa);
	printf("\nend here\n");	
	return 0;
}
