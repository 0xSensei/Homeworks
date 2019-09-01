#include <stdio.h>
#include "string.h"
#include <ctype.h>


int TestPalindrome(int start, int end, char* string);

int main()
{

	char test[] = "a man a plan a canal panama.";

	int res = TestPalindrome(0, strlen(test) - 1, test);

	printf("%d", res);
}


int TestPalindrome(int start, int end, char* string) {

	if (*(string + start) == ' ' || ispunct(*(string + start)))
		return TestPalindrome(++start, end, string);
	if(*(string+end) == ' ' || ispunct(*(string + end)) )
		return TestPalindrome(start, --end, string);
	if (*(string + start) != *(string + end))
		return 0;

	if (start == end)
			return 1;

	return TestPalindrome(++start, --end, string);

}
