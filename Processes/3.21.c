#include <unistd.h> /*fork declared here*/
#include <stdio.h> /* printf declared here*/


int main(void){

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
      for (; number!= 1;)
      {
         printf("%d ", number);
         if(number & 1){
         // ODD
         number = 3 * number + 1;

         }else{
            number = number/2;
         }
      }
         printf("%d ", number);

      

   }else{
      //parent

   waitpid(id,&status,0);

   }
  



}
