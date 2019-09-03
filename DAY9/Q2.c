// ex07_20.c
 // what does this program do?
#include "pch.h"
#include <stdio.h>
#include "ctype.h"
#include "string.h"
#define INT_ARRAY_SIZE  10


/*Q1
(Calculating Circle Circumference, Circle Area or Sphere Volume Using Function Pointers)
Using the techniques you learned in Fig. 7.28, create a text-based, menu-driven program that allows
the user to choose whether to calculate the circumference of a circle, the area of a circle or the volume of a sphere. The program should then input a radius from the user, perform the appropriate
calculation and display the result. Use an array of function pointers in which each pointer represents
a function that returns void and receives a double parameter. The corresponding functions should
each display messages indicating which calculation was performed, the value of the radius and the
result of the calculation.

Menu of 3 choices:
1-circumference of a circle (2 * PI * user input (double))
2-the area of a circle (PI * user_iput^2)
3-volume of a sphere (4/3 * PI * r^3)

make 3 functions with their pointers


*/
/* Q2
(Text Analysis) The availability of computers with string-manipulation capabilities has resulted in some rather interesting approaches to analyzing the writings of great authors. Much attention has been focused on whether William Shakespeare ever lived. Some scholars find substantial
evidence that Christopher Marlowe actually penned the masterpieces attributed to Shakespeare. Researchers have used computers to find similarities in the writings of these two authors. This exercise
examines three methods for analyzing texts with a computer.
a) Write a program that reads several lines of text and prints a table indicating the number
of occurrences of each letter of the alphabet in the text. For example, the phrase
To be, or not to be: that is the question:
contains one “a,” two “b’s,” no “c’s,” and so on.
b) Write a program that reads several lines of text and prints a table indicating the number
of one-letter words, two-letter words, three-letter words, and so on, appearing in the
text. For example, the phrase
Whether 'tis nobler in the mind to suffer

*/




void countCharacters(char* src);
void wordCounts(char *src);

int main(void)
{
	char test[] = "Whether 'tis nobler in the mind to suffer";
	wordCounts(test);
	char test2[] = "To be, or not to be: that is the question:";
	countCharacters(test2);
}


void countCharacters(char* src) {
	// walk every character until \0 and subtact base and compare boundry and ++
	int counts[26] = { 0 };
	while (*src)
	{
		
		if (tolower(*src) >= 97 && tolower(*src) - 97 <= 122) { // lower a-z
			counts[tolower(*src) - 97]++;
		}
		src++;
	}
	for (size_t i = 0; i < 26; i++)
	{
		printf("%c occured %d\n", i + 97, counts[i]);

	}

}
void wordCounts(char *src) {
	// strtok and count 

	int counts[INT_ARRAY_SIZE][1] = { 0 };
	int counter = 0;
	char* token = strtok(src, " ");

	while (token != NULL)
	{
		counter = 0;
		while (counter++,*(token+counter) != '\0' ) {

		}
		counts[counter][0]++;

		token = strtok(NULL, " ");
	}

	for (size_t i = 1; i < INT_ARRAY_SIZE; i++)
	{
		printf("word length\tOccurences\n");
		printf("%d\t\t%d\n",i,counts[i][0]);
	}

}
