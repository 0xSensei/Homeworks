// ex07_20.c
 // what does this program do?
#include "pch.h"
#include <stdio.h>
#include "math.h"
// prototypes
void circumference_of_a_circle(double);
void are_of_cirecle(double);
void volume_of_sphere(double);



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

int main(void)
{
	int choice = 0;
	double input = 0;
	void (*functions[3])(double) = { circumference_of_a_circle,are_of_cirecle,volume_of_sphere };

	while (choice != -1)
	{
		puts("Please Make a choice (-1 to quit)");
		printf("1-circumference of a circle (2 * PI * user input (double))\n2 - the area of a circle(PI * user_iput ^ 2)\n3 - volume of a sphere(4 / 3 * PI * r ^ 3)\n");
		
		scanf("%d", &choice);
		getc(stdin); // to clear the \n

		

		if (choice >= 1 && choice <= 3) {
			puts("Enter an input (double)");
			scanf("%lf", &input);
			(*functions[choice-1])(input);
		}
		else {
			puts("Please input a correct choice");
		}
	}
	
	puts("Bye :).");
	
}


void circumference_of_a_circle(double radius) {
	//(2 * PI * user input (double))
	double formula = (double)2 * 3.14 * radius;
	printf("%lf\n", formula);
}
void are_of_cirecle(double radius) {
	// (PI * user_iput^2)
	double formula = 3.14 * (pow(radius,2));
	printf("%lf\n", formula);

}
void volume_of_sphere(double radius) {
	//(4/3 * PI * r^3)
	double formula = ((double) 4/3) * 3.14 * (pow(radius, 3));
	printf("%lf\n", formula);

}
