//
// Created by Timothy Stronach on 3/13/2021.
/*tstronac 1581380*/
#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include "io.c"

#define _CRT_SECURE_NO_WARNINGS

#define BUFFER_SIZE 64

#define MIN     0
#define MAX     1
#define ODD     2
#define EVEN    3
#define MINMAX  4
#define ODDEVEN 5

// prototypes of your functions you need to write
/*The names are self explanatory*/
int finder_min(int [], int b);
int finder_max(int [], int b);
int sort_odd(int [], int b);
int sort_even(int [], int b);

void set_zeros(int * a);

// this function fills input buffer using values
// obtained with the function get_value()
void reading(int[]);

// this function performs processing of data in local buffer
// and put results back into local buffer
void processing(int[]);

// this function transfers data between two buffers
// it is used to transfer data from input buffer to local buffer
// and to transfer data from local buffer to output buffer
void transferring(int[], int[]);

// this function submit the results stored
// in output buffer for validation
void submitting(int[]);


// two functions provided to you (defined in io.h and io.c) are:
// int get_value(void);
//       this function generates a single value
//       you use it to obtain this value and put it into an input buffer
// int submit_result(int[]);
//       you use this function to submit the data processing results
//       for validation (your results are checked inside this function)


int main(void) {

    int inputBuffer[BUFFER_SIZE] = {0};
    int localBuffer[BUFFER_SIZE] = {0};
    int outputBuffer[BUFFER_SIZE]= {0};

/*calls the function to read data into the inputbuffer using the function get_value*/
    reading(inputBuffer);

    while (inputBuffer[0]!=-1) {
        /*transfer the input buffer to local buffer using the function designed by you. This should work for both r and W*/
        transferring(inputBuffer,localBuffer);

        processing(localBuffer);

        transferring(localBuffer,outputBuffer);

        submitting(outputBuffer);

        reading(inputBuffer);
    }
    return 0;
}

void reading(int inputBuffer[]) {
/*gets the first two values to check if the ID is -1 and the length of the data*/
   inputBuffer[0] = get_value();
   inputBuffer[1] = get_value();


    if(inputBuffer[0] != -1) {
        for (int i = 0; i < inputBuffer[1]; i++)
            inputBuffer[i+2] = get_value();
    }

}
/*I think this is all you need, it just needs to read the first value and if its not it then no time wasted*/

void processing(int localBuffer[]) {
    int Operation_ID = localBuffer[0];
    int no_datapoints = localBuffer[1];
    int temp;

    switch (Operation_ID) {
    case MIN:
    localBuffer[2] = finder_min(localBuffer, no_datapoints);
    localBuffer[1] = 1;
        break;

    case MAX:
        localBuffer[2] = finder_max(localBuffer, no_datapoints);
        localBuffer[1] = 1;
        break;

    case ODD:
        localBuffer[2] = sort_odd(localBuffer, no_datapoints);
        localBuffer[1] = 1;
        break;

    case EVEN:
        localBuffer[2] = sort_even(localBuffer, no_datapoints);
        localBuffer[1] = 1;
        break;

    case MINMAX:
        /*A temp variable is used to not write over index 3*/
      temp = finder_min(localBuffer, no_datapoints);
          localBuffer[3] = finder_max(localBuffer, no_datapoints);
          localBuffer[2] = temp;
          localBuffer[1] = 2;
          break;

    case ODDEVEN:
        temp = sort_odd(localBuffer, no_datapoints);
            localBuffer[3] = sort_even(localBuffer, no_datapoints);
            localBuffer[2] = temp;
            localBuffer[1] = 2;
            break;
    }

}



/*All this needs to do is transfer the contents of one buffer to the next. I/P or O/P no shortening needed*/
void transferring(int sourceBuffer[], int destinationBuffer[]) {

    int length = sourceBuffer[1] +2;
    for(int i = 0; i < length ; i++) {
        destinationBuffer[i] = sourceBuffer[i];
    }
    set_zeros((int *) sourceBuffer);
}

/*This where you sort the data*/
void submitting(int outputBuffer[]) {
    submit_results(outputBuffer);
    set_zeros((int *) outputBuffer);
}

int finder_min(int localBuffer[],int b){
    int min = localBuffer[2];

    for (int i = 0; i < b; i++)
        if (localBuffer[i+2] <= min)
            min = localBuffer[i+2];

    return min;
    }

int finder_max(int localBuffer[],int b){
    int max = localBuffer[2];

    for (int i = 0; i < b; i++)
    {
        if (localBuffer[i+2] >= max)
            max = localBuffer[i+2];
    }
   return max;

}

int sort_odd(int localBuffer[],int b){
    int odd = 0;

    for(int i =0; i < b; i++){
        if(localBuffer[i+2]%2 == 1)
            odd++;

    }
    return odd;
}


int sort_even(int localBuffer[],int b){
int even = 0;

    for(int i =0; i < b; i++){
        if(localBuffer[i+2]%2 == 0)
           even++;
    }

    return even;
}




void set_zeros(int localBuffer[]){
    for(int i = 0 ; i< BUFFER_SIZE;i++){
        localBuffer[i] = 0;
    }
    /*set the INPUT/OUTPUT/LOCAL BUFFER TO ZERO!!!!!!!!*/
}