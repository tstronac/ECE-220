/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Timothy Stronach: 1581380

#include <stdio.h>
#include <math.h>

int main(void ) {
    int winnings;
    double interest_month = 1.006667; // Calculated by interest/12 +1
    int year = 0;


    printf("Enter the amount won:");
    scanf("%double", &winnings);
    printf("WOOHOO! you won %d dollar(s)!\n", winnings);//Should be a million. but wasn't sure if inptxt was needed
    printf("So how long will it last?\n");

    printf("Press ENTER key to Continue\n");
    getchar();
    getchar();
//I know this is weird, but at the same time its slightly elegant? ¯\_(ツ)_/¯


    while (1) {

// the subtracted amount is take at the start. It takes into account of the interest earned up to month 6
        if (winnings >= 96091) {
            winnings -= 96091;
            winnings *= pow(interest_month, 12);
            year++;
            printf("the sum at the end of year %i is  %d \n", year, winnings);
        }

/*If they cant make the relative payment at the beginning of the year then they cant at month 6,
and thus will have withdrawn the amount at the beginning of the year times the interest accumulated*/
        else {
            winnings *= pow(interest_month, 6);
            year++;
            break;
        }

        // if you didn't put a million or less, break at 50
        if (year == 50) {
            printf(" Wow, you're good with money!\n");
            printf("You retired with %i dollars.", winnings);
            return 2;
        }
    }

    printf("You are out! Well, that was fun while it lasted.\n");
    printf("It took %i years. You took %i on your last withdrawal", year, winnings);
    return 1;
}


