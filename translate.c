#include "stdlib.h"
#include "stdio.h"
#include "string.h"


#define SIZE 10

void TranslateFromSMS(char* dest, char* src);
void TranslateToSMS(char* dest, char* src);




const char* abb[SIZE] = {
	"AFK",
	"IMO",
	"FISH",
	"BRB",
	"FBI",
	"GG",
	"BG",
	"OMG",
	"OMW",
	"KILL"

};

const char* real[SIZE] = {
	"Away From Keyboard",
	"In My Opinion",
	"First In, Still Here",
	"Be Right Back",
	"Fedral investigation inteliangnce",
	"Good Game",
	"Bad Game",
	"Oh My GOD",
	"Om My Way",
	"COPS!!"

};

int compare(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}

int main(void) {


	int choice = 0;
	char newline = 0;

	puts("Please enter a choice: \n1: sms to natural \n2: natural to sms ");
	// scanf("%d", &choice);
	char Dest[1000] = { 0 };

	scanf("%d", &choice);
	getc(stdin);
	char sms_language[170] = { 0 };
	char natural_language[300] = { 0 };
	switch (choice)
	{
	case 1: // parse SMS language

		puts("Enter your sms message");
		
		fgets(sms_language, 170, stdin);
		TranslateFromSMS(Dest, sms_language);
		printf("%s", Dest);
		break;
	case 2: // parse Natural Language

		puts("Enter your natural message");
		
		fgets(natural_language, 299, stdin);

		TranslateToSMS(Dest, natural_language);
		printf("%s", Dest);
		break;
	default:
		break;
	}


}


void TranslateFromSMS(char* dest, char* src) {


	char *need_to_edit = NULL;
	int counter = 1;
	char * token = strtok(src, " ");

	while (token != NULL) {

		printf("the token is :%s\n", token);
		for (size_t i = 0; i < SIZE; i++)
		{
			if (!strcmp(token, abb[i])) {
				strcat(dest, real[i]);
				counter = 0;
				break;
			}

		}
		if (counter) {
			strcat(dest, token);
		}
		counter = 1;
		strcat(dest, " ");


		token = strtok(NULL, " ");
	}

	puts(" ");


}
void TranslateToSMS(char* dest, char* src) {
	// cut string for

	// parse text and find the index's of want to be changed words into an array
	// loop indexs and place the abb, 
	//int indexs[SIZE] = { 900 ,900 ,900 ,900 ,900 ,900 ,900 ,900 ,900 ,900 };
	
	for (size_t i = 0; i < SIZE; i++)
	{
		int counter = 0;
		char * str_ = strstr(src+counter, real[i]);
		while (str_)
		{	// Away From Keyboard In My Opinion kk what is wrong Oh My GOD ->  \0way From Keyboard \0n My Opinion kk what is wrong \0h My GOD 
			char tmp = *str_;
			*str_ = '\0';
			strcat(dest, src);
			strcat(dest, abb[i]);
			
			*str_ = tmp;
			counter = ( str_ -src) + strlen(real[i]);
			strcat(dest, src + counter);
			strcpy(src, dest);
			memset(dest, 0, 300);
			str_ = strstr(src+counter, real[i]);
		}
		
	}
	
	
	strcpy(dest, src);
	puts(" ");



}
