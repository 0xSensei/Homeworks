
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

int minimum = INT_MAX;
int average = 0;
int maximum = INT_MIN;

void *avg(void *param); 
void *max(void *param); 
void *min(void *param); 

struct arguments {
	unsigned int size;
	int *array;
} args;

int main(int argc, char *argv[])
{
pthread_t tid[3];
pthread_attr_t attr[3];

if (argc <2 ) {
	fprintf(stderr,"provide numbers\n");
	return -1;
}

int *arr = malloc(sizeof(int) * argc);
for (size_t i = 1; i < argc; i++)
{
	arr[i-1] = atoi(argv[i]);
}


args.size = argc - 1;
args.array = arr;


pthread_attr_init(&attr);


// average
pthread_create(&tid[0],&attr,avg,(void *)&args);
pthread_join(tid[0],NULL);

// maximum
pthread_create(&tid[1],&attr,max,(void *)&args);
pthread_join(tid[1],NULL);

//minimum
pthread_create(&tid[2],&attr,min,(void *)&args);
pthread_join(tid[2],NULL);


printf("The Average is: %d\nThe Maximum is: %d\nThe Minimum is: %d", average,maximum,minimum);

}


void *avg(void *param) 
{
   int total = 0;
   for (size_t i = 0; i < args.size; i++)
   {
	   total += args.array[i];
   }
   average = (total/args.size);
   

	pthread_exit(0);
}

void *max(void *param){
	
	
   for (size_t i = 0; i < args.size; i++)
   {
	   if(args.array[i] > maximum){
	   		maximum = args.array[i];

   		}
   }
   
		pthread_exit(0);

}


void *min(void *param){

for (size_t i = 0; i < args.size; i++)
   {
	   if(args.array[i] < minimum){
	   		minimum = args.array[i];
   		}

   }
   
	pthread_exit(0);
}
