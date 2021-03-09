//
// Created by Timothy Stronach on 3/1/2021.
//

#include <string.h>
#include <stdio.h>

#define ERR -1

#define DEF FILE
#define base64 64

int main(void){
    FILE *file_id, *file_id2, *file_id3;
    char c_value[6];
    char base64_key[base64];
    size_t read_char;

    file_id = fopen("D:\\School_Stuff\\ECE 220\\Lab2\\RAW.dat", "r+");
    file_id2 = fopen("D:\\School_Stuff\\ECE 220\\Lab2\\Key.dat", "r+");
    file_id3 = fopen("D:\\School_Stuff\\ECE 220\\Lab2\\Test.dat", "w");

    if (file_id == NULL){
        printf("The file cannot be found\n");
        return ERR;
    }



/*read char is the size of c_value in bytes. This is handy for the switch case for the mask// nvrmd it doesn't do anything just reads an amount
*i guess the next part is to sort the mask which writes as 4 bytes, so write twice in a block then add a space
*/
        int mask[24];
        char write[24];
        int readabit = 0;
        int writeabit = 0;

    read_char = fread(base64_key, 1, base64, file_id2);
    read_char = fread(c_value, 1, sizeof(c_value), file_id);

    while(read_char == 6) {


            for (int l = 0, j = 0; l < 8; j += 3, l += 4) {
                mask[l] = (c_value[j] & 252) >> 2; //mask 1 do you need the 252?
                mask[l + 1] = ((c_value[j] & 3) << 4) + ((c_value[j + 1] & 113) >> 4); //mask 2
                mask[l + 2] = ((c_value[j + 1] & 15) << 2) + ((c_value[j + 2] & 192) >> 6); //mask 3
                mask[l + 3] = ((c_value[j + 2] & 63)); // mask 4

            }

            for (int k = 0; k < 8; k++) {
                write[k] = base64_key[mask[k]];
            }

        writeabit=+ 1;
        fwrite(write, 8, writeabit,file_id3);

        readabit =+ 6;
        read_char = fread(c_value, 1, readabit, file_id);
    }

    if(read_char == 4){
        for (int l = 0, j = 0; l < 4; j += 3, l += 4) {
            mask[l] = (c_value[j] & 252) >> 2; //mask 1 do you need the 252?
            mask[l + 1] = ((c_value[j] & 3) << 4) + ((c_value[j + 1] & 113) >> 4); //mask 2
            mask[l + 2] = ((c_value[j + 1] & 15) << 2) + ((c_value[j + 2] & 192) >> 6); //mask 3
            mask[l + 3] = ((c_value[j + 2] & 63)); // mask 4
        }

        mask[4] = (c_value[3] & 252) >> 2;
        mask[5] = (c_value[3] & 3) << 4;
        mask[6] = '=';
        mask[7] = '=';

        for (int k = 0; k < 6; k++) {
            write[k] = base64_key[mask[k]];
        }
        write[6] = mask[6] ;
        write[7] = mask[7] ;


        writeabit=+ 1;
        fwrite(write, 8, writeabit,file_id3);

    }

    fclose(file_id);
    fclose(file_id2);
    fclose(file_id3);
    return 0;
}