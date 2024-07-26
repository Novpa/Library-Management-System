#include <stdio.h>

void insertText() {
    FILE *fp;
    fp = fopen("file.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "This is testing\n");
        fprintf(fp, "Learn file handling\n");
        fclose(fp);
    } else {
        printf("Failed to open file for writing.\n");
    }
}

void readText() {
    FILE *fp;
    char buffer[255];  // Buffer to store the text read from the file

    fp = fopen("file.txt", "r");  // Open the file in read mode
    if (fp != NULL) {
        // Read each line from the file and print it to the console
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }
        fclose(fp);
    } else {
        printf("Failed to open file for reading.\n");
    }
}

int main() {
    FILE *fp;
    fp = fopen("file.txt", "w");
    if (fp != NULL) fclose(fp);

    insertText();  // Write text to the file
    insertText();  // Write text to the file
    insertText();  // Write text to the file
    readText();    // Read and display text from the file
    return 0;
}
