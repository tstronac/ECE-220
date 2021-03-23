//
// Created by Timothy Stronach on 3/1/2021.
//
//tstronac :1581380

#include <string.h>
#include <stdio.h>

#define ERR -1

#define DEF FILE
#define base64 64


int main2(void){
    FILE *file_id, *file_id2, *file_id3;
    char inptxt[6];
    char base64_key[base64];
    char write[8];
    int mask[8];
    size_t read_char;

//The 8 was left as is because a def took away from the readability, where base64 made sense

//open files
    file_id = fopen("D:\\School_Stuff\\ECE 220\\Lab2\\RAW.dat", "r+");
    file_id2 = fopen("D:\\School_Stuff\\ECE 220\\Lab2\\Key.dat", "r+");
    file_id3 = fopen("D:\\School_Stuff\\ECE 220\\Lab2\\Encoded.dat", "w");

    if (file_id == NULL){
        printf("The file cannot be found\n");
        return ERR;
    }

    fread(base64_key, 1, base64, file_id2);
    read_char = fread(inptxt, 1, 6, file_id);

//Read in 6 characters, convert them, output 1 block or 8 BASE64 chars
//read_char is the size of inptxt in bytes (6). This is handy for the if else

    while(read_char == 6) {

        for (int l = 0, j = 0; l < 8; j += 3, l += 4) {
            mask[l] = (inptxt[j]) >> 2; //mask 1
            mask[l + 1] = ((inptxt[j] & 3) << 4) + ((inptxt[j + 1] & 113) >> 4); //mask 2
            mask[l + 2] = ((inptxt[j+1] & 15) << 2) + ((inptxt[j + 2] & 192) >> 6); //mask 3
            mask[l + 3] = ((inptxt[j+2] & 63)); // mask 4

        }

//converts the data by calling the indexed array at the masks value
        for (int k = 0; k < 8; k++) {
            write[k] = base64_key[mask[k]];
        }

//writes 8 bytes, then one space. after read in the next 6 chars
        fwrite(write, 8, 1,file_id3);
        fputc(' ',file_id3);
        read_char = fread(inptxt, 1, 6, file_id);
    }

//once read char <6, sort the cases of less than a multiple of 3 or greater
    if( read_char >= 3) {

        for (int l = 0, j = 0; l < 4; j += 3, l += 4) {
            mask[l] = (inptxt[j]) >> 2; //mask 1
            mask[l + 1] = ((inptxt[j] & 3) << 4) + ((inptxt[j + 1] & 113) >> 4); //mask 2
            mask[l + 2] = ((inptxt[j + 1] & 15) << 2) + ((inptxt[j + 2] & 192) >> 6); //mask 3
            mask[l + 3] = ((inptxt[j + 2] & 63)); // mask 4
        }

        for (int k = 0; k < 4; k++) {
            write[k] = base64_key[mask[k]];
        }
//after a multiple of 3 is taken out, the padding cases start

        switch(read_char%3){

            case 1:

                mask[4] = inptxt[0] >> 2; //mask 1
                mask[5] = (inptxt[0] & 3) << 4; //mask 2


                for (int k = 4; k < 6; k++) {
                    write[k] = base64_key[mask[k]];
                }
                write[6] = '=';
                write[7] = '=';
                break;

            case 2:

                mask[4] = inptxt[4] >> 2; //mask 1
                mask[5] = ((inptxt[4] & 3) << 4) + ((inptxt[5] & 113) >> 4); //mask 2
                mask[6] = ((inptxt[5] & 15) << 2);

                for (int k = 4; k < 7; k++) {
                    write[k] = base64_key[mask[k]];
                }
                write[7] = '=';
                break;

            default:
                for (int k = 4; k < 8; k++) {
                    write[k] ='=';
                }
                write[7] = '=';

        }

        fwrite(write, 8, 1,file_id3);
        fputc(' ',file_id3);

    }

//in the case that read_char < 3 we goto padding
    if(read_char < 3) {
        if (read_char % 3 == 1) {

            mask[0] = inptxt[0] >> 2; //mask 1
            mask[1] = (inptxt[0] & 3) << 4; //mask 2


            for (int k = 0; k < 2; k++) {
                write[k] = base64_key[mask[k]];
            }
            write[2] = '=';
            write[3] = '=';
        }
        else {

            mask[0] = inptxt[0] >> 2; //mask 1
            mask[1] = ((inptxt[0] & 3) << 4) + ((inptxt[1] & 113) >> 4); //mask 2
            mask[2] = ((inptxt[1] & 15) << 2);

            for (int k = 0; k < 3; k++) {
                write[k] = base64_key[mask[k]];
            }
            write[3] = '=';

        }

        fwrite(write, 8, 1, file_id3);
        fputc(' ', file_id3);

    }


    fclose(file_id);
    fclose(file_id2);
    fclose(file_id3);
    return 0;
}
