#include "stdlib.h"
#include "stdio.h"
#include "string.h"


#define SIZE 10

void TranslateFromSMS(char* dest, char* src);
void TranslateToSMS(char* dest,char* src);




char* abb[] = {
    "AFK",
    "IMO",
    "FISH",
    "BRB",
    "IMO",
    "GG",
    "BG",
    "OMG",
    "OMW",
    "IMO"

};

char* real[] ={
    "Away From Keyboard",
    "In My Opinion",
    "First In, Still Here",
    "Be Right Back",
    "In My Opinion",
    "Good Game",
    "Bad Game",
    "Oh My GOD",
    "Om My Way",
    "In My Op"

};



int main(void){


    int choice = 0;
    char newline =0;  

    puts("Please enter a choice: 1 -> sms to natural, 2: natural to sms ");
    // scanf("%d", &choice);
    char Dest[1000] ={0};

    scanf("%d", &choice);
    getc(stdin);

    switch (choice)
    {
    case 1: // parse SMS language
        
        puts("Enter your sms message");
        char sms_language[170] = {0};
        fgets(sms_language,170,stdin);
        TranslateFromSMS(Dest, sms_language);

        break;
    case 2: // parse Natural Language
    
        puts("Enter your natural message");
        char natural_language[300] = {0};
        scanf("%299s", natural_language);
        TranslateToSMS(Dest, natural_language);
        break;
    default:
        break;
    }


}


void TranslateFromSMS(char* dest, char* src){

   
    char *need_to_edit = NULL;
    int counter = 1;
    char * token = strtok(src," ");

    while(token != NULL){

        printf("the token is :%s\n", token);
        for (size_t i = 0; i < SIZE; i++)
        {
            if(!strcmp(token,abb[i])){
                    strcat(dest,real[i]);
                    counter = 0;
                    break;
            }
            
        }
        if(counter){
            strcat(dest,token);
        }
        counter =1;
        strcat(dest," ");
        

        token = strtok(NULL," ");
    }

    puts(" ");
    printf("%s", dest);
    

}
void TranslateToSMS(char* dest,char* src){

    printf("%s", dest);
    printf("%s", src);          


}
