#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int max(int num_args, ...){

    va_list args;
    va_start(args, num_args);

    int maxel = INT_MIN;

    for(int i=0; i < num_args; i++){
        int x= va_arg(args, int);
        printf("x: %d\n",x);

        if(x > maxel){
            maxel = x;
        }
    }

    va_end(args);
    return maxel;
}

int main(){
    int maxel = max(4,10,11,12,13); //1st arg 4 is the total arguments i will be passing that is 4 (10,11,12,13)
    printf("Max : %d\n", maxel);

    int arr = 10;
    void* v = &arr;
    int* i = &arr;
    printf("Address : %p\n", v);
    printf("Address : %p\n", &arr);
    v++; // moves ahead 1 byte
    printf("Address : %p\n", v);
    printf("Address : %p\n", &arr);
    i++; //moves ahead by type size
    printf("Address : %p\n", v);
    printf("Address : %p\n", &arr);
    printf("Address : %p\n", i);
    printf("value : %d\n", *i); //garbage value
    printf("value : %d\n", arr); // 10

    
    return 0;
}
