#include <stdio.h>

typedef struct {
	    unsigned char A, B, C;
	        unsigned short PC;

	            unsigned char mem[65536];
	            } CPU;

void step(CPU *cpu) {
	unsigned char opcode = cpu->mem[cpu->PC++];
	 printf("PC=%04X OPCODE=%02X\n", cpu->PC-1, opcode);

}

int main() {
	CPU cpu = {0};
	step(&cpu);

	return 0;
}
