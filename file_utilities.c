//
// Created by Jacob Walton on 1/29/18.
//

#include "file_utilities.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/*
 * Function to read filename text into buffer.
 *
 * Returns 0 on success, and errno on error.
 */
int read_file( char* filename, char **buffer ){
    FILE *input = fopen(filename, "rb");

    if (input != NULL) {
        //grabs the file size in bytes
        //snippet found on https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c by Rob Walker
        fseek(input, 0, SEEK_END);
        long fsize = ftell(input);
        fseek(input, 0, SEEK_SET);

        //allocates the memory for the buffer array
        *buffer = (char *)malloc((fsize+1L)*sizeof(char));

        //show the filesize
        printf("Filesize: %ld\n", fsize);

        //reads the file into buffer
        fread(*buffer, sizeof(char), (size_t)fsize, input);

        //close file
        fclose(input);

    }else{
        fprintf(stderr,"Error on file open: %d", errno);
        return errno;
    }

    return 0;
}

/*
 * Function to write buffer string to filename file.
 *
 * Returns 0 on success, and errno on error.
 */
int write_file( char* filename, char *buffer, int size){

    //open the output file
    FILE *output = fopen(filename, "w");

    if (output != NULL)
    {
        //print the buffer array to the output file
        fputs(buffer, output);

        printf("\nFile written successfully.\n");

        //close the output file
        fclose(output);
    }else{
        fprintf(stderr,"Error on file write: %d", errno);
        return errno;
    }

    return 0;
}