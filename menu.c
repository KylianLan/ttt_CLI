#include <stdio.h>

#include "arrow_input.h"

#define clear_screen() printf("\e[1;1H\e[2J")

void green(void) {
    printf("\033[0;32m");
}
void reset_color(void) {
    printf("\033[0m");
}

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

void display_options(int selection) {
    char options[2][8] = {{"Start"}, {"Exit"}};
    for (int i = 0; i < 2; i++) {
        if (selection == i) {
            green();
        }
        printf("%s\n", options[i]);
        reset_color();
    }
}

void show_menu(void) {
    display_title();
    
    int selection = 0;
    display_options(selection);
    while (1) {
        
    }
}