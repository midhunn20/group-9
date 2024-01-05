#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library {
    char book_name[100];
    char author[100];
    int pages;
    float price;
};

void add(struct library lib[], int *count, FILE *f1);
void cnt(int count);
void display(FILE *f1);
void dbINFO(struct library lib[], int count, FILE *f1);
void author(struct library lib[], int count, FILE *f1);

int main() {
    struct library lib[100];
    int input, count = 0;
    FILE *f1 = fopen("Library.txt", "a+");

    if (f1 == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    rewind(f1); // Move the file pointer to the beginning

    while (fscanf(f1, "%99[^,], %99[^,], %d, %f\n", lib[count].book_name, lib[count].author, &lib[count].pages, &lib[count].price) != EOF) {
        count++;
    }

    printf("\n\n*###### WELCOME TO E-LIBRARY #####*\n");
    printf("\n\n1. Add book information\n");
    printf("2. List the count of books in the library\n");
    printf("3. List all the books in the library and its information\n");
    printf("4. Display book information\n");
    printf("5. List all books of given author\n");
    printf("0. Exit");

    printf("\n\nEnter one of the above: ");
    scanf("%d", &input);