#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
   char str[5][50], temp[50];
   printf("Enter 5 words: ");

   // Getting strings input
   for (int i = 0; i < 5; ++i) {
      fgets(str[i], sizeof(str[i]), stdin);
   }

   // storing strings in the lexicographical order
   for (int i = 0; i < 5; ++i) {
      for (int j = i + 1; j < 5; ++j) {

         // swapping strings if they are not in the lexicographical order
         if (strncmp(str[i], str[j], 50) > 0) {
            strncpy(temp, str[i], 50);
            strncpy(str[i], str[j], 50);
            strncpy(str[j], temp, 50);
         }
      }
   }

   printf("\nIn the lexicographical order: \n");
   for (int i = 0; i < 5; ++i) {
      fputs(str[i], stdout);
   }

   printf("PATH : %s\n"),getenv("PATH");
   printf("HOME : %s\n"),getenv("HOME");
   printf("ROOT : %s\n"),getenv("ROOT");

   return 0;
}
