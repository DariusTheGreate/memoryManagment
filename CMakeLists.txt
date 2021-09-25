cmake_minimum_required(VERSION 3.0.0)

project(memoryManagment VERSION 0.0.1
	DESCRIPTION "some memory managment stuff"
	)
add_executable(memoryManagment
	generalAllocators/linearAllocator.h
	generalAllocators/linearAllocator.c
	generalAllocators/stackAllocator.h
	generalAllocators/stackAllocator.c
	generalAllocators/allocatorsTest.c
	)






