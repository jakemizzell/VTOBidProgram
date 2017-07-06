/**
 * main.c
 *
 * Written by Jake Mizzell
 *
 * This program figures out the remaining lines for the name given.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

void findRemaining (char *, FILE *);
int findBid(int *,FILE *);
int checkArray(int, int *);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Execute with \'bid.exe filename.txt\'\n");
        exit(1);
    }
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "File didn't open, check file name\n");
        exit(1);
    }
    char *name;
    //if (argv[2] == NULL)
        name = "MIZZELL,";
    //else
        //name = argv[2];
    fprintf(stdout, "\nCalculating remaining lines\n");
    findRemaining(name,fp);
    printf("\nProgram Finished!\n\n");
    fclose(fp);
    return 0;
}

void findRemaining(char *name, FILE *fp) {
    int array[100] = { 0 };
    char *str = readToken(fp);
    //loop to run until it finds the name you want
    while (strcmp(str,name) != 0) {
        //when it finds "CPT" because there are about to be the numbers
        if(strcmp(str, "CPT") == 0) {
           int bid = findBid(array,fp);
        }
        str = readToken(fp);
    }
    //Used for error checking
    /*printf("Array as is\n");
    for (int i = 1; i < 100; i++) {
        printf("%d:%d ",i,array[i]);
    }
    printf("\nRemaining slots\n");
    for (int i = 1; i < 100; i++) {
        if (array[i] == 0)
            printf("%d:%d ",i,array[i]);
    }
    printf("\n\n");*/
    //read the file through CPT
    str = readToken(fp);
    while (strcmp(str,"CPT") != 0)
        str = readToken(fp);
    //find the remaining slots
    printf("\nBids ");
    int i = readInt(fp);
    while (!feof(fp)) {
        int bid = findBid(array,fp);
        printf("%d ",bid);
        i = readInt(fp);
    }
    printf("are left for you!\n");
}

int findBid(int *array, FILE *fp) {
    int bid = readInt(fp);
    //printf("Looking at bid %d",bid);
    int avaliable = checkArray(bid,array);
    if (avaliable == 1)
        return bid;
    else
        findBid(array,fp);
}

int checkArray(int bid, int *array) {
    int i = 0;
    for (i = 1; i < 100; i++) {
        if (i == bid && array[i] == 0) {
            array[i] = 1;
            return 1;
        }
    }
}