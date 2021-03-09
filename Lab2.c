//
// Created by Timothy Stronach on 3/1/2021.
//

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ERR -1

#define DEF FILE

int main(void){
  FILE *file_id;
  char c_value[24];
  size_t read_char;

  file_id = fopen("D:\\School_Stuff\\ECE 220\\Lab2\\RAW.dat", "r+");

  if (file_id == NULL){
    printf("The file cannot be found\n");
    return ERR;
  }

  read_char = fread(c_value, 1, sizeof(c_value), file_id);
/*read char is the size of c_value in bytes. This is handy for the switch case for the mask// nvrmd it doesn't do anything just reads an amount
*i guess the next part is to sort the mask which writes as 4 bytes, so write twice in a block then add a space
*/

for(int i = 0; i < sizeof(c_value); i =i + 3) {


    int block1, block2, block3;

    block1 = (int) c_value[i];
    block2 = (int) c_value[i + 1];
    block3 = (int) c_value[i + 2];


    char checker1 = c_value[2];
    char checker2 = c_value[1];
//for the case when three characters can be checked

    if (checker1 != NULL && checker2 != NULL) {

        int mask0 = (block1 & 252) >> 2; //mask 1
        int mask1 = ((block1 & 3) << 4) + ((block2 & 113) >> 4); //mask 2
        int mask2 = ((block2 & 15) << 2) + ((block3 & 192) >> 6); //mask 3
        int mask3 = ((block3 & 63)); // mask 4


        printf("Block 1 is  %i\n", block1);
        printf("Block 2 is  %i\n", block2);
        printf("Block 3 is  %i\n", block3);


        printf("mask 1 is  %i\n", mask0);
        printf("mask 2 is  %i\n", mask1);
        printf("mask 3 is  %i\n", mask2);
        printf("mask 4 is  %i\n", mask3);
    }

//*/for case when there is two and not three
/*
    else if (checker2 != NULL) {
        int mask[0] = (block1 & 252) >> 2; //mask 1
        int mask[1] = ((block1 & 3) << 4) + ((block2 & 113) >> 4); //mask 2
        int mask[2] = ((block2 & 15) << 4);
        int mask[3] = 65;

        printf("Block 1 is  %i\n", block1);
        printf("Block 2 is  %i\n", block2);
        printf("Block 3 is  %i\n", block3);


        printf("mask 1 is  %i\n", mask[0]);
        printf("mask 2 is  %i\n", mask[1]);
        printf("mask 3 is  %i\n", mask[2]);
        printf("mask 4 is  %i\n", mask[3]);
    } else {

        int mask[0] = (block1 & 252) >> 2; //mask 1
        int mask[1] = ((block1 & 3) << 6); //mask 2
        int mask[2] = 65; // the "=", that calls the padding bit
        int mask[3] = 65;


        printf("Block 1 is  %i\n", block1);
        printf("Block 2 is  %i\n", block2);
        printf("Block 3 is  %i\n", block3);


        printf("mask 1 is  %i\n", mask[0]);
        printf("mask 2 is  %i\n", mask[1]);
        printf("mask 3 is  %i\n", mask[2]);
        printf("mask 4 is  %i\n", mask[3]);

    }
    */
}


printf("c_value is %s \n",c_value);
printf("read_char is %i \n",read_char);


fclose(file_id);
return 0;
}