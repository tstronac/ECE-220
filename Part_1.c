//
// Created by Timothy Stronach on 2/23/202i

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define ARR_MAX 50



int main(void)
{
    char array_value[ARR_MAX]= "This is, maybe, or maybe not, quite nice,,,.";
    int swaps = 0;
    int size = strlen(array_value);
    for(int i = 0; i< size; i++){
        if(array_value[i] == ','){
            array_value[i] = '*';
            swaps++;
        }

    }


    printf(" the string contains %s\n", array_value);
    printf(" the had %d commas\n", swaps);
}


