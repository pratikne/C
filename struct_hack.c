#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{
    int id;
    int name_len;
    char name[0];
};

int main(){
printf("size is [%d]",sizeof(struct employee));
printf("size is [%d]",sizeof(struct employee*));

struct employee* e1 = (struct employee*) malloc(sizeof(*e1) + sizeof(char) * 1024);
printf("size is [%d]",sizeof(e1));
e1->id = 10;
e1->name_len = 20;
strncpy(e1->name,"Pratik Negi",e1->name_len);

printf("name is [%s]",e1->name);

return 0;
}