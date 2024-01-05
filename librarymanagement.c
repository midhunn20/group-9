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
    
    while (input != 0) {
        switch (input) {
            case 1:
                add(lib, &count, f1);
                break;
            case 2:
                cnt(count);
                break;
            case 3:
                display(f1);
                break;
            case 4:
                dbINFO(lib, count, f1);
                break;
            case 5:
                author(lib, count, f1);
                break;
            default:
                printf("Invalid input\n");
                break;
        }

        printf("\n\nEnter one of the above: ");
        scanf("%d", &input);
    }

    fclose(f1);

    return 0;
}
    
void add(struct library lib[], int *count, FILE *f1) {
    getchar(); // Clear input buffer
    printf("Enter book name: ");
    fgets(lib[*count].book_name, sizeof(lib[*count].book_name), stdin);
    lib[*count].book_name[strcspn(lib[*count].book_name, "\n")] = '\0'; // Remove newline from fgets

    printf("Enter author name: ");
    fgets(lib[*count].author, sizeof(lib[*count].author), stdin);
    lib[*count].author[strcspn(lib[*count].author, "\n")] = '\0'; // Remove newline from fgets

    printf("Enter pages: ");
    scanf("%d", &lib[*count].pages);

    printf("Enter price: ");
    scanf("%f", &lib[*count].price);

    fprintf(f1, "%s, %s, %d, %.2f\n", lib[*count].book_name, lib[*count].author, lib[*count].pages, lib[*count].price);

    (*count)++;
}
