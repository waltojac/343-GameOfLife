//
// Created by Jacob Walton on 1/29/18.
//

#include "file_utilities.h"
#include <stdlib.h>
#include <stdio.h>


int read_file( char* filename, char **buffer ){
    FILE *input = fopen(filename, "rb");

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

    return 0;

}
int write_file( char* filename, char *buffer, int size){

    //open the output file
    FILE *output = fopen(filename, "w");

    //print the buffer array to the output file
    fputs(buffer, output);

    //close the output file
    fclose(output);

}