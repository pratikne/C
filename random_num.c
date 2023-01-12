#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int global_var = 20;

int main(){
    srand(time(NULL)); // seed provided 

    int num;
    for(int i = 1; i <=10; i++){
        num = (rand() % 10) + 1; //generates number between [1,10]
        printf("Random number %d is %d\n",i,num);
    }

    // Printing data without semicolon(;)
    // To prnt %, use %%
    if(printf("Hello World!%%!\n")){}

    // Swapping number without temp/third
    int a = 10;
    int b = 20;
    
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("a = %d, b = %d\n",a,b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a = %d, b = %d\n",a,b);

    int global_var = 50; //local

    printf( "global var is %d\n", ::global_var ); //this prints global

    return 0;
}