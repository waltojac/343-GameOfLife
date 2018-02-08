#include <stdio.h>
#include "file_utilities.h"
#include <stdlib.h>
#include <string.h>

//function declarations
int populateBoard(char *** arr, int height, int width);
int freeBoard(char *** arr, int height, int width);
int allocateBoard(char *** arr, int height, int width);
int printBoard(char ** board, int height, int width);
int writeBoard(char *** board, int height, int width);
int loadBoard(char* filename, char *** board, int * height, int * width);
int runGeneration(char *** board, int height, int width, int itr);

int main(int argc, char * argv[]) {

    //game board dimensions
    int width = 0, height = 0;
    char ** board;

    //allocateBoard(&board, height, width);


    //loadBoard
    loadBoard("test.txt", &board, &height, &width);

    printf("Height: %d, Width: %d\n\n", height, width);

    //freeBoard(&board, height, width);

    runGeneration(&board, height, width, 3);



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

}



int runGeneration(char *** board, int height, int width, int itr){
    //create copy board
    char ** copy;
    copyBoard(board, &copy, height, width);


    printf("\n");
    //print board
    printBoard(copy,height,width);
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


/*
void testing(char ** board, int height, int width){
    //grab user input
    printf("\nEnter height: ");
    scanf("%d", &height);
    printf("\nEnter width: ");
    scanf("%d", &width);

    //allocate the board
    allocateBoard(&board, height, width);

    //populateBoard
    populateBoard(&board,height,width);

    //print board
    printBoard(board, height, width);

    //write board
    writeBoard(&board, height, width);

    freeBoard(&board, height, width);
}
*/

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
int writeBoard(char *** board, int height, int width) {

    int count = 0;
    char h;
    char w;

    char *buffer = (char *) malloc(sizeof(char)*height*width+2);

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

    write_file("test.txt", buffer, height);
    return 0;
}


int loadBoard(char* filename, char *** board, int * height, int * width){
    FILE * fp = fopen(filename,"r");
    int count = 3;

    char *buffer;

    read_file(filename, &buffer);

    *height = buffer[0];
    *width = buffer[1];

    allocateBoard(board, *height, *width);

    for(int i = 0; i < *height; i++){
        for(int j = 0; j < *width; j++){
            (*board)[i][j] = buffer[count];
            count++;
        }
        count++;
    }

    printBoard(*board, *height, *width);

    return 0;

}