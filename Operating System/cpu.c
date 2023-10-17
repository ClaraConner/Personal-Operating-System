#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.c"

int ir0, ir1, ac, mar, mbr;

int base = 4;
int pc = 0;

void fetch_instruction(int addr){
	int arr[2];
	mem_read(arr, addr);
	ir0 = arr[0];
	ir1 = arr[1];
//	printf("\nCPU IR0: %d   IR1: %d\n:",ir0,ir1);
}

void execute_instruction(){

//	printf("IR0: %d", ir0);
	if(ir0 == 1){
		//move ir1 to ac;
//		printf("load const");
		ac = ir1;
	}

	if(ir0 == 2){
		//move mbr to ac
//		printf("move from mbr");
		ac = mbr;	
		mbr = 0;
	}

	if(ir0 == 3){
		//move mar to ac
//		printf("move from mar");
		ac = mar;
		mar = 0;
	}

	if(ir0 == 4){
		//move ac to mbr
//		printf("move_to_mbr");
		mbr = ac;
		ac = 0;
	}

	if(ir0 == 5){
		//move ac to mar
		mar = ac;
		ac = 0;
	}

	if(ir0 == 6){
		//load an integer in memory using the addres in the mar register
		//into the mbr register
		int arr[2];
		mem_read(arr, mar);
		mbr = arr[1];
	}

	if(ir0 == 7){
		//load an integer into memory using the address in mar
		//using the value in mbr
//		printf("write_at_addr");
		int arr[2] = {0, mbr};
		mem_write(mar, arr);
	
	}

	if(ir0 == 8){
		//add contents of mbr to ac
//		printf("add");
		ac += mbr;
	}

	if(ir0 == 9){
		//multiply mbr and ac and store in ac
//		printf("multiply");
		ac *= mbr;
	}

	if(ir0 == 10){
		//perform logical AND betwene MBR and AC. 0 = false. else = true
		//store in ac
//		printf("and");
		ac = (mbr&ac);
	}

	if(ir0 == 11){
		//perform logical or
//		printf("or");
		ac = (mbr|ac);
	}

	if(ir0 == 12){
		//if the contents of the AC register is not 0
		//then load the integer (addr - 1) into the PC register
		//otherwise do nothing
//		printf("ifgo");
		if(ac != 0){
			pc = (ir1 - 1);
		}
	}

	if(ir0 == 13){
//		printf("sleep");
	}
//	printf("\n");
}

int mem_address(){
	return base + pc;
}

int clock_cycle(){
	fetch_instruction(mem_address());
	
	if(ir0 != 0){
		execute_instruction();
//DEBUG		printf("\nbase: %d  pc: %d  ac: %d  mar: %d  mbr: %d\n", base, pc, ac, mar, mbr); 
		pc++;
		return 1;
	}
	else{
		return 0;
	}
}


