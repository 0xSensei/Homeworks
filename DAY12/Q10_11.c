#include "limits.h"
#include "stdio.h"


#define BYTE1 4278190080
#define BYTE2 16711680
#define BYTE3 65280
#define BYTE4 255


void printBits(unsigned int test);
void unpackCharacters(unsigned int test);


int main(void) {

	unsigned int test = 0x5421235a;
	//01010100 00100001 00100011 01011010
	//01010100 00100001 00100011 01011010
	printBits(test);
	printf("\n");
	unpackCharacters(test);


}

// print bits
void printBits(unsigned int test) {
	
	int bits_size = CHAR_BIT * sizeof(int) - 1;
	for (unsigned int i = bits_size; i != -1 ; i--)
	{
		printf("%c",test >> i & 1 ? '1' : '0' );
		if (i % 8 == 0)
			printf(" ");
	}
}





void unpackCharacters(unsigned int test) 
{
	int masks[] = {BYTE1,BYTE2,BYTE3,BYTE4};

	for (size_t i = 0; i < sizeof masks  / sizeof(int); i++)
	{
		char masked_char = (test & masks[i]) >> ((4 - (i + 1)) * 8);
		for (size_t i = CHAR_BIT - 1 ; i !=  UINT_MAX; i--)
		{
			printf("%c", masked_char >> i & 1 ? '1' : '0');
		}
		printf(" ");
	}

}
