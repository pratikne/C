#include<stdio.h>
// #include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define KRESET  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main()
{
    int x = 10;
    int *p = NULL; //NULL Pointer

    int *q ;//Wild pointer (Uninitialized pointer, so pointing to any memory address since garbage value is stored)
    //pointer may be initialized to a non NULL garbage value that may not be a valid address

    void *r;//Void pointer - can contains any block address so called generic pointer type
    r = &x;
    q = (int*)r; //r is typecasted from void to int and stored in int pointer which can be accessed
    r = NULL;
    printf("%d\n",*q);

    //New block
    {
        int y = 20;
        q = &y;
        printf("%d\n",*q); //20
        printf("%d\n",q);  //6422004
        q = NULL; //to solve dangling error ..we can also make y as static variable 
    }
    int* arr = new int[10];
    delete[] arr;
    // Now arr is a dangling pointer too,
    arr = NULL; //not a dangling pointer now
    
    //The pointers pointing to a deallocated memory block are known as Dangling Pointers.
    //More info : https://www.scaler.com/topics/c/dangling-pointer-in-c/
    
    //y is destroyed as soon as above block is finished
    //q is still pointing to that same address where y was but that is not valid. hence called dangling 
    // q++;
    printf("%d\n",q); //6422004

    printf("%sred\n", KRED);
    printf("%sgreen\n", KGRN);
    printf("%syellow\n", KYEL);
    printf("%sblue\n", KBLU);
    printf("%smagenta\n", KMAG);
    printf("%scyan\n", KCYN);
    printf("%swhite\n", KWHT);
    printf("%snormal\n", KRESET);

    printf(KRED "red\n"     KRESET);
    printf(KGRN "green\n"   KRESET);
    printf(KYEL "yellow\n"  KRESET);
    printf(KBLU "blue\n"    KRESET);
    printf(KMAG "magenta\n" KRESET);
    printf(KCYN "cyan\n"    KRESET);
    printf(KWHT "white\n"   KRESET);

    srand(time(NULL));   // Initialization, should only be called once.
    int i = 0;
    for(i=0; i<10; i++){
        int r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
        r = (r%10) + 1   ;          //If random number needed to be between 1 and 10
        printf(KYEL "Number is %s%d\n" KRESET,KBLU,r);
    }

    free(p);
    free(q);
    free(r);
    return 0;
}
/**Output
 * red
green
yellow
blue
magenta
cyan
white
normal
red
green
yellow
blue
magenta
cyan
white
Number is 6
Number is 7
Number is 4
Number is 5
Number is 3
Number is 3
Number is 9
Number is 4
Number is 5
Number is 7
**/