#include "arrow_input.c"

void display_title(void) {
    FILE* file = fopen("title.txt", "r");
    
    char c = getc(file);
    while (c != EOF) {
        putchar(c);
        c = getc(file);
    }
    
    printf("\n");
    
    fclose(file);
}

void showMenu(void) {
    display_title();
    
    
}