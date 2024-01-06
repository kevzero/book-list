#include <stdio.h>
#include <string.h>

#define N 50
#define FILENAME "library_data.txt"

typedef struct {
    char id[40];
    char title[150];
    char genre[40];  
} book;

book library[N];
int my_index = 0;

void printBooks(int position)
{ 
    int i = 0;
    while (i < position)
    {	
        printf("\n\nBook Code: %s", library[i].id);
        printf("\nTitle: %s", library[i].title);
        printf("\nGenre: %s", library[i].genre);

        i++;
    }
}

int insertBook(int position)
{
    char enter;
    
    if (position >= N) {
        printf("\n\nYou have reached the maximum limit of books you can insert.");
        
        getchar(); // Consumes the newline character in the buffer
        scanf("%c", &enter);
        return position;
    }
    
    printf("\nISBN:");
    scanf("%s", library[position].id);
    printf("\nTitle:");
    scanf(" %[^\n]s", library[position].title); // Reads a whole line as title
    printf("\nGenre:");
    scanf(" %[^\n]s", library[position].genre); // Reads a whole line as genre
    
    position++;
    return position;
}

void printGenre(int position)
{ 
    char genre[40];
    int i = 0, found = 0;
    
    printf("\nWhich genre are you looking for?:");
    scanf("%s", genre);
    
    for (i = 0; i < position; i++){
        if (strcmp(library[i].genre, genre) == 0) {
            printf("\n\n ISBN: %s ", library[i].id);
            printf("\n Title: %s ", library[i].title);
            found = 1;
        }
    }
    if (found == 0) 
        printf("\nNo books in this category.");
}

int menuChoice(void)
{
    int selection = 0;
    do
    {
        printf("\n" );
        printf("\n1 - Print available books" );
        printf("\n2 - Insert a book");
        printf("\n3 - Search for books by genre");
        printf("\n4 - Exit");
        printf("\n" );
        printf("\nMake a choice: " );
        scanf("%d", &selection );
    }
    while (selection < 1 || selection > 4);
    return selection;
}

void saveLibraryToFile()
{
    FILE *file = fopen(FILENAME, "w");
    
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    
    for (int i = 0; i < my_index; i++) {
        fprintf(file, "%s;%s;%s\n", library[i].id, library[i].title, library[i].genre);
    }
    
    fclose(file);
}

void loadLibraryFromFile()
{
    FILE *file = fopen(FILENAME, "r");
    
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    
    while (fscanf(file, "%[^;];%[^;];%[^\n]\n", library[my_index].id, library[my_index].title, library[my_index].genre) == 3) {
        my_index++;
        if (my_index >= N) {
            printf("Warning: Too many books in the file. Some may not be loaded.\n");
            break;
        }
    }
    
    fclose(file);
}

int main(void)
{
    loadLibraryFromFile();
    
    int choice;
    
    while ((choice = menuChoice()) != 4) {
        switch (choice) {
            case 1: 
                printBooks(my_index);
                break;
            case 2:
                my_index = insertBook(my_index);
                saveLibraryToFile();
                break;
            case 3:
                printGenre(my_index);
                break;
            case 4: break;
        }
    }
    
    saveLibraryToFile();
    
    return 0;
}
