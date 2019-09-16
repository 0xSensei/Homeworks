#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

unsigned int prime;

void *runner(void *param); 


int main(int argc, char *argv[])
{
pthread_t tid;
pthread_attr_t attr; 

puts("Please enter a number.");
scanf("%u", &prime);


pthread_attr_init(&attr);
pthread_create(&tid,&attr,runner,NULL);
pthread_join(tid,NULL);

}

int isPrime(int number){
    int i;

    for(i=3; i< number; i++){
        if(number % i == 0){
            return 0;
    	}
	}
    return number;

}

void *runner(void *param){
printf("Prime :%d\n", 2);
for (size_t i = 3; i <= prime; i++)
{
	if(isPrime(i))
		printf("Prime :%d\n", i);

}
pthread_exit(0);
}

