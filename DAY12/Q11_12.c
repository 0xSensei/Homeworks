#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define SIZE 100

// struct to hold invetory records
struct inventory {
	unsigned int recordID;
	char toolName[100];
	unsigned short quantity;
	double cost;
};

// prototypes
void init(const char* filename);
void newRecord(FILE *fptr);
void deleteRecord(FILE *fptr);
void updateRecord(FILE *fptr);
void printRecord(struct inventory* record);
void printAllRecord(FILE *fptr);



int main(void) {
	const char* filename = "hardware.dat";
	init(filename);

	FILE *fptr = fopen(filename, "rb+");

	printf("Welcome to Azoz Store, Enter your choice:\n1- new Record\n2- update Record\n3- delete Record\n4- print all availabe records\n5- exit\n");
	unsigned int choice = 0;
	scanf("%d", &choice);
	while (choice != 5)
	{
		switch (choice) {
		case 1: // new Record
			newRecord(fptr);
			break;
		case 2:// update Record
			updateRecord(fptr);
			break;
		case 3:// delete Record
			deleteRecord(fptr);
			break;
		case 4: // print All record
			printAllRecord(fptr);
			break;
		case 5: // exit
			fclose(fptr);
			break;
		default: // wrong input
			printf("Wrong input\n");
		}
		
		printf("Welcome to Azoz Store, Enter your choice:\n1- new Record\n2- update Record\n3- delete Record\n4- print all availabe records\n5- exit\n");
		scanf("%d", &choice);
	}


}


void init(const char* filename) {
	FILE* fptr = NULL;
	fptr = fopen("hardware.dat", "wb");
	if (fptr == NULL) {
		printf("Couldnt open the file to write");
		exit(1);
	}
	struct inventory inv = { 0,"",0,0.0 };
	for (size_t i = 0; i < SIZE; i++)
	{
		fwrite(&inv, sizeof inventory, 1, fptr);
	}
	
	fclose(fptr);

}

void newRecord(FILE *fptr) {
	printf("Please Enter a number between 1-100 for RecordID\n");
	unsigned int RecordID = 0;
	scanf("%d", &RecordID);
	// handle Error case
	if (RecordID < 1 && RecordID >100) {
		printf("Wrong!!");
		return;
	}
	// sizeof inventory * RecordID -1
	fseek(fptr, sizeof inventory * (RecordID -1) , SEEK_SET);
	struct inventory tmp;
	fread(&tmp, sizeof inventory, 1, fptr);
	if (tmp.recordID != 0) {
		printf("Already Created with id %d\n", tmp.recordID);
		return;
	}

	puts("Enter Tool name");
	scanf("%s", tmp.toolName);
	puts("Enter Tool quantity");
	scanf("%hu", &tmp.quantity);
	puts("Enter Tool cost");
	scanf("%lf", &tmp.cost);
	tmp.recordID = RecordID;
	fseek(fptr, sizeof inventory * (RecordID - 1), SEEK_SET);

	fwrite(&tmp, sizeof inventory, 1, fptr);

	puts("Done!");
	return;



}

void deleteRecord(FILE *fptr){
	printf("Please Enter a number between 1-100 for RecordID\n");
	unsigned int RecordID = 0;
	scanf("%d", &RecordID);
	// handle Error case
	if (RecordID < 1 && RecordID >100) {
		printf("Wrong!!");
		return;
	}
	// sizeof inventory * RecordID -1
	fseek(fptr, sizeof inventory * (RecordID - 1), SEEK_SET);
	struct inventory tmp;
	fread(&tmp, sizeof inventory, 1, fptr);
	if (tmp.recordID == 0) {
		printf("Cant delete non created Records\n");
		return;
	}
	tmp.recordID = 0;
	tmp.cost = 0.0;
	memset(&tmp.toolName, 0, 100);
	tmp.quantity = 0;
	fseek(fptr, sizeof inventory * (RecordID - 1), SEEK_SET);

	fwrite(&tmp, sizeof inventory, 1, fptr);

	puts("Done!");
	return;
}

void updateRecord(FILE *fptr){
	printf("Please Enter a number between 1-100 for RecordID\n");
	unsigned int RecordID = 0;
	scanf("%d", &RecordID);
	// handle Error case
	if (RecordID < 1 && RecordID >100) {
		printf("Wrong!!");
		return;
	}
	// sizeof inventory * RecordID -1
	fseek(fptr, sizeof inventory * (RecordID - 1), SEEK_SET);
	struct inventory tmp;
	fread(&tmp, sizeof inventory, 1, fptr);
	if (tmp.recordID == 0) {
		printf("Create it first !\n");
		return;
	}
	printRecord(&tmp);
	puts("Enter Tool name");
	scanf("%s", tmp.toolName);
	puts("Enter Tool quantity");
	scanf("%hu", &tmp.quantity);
	puts("Enter Tool cost");
	scanf("%lf", &tmp.cost);

	fseek(fptr, sizeof inventory * (RecordID - 1), SEEK_SET);

	fwrite(&tmp, sizeof inventory, 1, fptr);

	puts("Done!");
	return;


}

void printRecord(struct inventory* record){

	printf("Tool Details are as follows:\n");
	printf("Tool ID: %u\n", record->recordID);
	printf("Tool Name %s\n", record->toolName);
	printf("Tool Quantity %hu\n", record->quantity);
	printf("Tool Cost %lf\n", record->cost);


}

void printAllRecord(FILE *fptr) {


	struct inventory tmp;
	for (size_t i = 0; i < SIZE; i++)
	{
		fseek(fptr, sizeof(inventory) * i, SEEK_SET);
		fread(&tmp, sizeof inventory, 1, fptr);
		if(tmp.recordID != 0)
			printRecord(&tmp);
		memset(&tmp, 0, sizeof inventory);
	}
}
