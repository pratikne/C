// C program for writing
// struct to file

/**IMP
fopen() - create a new file or open a existing file
fclose() - close a file
getc() - reads a character from a file
putc() - writes a character to a file
fscanf() - reads a set of data from a file
fprintf() - writes a set of data to a file
getw() - reads a integer from a file
putw() - writes a integer to a file
fseek() - set the position to desire point
ftell() - gives current position in the file
rewind() - set the position to the beginning point
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
    FILE *outfile;
    FILE *infile;
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