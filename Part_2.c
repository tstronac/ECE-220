//
// Created by Timothy Stronach on 2/23/202i

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define DAYS_PER_WEEK 7
int main(void)
{
    int days, Remdays, weeks;



    printf("\nEnter the number of days (<=0 to quit): ");
    scanf("%d", &days);

    while (days > 0)
    {
        weeks = days /DAYS_PER_WEEK;
        Remdays = days % DAYS_PER_WEEK;


        printf("%i days: %i weeks and %i days",days , weeks, Remdays);
        printf("\nEnter the number of days (<=0 to quit): ");
        scanf("%d", &days);
    }
    return 0;

}


