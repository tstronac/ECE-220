//
// Created by Timothy Stronach on 3/22/2021.
//
/*tstronac: 1581380*/

#include <stdlib.h>
#include <stdio.h>
#define NO_ELEMENTS 6


int main(){
    /*the structure for the 6 arrays*/
    struct alphabet{
        char Arr[26];
    } ;


/*creates a structure list then clears memory for 6 lists*/
/*https://stackoverflow.com/questions/625138/structure-calloc-c was helpful in this assignment*/
    struct alphabet *list = (struct alphabet*) calloc(NO_ELEMENTS, sizeof(*list));

/*can be swapped for different values*/
    char last_letter[NO_ELEMENTS] = {'d','d','s','h','n','z'};

/*for each last letter, the loop writes up to and including it*/
    for(int i = 0; i< NO_ELEMENTS; i++){
        for(int j = 97 ; j<= (int)last_letter[i]; j++)
            list[i].Arr[j-97] = j;
    }

    for(int i = 0; i<NO_ELEMENTS; i++)
        printf("%s\n",list[i].Arr);
}


