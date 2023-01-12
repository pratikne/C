// Function pointers - used for callback (function passed into another function as an argument
// which is then invoked inside the outer function to complete one kind of routine or action)

// Name of the function gives its memory address just like array
#include <stdio.h>

// Syntax:
// return_type (*ptr_name)(parameter list) = actual_function
// ptr_name(parameters) same as actual_function(parameters)

//void (*p)(int)
void show(int x){
    printf("Value of x is %d\n",x);
}

float add(int a, int b){
    return a + b;
}
float subtract(int a, int b){
    return a - b;
}
float multiply(int a, int b){
    return a * b;
}
float divide(int a, int b){
    return (float)a / b;
}


/**CAllback example B calling A*/
void A(int a){
    printf("I am function - %d\n",a);
}

void B(void (*ptr)(int), int a){
    (*ptr)(a); //callback to A
    ptr(a); //same as above
    printf("CAllback finished\n");
}

int main(){
    //1st
    printf("Address of function : %p\n", show);

    //Syntax of FP
    void (*p)(int);
    p = &show;
    (*p)(9);

    //2nd
    void (*q)(int);
    q = show;
    q(10);

    //3rd
    show(11);

    //void (*x)() = &A;
    B(A, 10); //B callbacking A with parameters


    //Array of FP
    float (*op[4])(int,int);
    op[0] = add;
    op[1] = subtract;
    op[2] = multiply;
    op[3] = divide;

    int a = 10;
    int b = 5;
    float result;

    result = op[0](a,b);
    printf("Addition result of 10 and 5 is %.1f\n",result);

    result = op[1](a,b);
    printf("Subtract result of 10 and 5 is %.1f\n",result);

    result = op[2](a,b);
    printf("Multiply result of 10 and 5 is %.1f\n",result);

    result = op[3](a,b);
    printf("Divide result of 10 and 5 is %.1f\n",result);

    return 0;
}

/***OUTPUT
 * 
Address of function : 0000000000401550
Value of x is 9
Value of x is 10
Value of x is 11
Addition result of 10 and 5 is 15.0
Subtract result of 10 and 5 is 5.0
Multiply result of 10 and 5 is 50.0
Divide result of 10 and 5 is 2.0
***/