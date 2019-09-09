#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define SIZE 25
#define Threadhold 10

// struct to hold invetory records

void listIOC();
void scan(const char* filename);
int parseLine(char* line);
// list taken from these reports
// https://www.fireeye.com/content/dam/fireeye-www/global/en/current-threats/pdfs/rpt-top-spear-phishing-words.pdf
// https://www.zdnet.com/article/these-are-the-12-most-common-phishing-email-subject-lines-cyber-criminals-use-to-fool-you/


const char* IOC[SIZE] ={
	// 5 of common words
	"free",
	"cuopon",
	"click",
	"shipping",
	"invoice",
	// 5 of common url misquarding
	"-com",
	".xyz",
	"no-ip",
	"apple-",
	"gmail-",
	// 5 of common file extensions
	".exe",
	".zip",
	".pif",
	".scr",
	".bat",
	// 5 of common phrases in phishing
	"Your Password Expires in Less Than 24 Hours",
	"Please Read Important from Human Resources",
	"A Delivery Attempt was made",
	"Change of Password Required Immediately",
	"Email Account Updates",
	// 5 common company names
	"apple",
	"google",
	"hotmail",
	"dhl",
	"ups"
};

int scores[SIZE] = {
	1,1,2,2,4,
	5,2,2,5,5,
	5,3,5,5,5,
	5,2,3,5,5,
	1,1,1,1,1
};

int score = 0;

/*
Write a program that scans a file of text for these terms and phrases. For each occurrence of
a keyword or phrase within the text file, add the assigned point value to the total points for that
word or phrase. For each keyword or phrase found, output one line with the word or phrase, the
number of occurrences and the point total. Then show the point total for the entire message. Does
your program assign a high point total to some actual phishing e-mails you’ve received? Does it
assign a high point total to some legitimate e-mails you’ve received?
*/

int main(void) {
	
	printf("Welcome to Az phishing scanner, Enter your choice:\n1- List IOC\n2- Scan File\n3- exit\n");
	unsigned int choice = 0;
	scanf("%d", &choice);
	while (choice != 3)
	{
		switch (choice) {
		case 1: // new Record
			listIOC();
			break;
		case 2:// update Record
			char file_path[100];
			puts("enter the file name");
			scanf("%s", file_path);
			scan(file_path);
			break;
		default: // wrong input
			printf("Wrong input\n");
		}
		
		printf("Welcome to Az phishing scanner, Enter your choice:\n1- List IOC\n2- Scan File\n3- exit\n");
		scanf("%d", &choice);
	}

	
	
}

void listIOC() {
	for (size_t i = 0; i < SIZE; i++)
	{
		printf("The IOC: %s weight: %d\n", IOC[i], scores[i]);

	}
}
void scan(const char* filename) {

	FILE * fptr;
	int score = 0;
	int line = 0;

	fptr = fopen(filename, "r");
	if (fptr == NULL) {
		puts("couldnt open the file");
		return;
	}
		
	char buffer[200] = { 0 };
	puts("opened the file");

	while (fgets(buffer, 200, fptr))
	{
		
		if (buffer){
			printf("Parsing line %d\n", line++);
			score += parseLine(buffer);

		}

	}
	printf("Finished Parsing the file.\nthe score is %d.\nThe file is %s\n", score, score >= Threadhold ? "Malicious" : "Benign");


}

int parseLine(char* line) {
	int score = 0;
	for (size_t i = 0; i < SIZE; i++)
	{
		char* str_ = strstr(line, IOC[i]);
		while (str_) {
			printf("Found IOC!! IOC Name %s. and the weight is %d\n", IOC[i], scores[i]);
			score += scores[i];
			str_ = strstr(str_ + strlen(IOC[i]), IOC[i]); // Move into the Next IOC
		}

	}

	return score;
}
