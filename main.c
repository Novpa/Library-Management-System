#include <conio.h>
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

struct bookManagement {
    char code[10];
    char bookName[256];
    char bookType[256];
    char price[15];
} BookManagement;

void inputData() {
    FILE *fp;
    fp = fopen("file.txt", "a+");
    if (fp == NULL) {
        fp = fopen("file.txt", "w+");
        {
            clearConsole();
            printf(
                "Please hold on while we set our database in your computer!!");
            printf("\n Process completed press any key to continue!! ");
            getchar();
        }
    }
    while (1) {
        char key;
        clearConsole();
        printf("\nCode: ");
        fgets(BookManagement.code, sizeof(BookManagement.code), stdin);
        removeNewline(BookManagement.code);
        printf("Book Name: ");
        fgets(BookManagement.code, sizeof(BookManagement.bookName), stdin);
        removeNewline(BookManagement.bookName);
        printf("Book Type: ");
        fgets(BookManagement.bookType, sizeof(BookManagement.bookType), stdin);
        removeNewline(BookManagement.bookType);
        printf("Price: ");
        fgets(BookManagement.bookName, sizeof(BookManagement.bookName), stdin);
        fwrite(&BookManagement, sizeof(BookManagement), 1, fp);
        removeNewline(BookManagement.bookName);
        printf("\n\nBook has been added!!\n");
        printf("Press esc to exit");
        key = getche();
        if (key == 27) break;
    }
    fclose(fp);
}

int main() {
    inputData();
    return 0;
}
