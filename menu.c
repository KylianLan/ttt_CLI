#include <stdio.h>

#include "arrow_input.h"

#define clear_screen() printf("\e[1;1H\e[2J")

void display_title(void) {
    clear_screen();

    FILE* file = fopen("title_ascii.txt", "r");
    
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