#include <unistd.h> /*fork declared here*/
#include <stdio.h> /* printf declared here*/
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(void){

    const int SIZE = 4096;
	const char *name = "HomeWork";


	int shm_fd;
	int *ptr;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd,SIZE);
	ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
   
	if (ptr == MAP_FAILED) {
		printf("Map failed\n");
		return -1;
	}

   int number = 0;
   puts("Please enter a number");
   scanf("%d", &number);

   if(number <= 0)
      exit(1);

   __pid_t id;
   int status;
   id = fork();

   if(id == 0){
      // child 
      int counter =0;

      for (; number!= 1;)
      {
         *(ptr+counter++) = number;
         if(number & 1){
         // ODD
         number = 3 * number + 1;

         }else{
            number = number/2;
         }
      }
         *(ptr+counter++) = number;

      

   }else{
      //parent

   waitpid(id,&status,0);
   for (; *ptr; ptr++)
   {
      printf("%d ", *ptr);
   }
   

   }
  
}
