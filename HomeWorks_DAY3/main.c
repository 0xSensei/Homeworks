
#include "stdio.h"

int my_ctoi(char c) { // Convert the ascii character to int

	// range the decmial in ascii
	// 48 = 0 -> 57 = 9   (c >=48) && (c<=57) --> return c - 30; 
	if (c >= '0' && c <= '9')
		return (int) c - '0';
	return -1;
}

// Test Cases
// 22 asdasd22 22asdasd asd22asd 2d2 asd2asd225asd 22asd2asd 22 = 22 + 22 = 44
// 55 asda5sd54asd a5s6d45a 4d5a5 55 4asd 15we 1sd5s 2 s22 sd4 21sd 51ds2  5sd1 = 55 + 55 + 2 = 112
// 12 9xy4 59   y5t  31 = 12 + 59 + 31 = 102 

int main(void*) {
	char Rchar = 0;
	int out_sum = 0;
	int inner_sum = 0; 
	int multiplier = 10;
	int flag = 0;
	
	// Read user input
	while (Rchar != EOF) {	// LOOP until encountring EOF
		Rchar = getchar();

		// Case decmial 
		while (my_ctoi(Rchar) != -1) { // loop numbers
			if (flag) { // check if their a previous number
				inner_sum = inner_sum * multiplier;
				inner_sum += my_ctoi(Rchar);
			}
			else {
				inner_sum = my_ctoi(Rchar);
				flag = 1; // to make sure to carry for next iteration
			}

			Rchar = getchar();

			if(my_ctoi(Rchar) == -1 && Rchar != ' ' && Rchar != 0x0a)	// Encountred string in mid deciaml parsing; ABORT.	ex: 55asd
				flag = inner_sum = 0;
		}
		out_sum += inner_sum;	// save the sum
		flag =  inner_sum = 0; // reset the flag

		// case non Decimal
		if (my_ctoi(Rchar) == -1)
			while (Rchar != ' ' && Rchar != EOF) Rchar = getchar();
		

	}

	printf("loop Sum : %d\n", out_sum);

}
