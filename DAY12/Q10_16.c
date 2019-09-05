#include "limits.h"
#include "stdio.h"




void printBits(unsigned int test);
void reverseBits(unsigned int test);
int multiple(int num);


int main(void) {

	int test =1024 ;

	// 1 2 4 8 16 32 64 128 256 512 1024
  // X = 1024, the function determine if y is multiple of 1024
	printf("%d",multiple(1024));


}


// determine whether num is a multiple of X
int multiple(int num)
{
	int mask = 1; // initialize mask
	int mult = 1; // initialize mult
	
		for (int i = 1; i <= 10; ++i, mask <<= 1) {
		
			if ((num & mask) != 0) {
			mult = 0;
			break;
			
		}
		
	}
	
		return mult;
}
