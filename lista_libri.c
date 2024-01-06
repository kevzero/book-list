#include <stdio.h>
#include <string.h>

#define N 50

typedef struct {
    char id[40];
    char title[150];
    char genre[40];  
} book;

book library[N] = { 
    {"32-45435-1223-4", "The Name of the Rose", "novel"},
    {"78-674-5435-1223-4", "The C Programming Language", "computer science"},
    {"6-7887-6-8435-12234", "The C++ Programming Language", "computer science"},
    {"324-5-435-1234", "Java", "computer science"},
};

int my_index = 4; // Indicates the number of elements allocated in the library array

void printBooks(int position)
{ 
    int i = 0;
    while(i < position)
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
    
    if(position >= N) {
        printf("\n\nYou have reached the maximum limit of books you can insert.");
        
        scanf("%c", &enter);
        return position;
    }
    
    fflush(stdin);
    printf("\nISBN:");
    gets(library[position].id);
    fflush(stdin);	
    printf("\nTitle:");
    gets(library[position].title);
    printf("\nGenre:");
    gets(library[position].genre);
    fflush(stdin);
    
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
        if(strcmp(library[i].genre, genre) == 0) {
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

int main(void)
{
    int choice;
    
    while((choice = menuChoice()) != 4) {
        switch(choice) {
            case 1: 
                printBooks(my_index);
                break;
            case 2:
                my_index = insertBook(my_index);
                break;
            case 3:
                printGenre(my_index);
                break;
            case 4: break;
        }
    }             
    return 0;
}
