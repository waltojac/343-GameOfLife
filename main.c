/*
 * Game of Life
 *
 * Author: Jacob Walton
 * Date: 2/8/2018
 * Description: Simulation of Conway's Game of Life. Uses a dynamically
 * allocated, 2D array to store the universe (board).
 *
 * Uses homemade file_utilities.c/.h files.
 */




#include <stdio.h>
#include "file_utilities.h"
#include <stdlib.h>
#include <string.h>

//function declarations
int populateBoard(char *** arr, int height, int width);
int freeBoard(char *** arr, int height, int width);
int allocateBoard(char *** arr, int height, int width);
int printBoard(char ** board, int height, int width);
int writeBoard(char * filename, char *** board, int height, int width);
int loadBoard(char* filename, char *** board, int * height, int * width);
int runGeneration(char *** board, int height, int width, int itr);
int copyBoard(char *** board, char *** copy, int height, int width);


int main(int argc, char * argv[]) {

    //game board dimensions
    int width = 0, height = 0;
    char ** board;
    int flag = 1;
    loadBoard("default.txt", &board, &height, &width);
    int valid = 1;

    int input = 0;
    while(flag){
        printf("\n-------------Enter you selection-------------\n");
        printf("1: Save        2: Load        3: Run 1 gen\n");
        printf("4: Run x gen   5: New Board   6: Quit\n");

        char * strNum = (char*)malloc(sizeof(char)*2);

        while(valid){
            scanf("%s", strNum);
            input = atoi(strNum);
            if ((input > 0) && input < 7){
                valid = 0;
                break;
            }
            fflush(stdin);
            printf("\nPlease enter a valid input.\n");
            printf("\n-------------Enter you selection-------------\n");
            printf("1: Save        2: Load        3: Run 1 gen\n");
            printf("4: Run x gen   5: New Board   6: Quit\n");
        }
        valid = 1;


        //temp input values
        char * str = (char*)malloc(sizeof(char)*20);
        int itr = 0;

        switch (input) {

            //write file
            case 1:
                printf("\nEnter filename: ");
                scanf("%s", str);
                writeBoard(str, &board, height, width);
                break;

            //load file
            case 2:
                printf("\nEnter filename: ");
                scanf("%s", str);
                loadBoard(str, &board, &height, &width);
                break;

            //run 1 generation
            case 3:
                runGeneration(&board, height, width, 1);
                break;

            //run x generations
            case 4:
                printf("\nEnter x: ");
                scanf("%d", &itr);
                runGeneration(&board, height, width, itr);
                break;

            //resize board
            case 5:
                printf("\nEnter height: ");
                scanf("%d", &height);
                printf("\nEnter width: ");
                scanf("%d", &width);
                allocateBoard(&board, height, width);
                populateBoard(&board, height, width);

                printf("\nNew Board Created.\n\n");
                printBoard(board, height, width);
                printf("\nPlease save now to keep board.\n");
                break;

            //quit
            case 6:
                freeBoard(&board, height, width);
                printf("\nQuitting...\n");
                free(str);
                free(strNum);
                flag = 0;
                break;

        }
    }

    return 0;
}

int copyBoard(char *** board, char *** copy, int height, int width){
    allocateBoard(copy, height, width);

    //copy board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            (*copy)[i][j] = (*board)[i][j];
        }
    }
    return 0;
}



int runGeneration(char *** board, int height, int width, int itr){
    //create copy board
    char ** copy;
    copyBoard(board, &copy, height, width);

    printf("\n");

    while(itr){
        //check each cell for number of live neighbors
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int numAliveNeighbors = 0;
                //check surrounding cells
                //found this loop pattern from https://www.geeksforgeeks.org/program-for-conways-game-of-life/
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        //my own logic to make sure in bounds of board
                        if(((i+x)>=0 && (i+x)<height) && (((j+y)>=0 && (j+y)<width))){
                            if (copy[i + x][j + y] == 'o') {
                                numAliveNeighbors++;
                            }
                        }
                    }
                }

                //remove inclusion of itself
                if (copy[i][j] == 'o') {
                    numAliveNeighbors--;
                }

                //rules for alive cell
                if (copy[i][j] == 'o') {

                    //underpopulation
                    if (numAliveNeighbors < 2) {
                        (*board)[i][j] = 'x';
                    }else if (numAliveNeighbors > 3) {                    //overpopulation

                        (*board)[i][j] = 'x';
                    }else{
                        //stay alive, do nothing
                    }
                }
                //rules for dead cell
                else if (copy[i][j] == 'x') {
                    if (numAliveNeighbors == 3){
                        (*board)[i][j] = 'o';
                    }
                }
            }
        }
        copyBoard(board, &copy, height, width);
        printBoard(copy,height,width);
        printf("\n");
        itr--;
    }
    freeBoard(&copy, height, width);
    return 0;
}


int populateBoard(char *** arr, int height, int width){
    //Add values to the board. Created on my own before seeing
    //geeksforgeeks website.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            (*arr)[i][j] = 'x';
        }
    }
    return 0;
}

/*
 * Function to free the board memory.
 */
int freeBoard(char *** arr, int height, int width){
    //free array
    //created on my own
    for (int i = 0; i < height; i++) {
        free((*arr)[i]);
    }
    free(*arr);
    return 0;
}

/*
 * Function to allocate the memory for the board.
 */
int allocateBoard(char *** arr, int height, int width){
    //Allocate board. Some help found from the following website.
    //I was missing the initial double pointer malloc.
    //https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
    *arr = (char**)malloc(sizeof(char*)*height);
    for (int i = 0; i < height; i++) {
        (*arr)[i] = (char*)malloc(sizeof(char) * width);
    }
    return 0;
}

/*
 * Function to print the game board.
 */
int printBoard(char ** board, int height, int width){
    //print board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    //added to stop error when large board printed
    fflush(stdout);
    return 0;
}

/*
 * Function that writes the board to the file.
 * Calls the write_file() function from file_utilities.h
 *
 * Returns 1 or 2 on game board to high or wide (256), respectively.
 */
int writeBoard(char * filename, char *** board, int height, int width) {

    int count = 0;
    char h;
    char w;

    //allocate input buffer
    char *buffer = (char *) malloc(sizeof(char)*height*width+2);

    //check for error due to size of char limitations when converting from ASCII to int
    //add height and width to array
    if (height < 256) {
        h = height;
    }
    else{
        printf("Game board must be less than 256 high.");
        return 1;
    }

    //add height to file
    buffer[count] = h;
    count++;

    //check for error due to size of char limitations when converting from ASCII to int
    if (width <256) {
        w = width;
    } else{
        printf("Game board must be less than 256 wide.");
        return 2;
    }

    //add width to file
    buffer[count] = w;
    count++;

    //newline
    buffer[count] = '\n';
    count++;

    //add board to array
    for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++) {
            buffer[count] = (*board)[i][j];
            count++;
        }
        buffer[count] = '\n';
        count++;
    }

    write_file(filename, buffer, height);
    free(buffer);
    return 0;
}


int loadBoard(char* filename, char *** board, int * height, int * width){
    int count = 3;
    int flag = 0;
    char *buffer;

    //read the file into buffer
    flag = read_file(filename, &buffer);

    //check for error on file read
    if (flag)
    {
        printf("\nFile %s not able to open.\n", filename);
        return 1;
    }

    //grab height and width from first 2 spots in input buffer.
    *height = buffer[0];
    *width = buffer[1];

    allocateBoard(board, *height, *width);

    //copy the buffer into the board.
    for(int i = 0; i < *height; i++){
        for(int j = 0; j < *width; j++){
            (*board)[i][j] = buffer[count];
            count++;
        }
        count++;
    }

    printBoard(*board, *height, *width);
    free(buffer);

    return 0;

}