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

void welcome();
void thankYou();

struct bookManagement {
    char code[10];
    char bookName[256];
    char bookType[256];
    char price[15];
} BookManagement;

// FILE HANDLER FUNCTION FOR THE BOOK DATABASE

void inputData() {
    FILE *fp;
    fp = fopen("databuku.txt", "a+");
    if (fp == NULL) {
        fp = fopen("databuku.txt", "w+");
        {
            clearConsole();
            printf(
                "Please hold on while we set our database in your computer!!");
            printf("\n Process completed press any key to continue!! ");
            getchar();
        }
    }
    while (1) {
        clearConsole();
        printf("\nCode: ");
        fgets(BookManagement.code, sizeof(BookManagement.code), stdin);
        removeNewline(BookManagement.code);
        printf("Book Name: ");
        fgets(BookManagement.bookName, sizeof(BookManagement.bookName), stdin);
        removeNewline(BookManagement.bookName);
        printf("Book Type: ");
        fgets(BookManagement.bookType, sizeof(BookManagement.bookType), stdin);
        removeNewline(BookManagement.bookType);
        printf("Price: ");
        fgets(BookManagement.price, sizeof(BookManagement.price), stdin);
        fwrite(&BookManagement, sizeof(BookManagement), 1, fp);
        removeNewline(BookManagement.price);
        printf("\n\nBook has been added : %s\n", BookManagement.bookName);
        printf("Press enter to continue...");
        getchar();
        break;
    }
    fclose(fp);
}

void outputData() {
    FILE *fp;
    int i = 1;
    fp = fopen("databuku.txt", "r");
    if (fp != NULL) {
        clearConsole();
        // printf("\nCode\t ");
        // printf("\tName\t");
        // printf("\tType\t ");
        // printf("\tPrice\n");
        printf(
            "================================================================="
            "\n");
        printf("\n%-4s | %-8s | %-20s | %-15s | %s\n", "No.", "Code",
               "Book Name", "Book Type", "Price");
        printf(
            "================================================================="
            "\n");
        while (fread(&BookManagement, sizeof(BookManagement), 1, fp) == 1) {
            printf("%-5d  %-8s   %-20s   %-15s    $%s\n", i,
                   BookManagement.code, BookManagement.bookName,
                   BookManagement.bookType, BookManagement.price);
            printf(
                "--------------------------------------------------------------"
                "-"
                "--"
                "\n");
            i++;
        }
        printf("\n\nPress enter to continue...");
        getchar();
    }
    fclose(fp);
}

void deleteData() {
    FILE *fp, *fp2;
    char code[5];
    int i = 1;

    fp2 = fopen("new.txt", "w");
    fp = fopen("databuku.txt", "r");

    if (fp != NULL) {
        if (fp2 != NULL) {
            clearConsole();
            printf("Enter book code you want to delete: ");
            fgets(code, 5, stdin);
            removeNewline(code);

            while (fread(&BookManagement, sizeof(BookManagement), 1, fp) == 1) {
                if (strcmp(BookManagement.code, code) == 0) {
                    i = 0;
                    continue;
                } else {
                    fwrite(&BookManagement, sizeof(BookManagement), 1, fp2);
                }
            }
        }
    }

    if (i == 1) {
        printf("No records contains %s code!", code);
        fclose(fp);
        fclose(fp2);
        printf("\n\nPress enter to continue...");
        getchar();
    }
    fclose(fp);
    fclose(fp2);
    remove("databuku.txt");
    rename("new.txt", "databuku.txt");
    printf("The data has successfully been removed!");
    fclose(fp);
    fclose(fp2);
    printf("\n\nPress enter to continue...");
    getchar();
}

// FILE HANDLER FUNCTION FOR THE HISTORY
void inputSellingData() {
    FILE *fp;
    fp = fopen("history.txt", "a+");
    if (fp == NULL) {
        fp = fopen("history.txt", "w+");
        {
            clearConsole();
            printf(
                "Please hold on while we set our database in your computer!!");
            printf("\n Process completed press any key to continue!! ");
            getchar();
        }
    }
    while (1) {
        clearConsole();
        printf("\n\n*** INPUT THE SOLD BOOK DATAS ***\n");
        printf("\nCode: ");
        fgets(BookManagement.code, sizeof(BookManagement.code), stdin);
        removeNewline(BookManagement.code);
        printf("Book Name: ");
        fgets(BookManagement.bookName, sizeof(BookManagement.bookName), stdin);
        removeNewline(BookManagement.bookName);
        printf("Book Type: ");
        fgets(BookManagement.bookType, sizeof(BookManagement.bookType), stdin);
        removeNewline(BookManagement.bookType);
        printf("Price: ");
        fgets(BookManagement.price, sizeof(BookManagement.price), stdin);
        fwrite(&BookManagement, sizeof(BookManagement), 1, fp);
        removeNewline(BookManagement.price);
        printf("\n\nBook has been sold : %s\n", BookManagement.bookName);
        printf("Press enter to continue...");
        getchar();
        break;
    }
    fclose(fp);
}

void outputSellingData() {
    FILE *fp;
    int i = 1;
    fp = fopen("history.txt", "r");
    if (fp != NULL) {
        clearConsole();
        // printf("\nCode\t ");
        // printf("\tName\t");
        // printf("\tType\t ");
        // printf("\tPrice\n");
        printf(
            "================================================================="
            "\n");
        printf("\n%-4s | %-8s | %-20s | %-15s | %s\n", "No.", "Code",
               "Book Name", "Book Type", "Price");
        printf(
            "================================================================="
            "\n");
        while (fread(&BookManagement, sizeof(BookManagement), 1, fp) == 1) {
            printf("%-5d  %-8s   %-20s   %-15s    $%s\n", i,
                   BookManagement.code, BookManagement.bookName,
                   BookManagement.bookType, BookManagement.price);
            printf(
                "--------------------------------------------------------------"
                "-"
                "--"
                "\n");
            i++;
        }
        printf("\n\nPress enter to continue...");
        getchar();
    }
    fclose(fp);
}

void deleteHistoryData() {
    FILE *fp, *fp2;
    char code[5];
    int i = 1;

    fp2 = fopen("history2.txt", "w");
    fp = fopen("history.txt", "r");

    if (fp != NULL) {
        if (fp2 != NULL) {
            clearConsole();
            printf("Enter book code you want to delete: ");
            fgets(code, 5, stdin);
            removeNewline(code);

            while (fread(&BookManagement, sizeof(BookManagement), 1, fp) == 1) {
                if (strcmp(BookManagement.code, code) == 0) {
                    i = 0;
                    continue;
                } else {
                    fwrite(&BookManagement, sizeof(BookManagement), 1, fp2);
                }
            }
        }
    }

    if (i == 1) {
        printf("No records contains %s code!", code);
        fclose(fp);
        fclose(fp2);
        printf("\n\nPress enter to continue...");
        getchar();
    }
    fclose(fp);
    fclose(fp2);
    remove("history.txt");
    rename("history2.txt", "history.txt");
    printf("The data has successfully been removed!");
    fclose(fp);
    fclose(fp2);
    printf("\n\nPress enter to continue...");
    getchar();
}

int main() {
    char key;
    int choice;

    int mainChoice(int choice) {
        if (choice == 6) {
            return 0;
        }
        switch (choice) {
            case 1:
                inputSellingData();
                break;
            case 2:
                outputSellingData();
                break;
            case 3:
                outputData();
                break;
            case 4:
                deleteHistoryData();
                break;
            case 5:
                deleteData();
                break;
            case 6:
                break;
            case 7:
                inputData();
                break;
            default:
                printf("Press enter...");
                getchar();
                break;
        }
    }

    do {
        clearConsole();
        welcome();
        printf("\nChoose menu --> ");
        scanf("%d", &choice);
        clearInputBuffer();
        mainChoice(choice);
    } while (choice != 6);
    thankYou();
    getchar();
}

void welcome() {
    printf("\n\n|**********************************************|\n");
    printf("|                                              |\n");
    printf("|            WELCOME TO THE MAIN MENU          |\n");
    printf("|                                              |\n");
    printf("|**********************************************|\n");

    printf("\n");

    printf("   Please choose an option from the menu below:   \n");
    printf("\n");
    printf("|  --------------------------------------------  |\n");
    printf("|  1. Input                                      |\n");
    printf("|  2. View History                               |\n");
    printf("|  3. View Book                                  |\n");
    printf("|  4. Delete History                             |\n");
    printf("|  5. Delete Book                                |\n");
    printf("|  6. Exit                                       |\n");
    printf("|  7. Add Book List                              |\n");
    printf("|  --------------------------------------------  |\n");

    printf("\n");

    printf("|  If this is your first time using the app,     |\n");
    printf("|  please add some book first by choosing menu 7.|\n");
    printf("|                                                |\n");

    printf("\n");

    printf("************************************************\n");
}

void thankYou() {
    clearConsole();
    printf("\n\n|**********************************************|\n");
    printf("|                                              |\n");
    printf("|                THANK YOU FOR USING           |\n");
    printf("|                OUR BOOK MANAGEMENT SYSTEM    |\n");
    printf("|                                              |\n");
    printf("|**********************************************|\n");

    printf("\n");

    printf("|                                              |\n");
    printf("|   We hope you found the system useful.       |\n");
    printf("|   If you have any feedback, please let us    |\n");
    printf("|   know. Have a great day!                    |\n");
    printf("|                                              |\n");
    printf("|                                              |\n");

    printf("\n");

    printf("************************************************\n");
}
