// C program for writing
// struct to file

/**IMP
fopen() - create a new file or open a existing file
fclose() - close a file
getc() - reads a character from a file
putc() - writes a character to a file
fscanf() - reads a set of data from a file
fgets() - reads a string from a file or stdin
fprintf() - writes a set of data to a file
getw() - reads a integer from a file
putw() - writes a integer to a file
fseek() - set the position to desire point
ftell() - gives current position in the file
rewind() - set the position to the beginning point

-------------------------------------------

scanf("%d",&a) //use to read formatted input from console/stdin
fscanf(file_ptr, "%s %s", buffer) //reads input from file  

int return = rename(old_file, new_file)
if(return == 0)
    successfull
else
    not successfull


gets(buffer) //depreciated in C now as non-safe
fgets(buffer, size(buffer), stdin)

puts(buffer) //prints buffer to stdout console and appends \n by itself
fputs(buffer, stdout) //this can print to file or stdout but doesnt appends \n by itself


printf("%s.%d", str, i) //formats and prints to STDOUT
fprintf(file_ptr, "%s.%d\n", str, i) //use to print the string content i file but not on stdout console
sprintf(buffer, "%s.%d\n", str, i) //use to store in buffer and not print it to file and stdout

int return = fseek(file_pointer, offset, whence) //sets file at specific position
lseek() --> same as fseek but is a linux system call
fseek() is just a wrapper for lseek Linux
seekg is same but for C++ streams

rewind(file_pointer) //set the position of a file_pointer to the beginning of a file

getc return EOF after last char in file

int c = getc(fp); //reads single char from input and returns int value, if fails..returns EOF

while(c != EOF){
    putc(c);
    c = getc(fp);
}
fclose(fp);

if( feof(fp) ){
    fclose(fp);
}

long num = ftell(fp); // finds out the position of fp wrt start

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a struct to read and write
// For avoiding structure padding, use pragme push and pop
#pragma pack(push,1)
struct person
{
    int id;
    char fname[20];
    char lname[20];
}person;
#pragma pack(pop)

int main()
{
    FILE* outfile;
    FILE* infile;
    int n, i=0;

    // open file for writing
    outfile = fopen("person.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit(1);
    }

    printf("Enter the number of records you want to enter: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of employee %d \n", i + 1);

        fflush(stdin); //flushes the input if anything present in buffer

        printf("ID: ");
        scanf("%d",&person.id);

        printf("First Name: ");
        gets(person.fname);

        printf("Last Name: ");
        gets(person.lname);

        // size_t fwrite(const void *__restrict__ _Str, size_t _Size, size_t _Count, FILE *__restrict__ _File)
        int chars = fwrite(&person, sizeof(person), 1, outfile);
        printf("Number of items written to the file: %d\n", chars);
    }
    typedef struct person          person;
    person input1 = {1, "rohan", "sharma"};
    person input2 = {2, "mahendra", "dhoni"};

    //write struct to file
    //size_t fwrite(const void *__restrict__ _Str, size_t _Size, size_t _Count, FILE *__restrict__ _File)
    fwrite(&input1, sizeof(person), 1, outfile);
    fwrite(&input2, sizeof(person), 1, outfile);

    if (fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
    
    fclose(outfile);

    infile = fopen("person.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit(1);
    }
    //typedef struct person          person;
    person input;

    fseek(infile, 0, SEEK_SET); // Moving pointer to start
    printf("Position at start [%ld]\n", ftell(infile));
    // fseek(infile, 0, SEEK_END); // Moving pointer to end
    // printf("Position at end[%ld]\n", ftell(infile));
    printf("Size of a record [%ld]\n", sizeof(person));
    fseek(infile, sizeof(person), SEEK_CUR); // Moving pointer to CUR set at 2nd argument
    printf("Position at cur [%ld]\n", ftell(infile));

    //size_t fread(void *__restrict__ _DstBuf, size_t _ElementSize, size_t _Count, FILE *__restrict__ _File)
    while(fread(&input, sizeof(person), 1, infile))
        printf ("id = %d name = %s %s\n", input.id, input.fname, input.lname);
    
    if (feof(infile)) {
        printf("Done!\n");
    }
    // close file

    
    fclose(infile);

    return 0;
}