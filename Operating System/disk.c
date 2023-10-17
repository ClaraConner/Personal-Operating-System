#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.c"

void translate(int * arr, char * instruction){

	int * translation = malloc(2*sizeof(int));

	if(strstr(instruction, "exit") != NULL){
	//	printf("exit found\n");
	
		translation[0] = 0;
		translation[1] = 0;
	
	}
	else if(strstr(instruction, "load_const") != NULL){
	//	printf("load const\n");
	
		translation[0] = 1;
		int argument;
		char gettingArg[20];
		strcpy(gettingArg, instruction);	
		sscanf(instruction, "%s %d", gettingArg, &argument);
		//printf("%s  %d\n", instruction, argument);
		translation[1] = argument;
	}
	else if(strstr(instruction, "move_from_mbr") != NULL){
	//	printf("move from mbr\n");
		
		translation[0] = 2;
		translation[1] = 0;
	}
	else if(strstr(instruction, "move_from_mar") != NULL){
	//	printf("move from mar\n");
		
		translation[0] = 3;
		translation[1] = 0;
	
	}
	else if(strstr(instruction, "move_to_mbr") != NULL){
	//	printf("move to mbr\n");
	
		translation[0] = 4;
		translation[1] = 0;
	
	}
	else if(strstr(instruction, "move_to_mar") != NULL){
	//	printf("move to mar\n");
	
		translation[0] = 5;
		translation[1] = 0;
	}
	else if(strstr(instruction, "load_at_addr") != NULL){
	//	printf("load at addr\n");
	
		translation[0] = 6;
		translation[1] = 0;
	}
	else if(strstr(instruction, "write_at_addr") != NULL){
	//	printf("arite at addr\n");
	
		translation[0] = 7;
		translation[1] = 0;
	}
	else if(strstr(instruction, "add") != NULL){
	//	printf("add\n");
	
		translation[0] = 8;
		translation[1] = 0;
	}
	else if(strstr(instruction, "multiply") != NULL){
	//	printf("multiply\n");
	
		translation[0] = 9;
		translation[1] = 0;
	}
	else if(strstr(instruction, "and") != NULL){
	//	printf("and\n");
	
		translation[0] = 10;
		translation[1] = 0;
	}
	else if(strstr(instruction, "or") != NULL){
	//	printf("or\n");
	
		translation[0] = 11;
		translation[1] = 0;
	}
	else if(strstr(instruction, "ifgo") != NULL){
	//	printf("ifgo\n");
	
		translation[0] = 12;
		int argument;
		char gettingArg[20];
		strcpy(gettingArg, instruction);	
		sscanf(instruction, "%s %d", gettingArg, &argument);
		translation[1] = argument;
	}
	else if(strstr(instruction, "sleep") != NULL){
	//	printf("sleep\n");
		translation[0] = 13;
		translation[1] = 0;
	}
	//printf("Translation: {%d, %d}\n", translation[0], translation[1]);
	arr[0] = translation[0];
	arr[1] = translation[1];
	

}

void load_prog(char fname[], int addr){
	int counter = 4;
	FILE * file_pointer = fopen(fname, "r");

	if (NULL == file_pointer){
		printf("file can't be opened\n");
	}

	char * line;
	size_t len;
	size_t read;
	
	while((read = getline(&line, &len, file_pointer)) != -1){
		
		
		
		if (strstr(line, "//") == NULL){
			//printf(line);
			//printf("\n");
			int arr[2] = {0};
			translate(arr, line);
			
			mem_write(counter, arr);
			counter++;
		}
	}
}

