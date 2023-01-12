// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>


void reverse(char* str){
    int len = strlen(str);
    //char* ans = (char*)malloc(len+1);
    int k=0;
    for(int i=0; i<=len/2 ; i++){
    	char temp = str[i];
    	str[i] = str[len-1-i];
    	str[len-1-i] = temp;
    // ans[k] = str[i];
    // k++;
    //printf("Hi");
    
    }
    //ans[len] = '\0';
    printf("[%s]",str);
    //return ans ;
}

int main() {
    // Write C code here
    
    char str[] = "Hello Pratik";
    //char* ans;
    reverse(str);
    
    // int len = strlen(str);
    // for(int i=0; i < len/2 ; i++){
    // 	char temp = str[i];
    // 	str[i] = str[len-1-i];
    // 	str[len-1-i] = temp;
    // }
    
    
    printf("[%s]",str);
    
    

    return 0;
}