// C program to Open a File,
// Write in it, And Close the File

#include <stdio.h>
#include <string.h>

int main()
{

    // Declare the file pointer
    FILE* filePointer;

    // Get the data to be written in file
    char dataToBeWritten[50] = "GeeksforGeeks-A Computer Science Portal for Geeks";
    char dataToBeRead[50];

    // Open the existing file GfgTest.c using fopen()
    // in write mode using "w" attribute
    filePointer = fopen("Hiscore.txt", "rw");

    // Check if this filePointer is null
    // which maybe if the file does not exist
    if (filePointer == NULL)
    {
        printf("Hiscore.txt file failed to open.");
    }
    else
    {

        printf("The file is now opened.\n");
        while (fgets(dataToBeRead,sizeof(dataToBeRead), filePointer) != NULL)
        {

            // Print the dataToBeRead
            printf("%s", dataToBeRead);
        }
        
        // Write the dataToBeWritten into the file
        if (strlen(dataToBeWritten) > 0)
        {

            // writing in the file using fputs()
            // fputs(dataToBeWritten, filePointer) ;
            // fputs("\n", filePointer) ;
            fprintf(filePointer, "%s\n", dataToBeWritten);
        }

        // Closing the file using fclose()
        fclose(filePointer);

        printf("Data successfully written in file Hiscore.txt\n");
        printf("The file is now closed.");
    }
    return 0;
}