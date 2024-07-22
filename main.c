#include <stdio.h>
#include <stdlib.h>

int main(){

FILE* fp;
char myChar1;

fp = fopen("myFirstFile.txt", "r");

if(fp != NULL) {
    
    printf("The file was successfully opened!\n\n");
    myChar1 = fgetc(fp);
    printf("the character that was red is: %c\n", myChar1);
    // fgetc(stdin);
    getchar();
  }


  return 0;
}