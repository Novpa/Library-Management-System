#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Clear the buffer function:
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Remove the new line if exist function:
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Clear console function:
void clearConsole() {
#ifdef _WIN32
    system("cls");

#elif defined(__unix__) || defined(__APPLE__)
    system("clear");

#else
    // No-op or alternative handling

#endif
}

typedef struct bookManagement {
    int code;
    char bookName[256];
    char bookType[256];
    int price;
} BookManagement;

void inputData(BookManagement *newBookData) {
    printf("Code: ");
    scanf("%d", &newBookData->code);
    clearInputBuffer();
    printf("Book Name: ");
    fgets(newBookData->bookName, sizeof(newBookData->bookName), stdin);
    removeNewline(newBookData->bookName);
    printf("Book Type: ");
    fgets(newBookData->bookType, sizeof(newBookData->bookType), stdin);
    removeNewline(newBookData->bookType);
    printf("Price: ");
    scanf("%d", &newBookData->price);
}

void readText(BookManagement *newBookData) {
    char name[256];
    char type[256];
    FILE *fp;
    // char buffer[255];  // Buffer to store the text read from the file

    fp = fopen("file.txt", "r");  // Open the file in read mode
    if (fp != NULL) {
        // Read each line from the file and print it to the console

        fscanf(fp, "%d", &newBookData->code);
        printf("Code: %d\n", newBookData->code);
        while (fgets(name, sizeof(name), fp));
        printf("Book Name: %s\n", newBookData->bookName);
        while (fgets(type, sizeof(type), fp));
        printf("Book Type: %s\n", newBookData->bookType);
        fscanf(fp, "%d", &newBookData->price);
        printf("Price: %d\n", newBookData->price);
    } else {
        printf("Failed to open file for reading.\n");
        fclose(fp);
    }
}

void insertText(BookManagement *newBookData) {
    FILE *fp;
    fp = fopen("file.txt", "a");
    if (fp != NULL) {
        inputData(newBookData);
        fprintf(fp, "%d ", newBookData->code);
        fprintf(fp, "%s \n", newBookData->bookName);
        fprintf(fp, "%s \n", newBookData->bookType);
        fprintf(fp, "%d ", newBookData->price);
        fclose(fp);
    } else {
        printf("Failed to open file for writing.\n");
    }
}

int main() {
    BookManagement newBookData;
    // inputData(&newBookData;);
    insertText(&newBookData);

    readText(&newBookData);

    return 0;
}
