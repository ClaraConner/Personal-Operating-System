#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "disk.c"
#include "memory.c"
#include "cpu.c"

int main(){

	//======================= EDIT FILE NAME ============================//
	char fname[] = {"inputFile.txt"};
	printf("\n\n\t\tPLEASE NOTE, PROGRAM IS RUNNING FILE: %s\n", fname);
	//===================================================================//
	

	int addr = 4;
	load_prog(fname, addr);
	
	while(clock_cycle() != 0);
	printf("\n\n\t	===================================================\n");
	printf("\t	||	READING FIRST 20 SPOTS OF MEMORY         ||\n");
	printf("\t	===================================================\n");
	for (int i = 0; i < 20; i++){
		int arr[2];
		mem_read(arr, i);
		printf("\t\t||    Memory address %2d: [ %2d , %3d ]            ||\n", i, arr[0], arr[1]);
		
	}
	printf("\t	===================================================\n\n");
	return 0;

}
