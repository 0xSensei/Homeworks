#include "limits.h"
#include "stdio.h"




void printBits(unsigned int test);
void reverseBits(unsigned int test);


int main(void) {

	unsigned int test = 0x5421235a;
	//01010100 00100001 00100011 01011010
	//01010100 00100001 00100011 01011010
	printBits(test);
	printf("\n");
	reverseBits(test);


}


// print bits
void printBits(unsigned int test) {

	int bits_size = CHAR_BIT * sizeof(int) - 1;
	for (unsigned int i = bits_size; i != -1; i--)
	{
		printf("%c", test >> i & 1 ? '1' : '0');
		if (i % 8 == 0)
			printf(" ");
	}
}

void reverseBits(unsigned int test) {
	int bits_size = CHAR_BIT * sizeof(int) - 1;
	for (unsigned int i = 0; i <= bits_size; i++)
	{
		printf("%c", test &  (1 << i) ? '1' : '0');
		if ((i+1) % 8	== 0)
			printf(" ");
	}
}
