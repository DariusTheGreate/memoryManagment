#include "linearAllocator.h"
#include "stackAllocator.h"
#include "linearAllocator.h"
#include "utils.h"

#include "stdio.h"
#include "stdint.h"

#include "string.h"

int main(){
	void* my_data = safe_malloc(20);
	void* my_data2 = safe_malloc(20);
	void* my_data3 = safe_malloc(20);
	
	printf("\nfrom malloc -> %ld\n",(long int)my_data);
	//my_data = "sadasdsad\0";

	safe_free(my_data2);
	safe_free(my_data);
	safe_free(my_data3);
	

	//stack_allocator* sa = create_stack_allocator(1000);
	//char* data = (char*)s_alloc(sa, 20);
	//data = "122222222222222\0";

		
	//destroy_stack_allocator(sa);
	printf("\nend here\n");	
	return 0;
}
