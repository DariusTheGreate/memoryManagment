#include "linearAllocator.h"
#include "stackAllocator.h"
#include "linearAllocator.h"
#include "poolAllocator.h"
#include "simpleArrayBasedStack.h"

#include "stdio.h"
#include "stdint.h"

#include "string.h"

int main(){
	//stack_allocator* sa = create_stack_allocator(1000);

	simple_array_based_stack* stack = create_array_based_stack(1000, sizeof(char));
	char* a = "s";
	push_array_based_stack(stack, a);
	push_array_based_stack(stack, a);
	push_array_based_stack(stack, a);
	push_array_based_stack(stack, a);
	push_array_based_stack(stack, a);
	push_array_based_stack(stack, a);

	printf("%s\n", (char*)stack->stack_buffer);
	char dest = 's';
	pop_array_based_stack(stack, &dest);
	printf("exit happens res => %s\n", dest);
	
	printf("end\n");	
	return 0;
}
