// #include <stdio.h>
// #define SQUARE(a) (a)*(a)



// int main()
// {
//     printf("%d\n", SQUARE(4)); //16
//     int x = 3;
//     printf("%d\n", SQUARE(++x)); //25
//     int y = 3;
//     printf("%d\n", ++y * ++y); //25
// }

// #include <stdio.h>



// void func()
// {
// int a = 0;
// func(); //segmentation fault
// }



// int main()
// {
//     func();
//     printf("exit");
//     while(1){}
// }

#include <stdio.h>
func (unsigned long *abc)
{
*abc = 0xFF;
printf("%ld\n", *abc);
}



main()
{
int a;
int b = 10;
func((unsigned long *)&a);

printf("%d \n%d \n", b, a); // 10   -1
}