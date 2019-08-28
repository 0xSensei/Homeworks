#include <stdio.h>
#define SIZE 512

// function prototypes
void recurse_gather(int i, int frequency[], char* str);
void Print(char c, int d);
void recurse_print(int i, int frequency[], char str[]);

// test case
// xyz0_ xyZ&amp;^%ABAZ**
int main(void)
{
	char input[SIZE] = { 0 };	// will hold 512 string
	

	int freq[94] = { 0 }; // Whole Ascii range

	fgets(input, SIZE, stdin);
	
	recurse_gather(0, freq, input);
	recurse_print(0, freq, input);
}

void recurse_gather(int i, int frequency[], char str[]) {

	if (str[i] == '\n') return;
	if (str[i] >= 32 && str[i] <= 126) ++frequency[str[i] - 32];

	recurse_gather(++i, frequency, str);
}

void recurse_print(int i, int frequency[], char str[]) {

	if ((i + 32) >= 126) return;

	printf("Freq[%c] = %d\n", i + 32, frequency[i]);
	recurse_print(++i, frequency, str);
}

