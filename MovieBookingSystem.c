#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

void showMovies() {
    FILE* movies = fopen("tickets.csv", "r");

    char line[1024];
    while (fgets(line, 1024, movies))
    {
        char* tmp = strdup(line);
        printf("%s\n", getfield(tmp, 1));
        free(tmp);
    }
}

void showRecords() {
    FILE* movies = fopen("tickets.csv", "r");

    char line[1024];
    while (fgets(line, 1024, movies))
    {
        char* tmp = strdup(line);
        printf("%s, %s\n", getfield(tmp, 1), getfield(tmp, 2));
        free(tmp);
    }

}

int main() {
    int choice;

    printf("Hello and Welcome to the Movie Booking System\n");
    printf("------------------Main Menu------------------\n");
    printf("1. Display All Movie Records\n");
    printf("2. Display All Movies\n");
    printf("3. Quit\n");
    printf("---------------------------------------------\n");

    while (1) {
        printf("\nWhat is your option (1-3)\n");
        scanf("%d", &choice);  

        switch(choice) {
            case 1 :
                showRecords();
                break;
            case 2 :
                showMovies();
                break;
            case 3 :
                return 0;
            default :
                printf("Invalid Option\n" );
        }
    }
    
    return 0;
}