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
#include <ctype.h>
#include "scanner.h"

void findRemaining (char *, FILE *);
int findBid(int *,FILE *);
int checkArray(int, int *);

int main(int argc, char **argv) {
    if (argc != 1) {
        fprintf(stderr, "Execute with './bid'\n");
        exit(1);
    }
    FILE *fp;
    fp = fopen("bids.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "File didn't open, check file name\n");
        exit(1);
    }
    char *name;
    char *in;
/*    if (argv[1] == NULL) {
        fprintf(stdout, "Enter last Name: ");
        in = readToken(stdin);
        char *s = in;
        //converts everything to uppercase since the text file is
        while (*s) {
            *s = toupper((unsigned char) *s);
            s++;
        }
        //adds a comma at the end
        name = malloc(strlen(in) + 2);
        strcpy(name, in);
        strcat(name, ",");
    }*/
//    else {
    name = "BIGWOOD,";
    in = "BIGWOOD";
//    }
    //check and make sure that the name exist
    int found = 0;
    char *str = readToken(fp);
    //loop to run until it finds the name you want
    while (!feof(fp)) {
        //if the name exist in the file then set found to 1
        if (strcmp(str,name) == 0)
            found = 1;
    str = readToken(fp);
    }
    //if you didn't find the name
    if (found == 0) {
        printf("\n%s not found in bids.txt\n\n", in);
        return 0;
    }
    //if you did find the name
    else {
        fclose(fp);
        fp = fopen("bids.txt", "r");
        if (fp == NULL) {
            fprintf(stderr, "File didn't open, check file name\n");
            exit(1);
        }
    }
    fprintf(stdout, "\nCalculating remaining lines for %s!\n", in);
    findRemaining(name,fp);
    fprintf(stdout,"are left for you!\n\n");
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
    char *c = readToken(fp);
    while (!feof(fp)) {
        int j;
        for (j = 0; j < strlen(c); j++) {
            if (!isdigit(c[j]))
                return;
        }
        int i = atoi(c);
        int bid = findBid(array,fp);
        fprintf(stdout, "%d ",bid);
        c = readToken(fp);
    }
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
