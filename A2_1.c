/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*tstronac 1581380*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

    int dice[2], Frequency[5]= {0,0,0,0,0};
    int X;
    float Mean;
    srand(time(NULL));

    void Mean_Calc(int *Frequency, float Mean, int X);
    void roll_dice(int *dice,int X,int *Frequency);


    printf("please enter a number: ");
    scanf("%d", &X);


    roll_dice(&dice, X, &Frequency);
    Mean_Calc(&Frequency, Mean, X);

    printf("Sum     Frequency\n");
    for (int i = 1; i < 6; i++) {
        printf("%3i    %5i\n", 2 * i, Frequency[i - 1]);
    }
    printf("the mean is about %.2f \n",Mean);



}


void roll_dice(int *dice,int X,int * Frequency)
{
    int i, sum;
    for (i =  0; i < X; i++) {
        for (int j = 0; j < 2; j++)
            dice[j] = 2 * (rand() % 3) + 1;

        switch (dice[0] + dice[1]) {
            case 2:
                Frequency[0]++;
                break;
            case 4:
                Frequency[1]++;
                break;
            case 6:
                Frequency[2]++;
                break;
            case 8:
                Frequency[3]++;
                break;
            case 10:
                Frequency[4]++;
                break;
            default:
                break;

        }
    }
}

void Mean_Calc(int *Frequency, float Mean, int X){
    int average;
        for(int i = 0; i< 4; i++)
        average = average + ((2*i+2)*Frequency[i]);
 Mean = average/X;
}





