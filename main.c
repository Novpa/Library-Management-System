#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

FILE* fp;
char myChar1;
int i = 0;
fp = fopen("myFirstFile.txt", "r");

if(fp != NULL) {

    while(!feof(fp)) {
      myChar1 = fgetc(fp);
      printf("%c", myChar1);
      if(myChar1 == '\n')
      i++;
    }
      printf("\nThere are %d rows in it", i+1);
    fclose(fp);
  }
  return 0;
}