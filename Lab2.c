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
  char c_value[8];
  size_t read_char;

  file_id = fopen("D:\\School_Stuff\\ECE 220\\Lab2\\Test.dat", "r+");

  if (file_id == NULL){
    printf("The file cannot be found\n");
    return ERR;
  }

  read_char = fread(c_value, 1, sizeof(c_value), file_id);
//now c value has the string, is it in bits or characters? how to convert back




//fwrite(d_value, 1, sizeof(d_value), file_id);



printf("read_char is %s",read_char);


fclose(file_id);
return 0;
}