#include <stdio.h>
#include <string.h>
// #define PRINT(i, limit) do \
//                         { \
//                             if (i++ < limit) \
//                             { \
//                                 printf("GeeksQuiz\n"); \
//                                 continue; \
//                             } \
//                         }while(1)
// int main()
// {
//     PRINT(0, 3);
//     return 0;
// }

// can't increment i at left end;
// lvalue required 
// int main(){
//     char p[20];
//     char *s = "string";
//     int length = strlen(s);
//     int i;

//     for (i = 0; i < length; i++){
//         p[i] = s[length — i];
//     }

//     printf("%s", p);
// }

// int main()
// {
//     static int i=5;
//     if(--i){
//         main();
//         printf("%d ",i);
//     }
// }
// 0 0 0 0



// struct grade
// {
//      int alpha:3;
//       int beta:3;
//       int gama:2;
// };



// int main()
// {
//       struct grade g1={2,-6,5};
//       printf("%d %d %d",g1.alpha,g1.beta,g1.gama);
//       return 0;
// }

// #define concatenate(a,b) a##b
// #define same1(a)  #a
// #define same2(a) same1(a)
// int main()
// {
//     printf("%s\n",same2(concatenate(1,2)));
//     return 0;
// }

//12

// int main()
// {
//       int a=10,*j;
//       void *k;
//       k=&a;
//       j=&a;
//       k++;
//       j++;
//       printf("\n %u", a);
//       return 0;
// }

// 10
// 10

struct Foo
{
char x; //8
int* z; //8
char y; //8
};

struct Foo1
{
char x; //8
double z; //8
int y; //8
};

int main()
{
    // int a[][3] = {1, 2, 3, 4, 5, 6};
    // int (*ptr)[3] = a;
    // printf("%d %d ", (*ptr)[0], (*ptr)[2]);
    // ++ptr;
    // printf("%d %d\n", (*ptr)[1], (*ptr)[2]);

    int test[5] = {2};
    
    printf("%d\n",test[2]); // 0
    printf("Hello World %ld\n" , sizeof('a')); //1
    printf("%d\n",sizeof(struct Foo)); // 24
    printf("%d\n",sizeof(struct Foo1)); // 24

    char str[] = "November";
    printf("Length of String is %lu\n", strlen(str)); //8
    printf("Size of String is %lu\n", sizeof(str)); //9 

    char a = 0xFF; // 1111 1111
    char b = 0x0F; // 0000 1111
    
    char c = a & b; // 0000 1111 
    char d = a && b; // 1
    char f = ~b; // 1111 0000
    char g = !b; // 0
    
    printf ("%x %x %x %x ", c , d , f , g  ); // f 1 fffffff0 0

    

    return 0;
}