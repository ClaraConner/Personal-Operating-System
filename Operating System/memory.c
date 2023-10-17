#ifndef MEMORY_C
#define MEMORY_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memory[1024][2];

void mem_read(int *arr, int addr){
//	printf("Value at address %d: {%d, %d}\n", addr, memory[addr][0], memory[addr][1]);
	arr[0] = memory[addr][0];
	arr[1] = memory[addr][1];
}

void mem_write(int addr, int data[]){
	memory[addr][0] = data[0];
	memory[addr][1] = data[1];
}

#endif
