//
// Created by Timothy Stronach on 3/2/2021.
//


#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ERR -1

#define DEF FILE

int main(void){

char a_string[3] = "ECE";

int block1, block2, block3;

    block1 = (int) a_string[0];
    block2 = (int) a_string[1];
    block3 = (int) a_string[2];

 char   checker =  a_string[3];
 char   checker1 =  a_string[2];
 char   checker2 =  a_string[1];
//for the case when three characters can be checked

if(checker == NULL) {

    int mask1 = (block1 & 252) >> 2; //mask 1
    int mask2 = ((block1 & 3) << 4) + ((block2 & 113) >> 4); //mask 2
    int mask3 = ((block2 & 31) << 2) + ((block3 & 192) >> 6); //mask 3
    int mask4 = ((block3 & 61)); // mask 4


    printf("Block 1 is  %i\n", block1);
    printf("Block 2 is  %i\n", block2);
    printf("Block 3 is  %i\n", block3);


    printf("mask 1 is  %i\n", mask1);
    printf("mask 2 is  %i\n", mask2);
    printf("mask 3 is  %i\n", mask3);
    printf("mask 4 is  %i\n", mask4);
}

//for case when there is two and not three
else if(checker1 == NULL) {
        int mask1 = (block1 & 252) >> 2; //mask 1
        int mask2 = ((block1 & 3) << 6); //mask 2
        int mask3 = 65; // the "=", that calls the padding bit
        int mask4 = 65;

        printf("Block 1 is  %i\n", block1);
        printf("Block 2 is  %i\n", block2);
        printf("Block 3 is  %i\n", block3);


        printf("mask 1 is  %i\n", mask1);
        printf("mask 2 is  %i\n", mask2);
        printf("mask 3 is  %i\n", mask3);
        printf("mask 4 is  %i\n", mask4);
    }

else if(checker2 == NULL){

        int mask1 = (block1 & 252) >> 2; //mask 1
        int mask2 = ((block1 & 3) << 4) + ((block2 & 113) >> 4); //mask 2
        int mask3 = ((block2 & 31) << 4);
        int mask4 = 65;


        printf("Block 1 is  %i\n", block1);
        printf("Block 2 is  %i\n", block2);
        printf("Block 3 is  %i\n", block3);


        printf("mask 1 is  %i\n", mask1);
        printf("mask 2 is  %i\n", mask2);
        printf("mask 3 is  %i\n", mask3);
        printf("mask 4 is  %i\n", mask4);

    }

}

