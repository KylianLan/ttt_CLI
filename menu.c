#include <stdio.h>

#include "arrow_input.h"
#include "game.h"

#define clear_screen() printf("\e[1;1H\e[2J")
#define move_up_and_clear()  printf("\033[A\033[2K")

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
        printf("\t%s\n", options[i]);
        reset_color();
    }
}

void show_menu(void) {
    display_title();
    
    int res = 0;
    int selection = 0;
    display_options(selection);
    while (1) {
        res = read_arrows(1);
        if (res == 1 || res == 2) selection = !selection;
        else if (res == 3 || res == 5) {
            if (selection == 1) {
                break;
            }
        }
        move_up_and_clear();
        move_up_and_clear();
        display_options(selection);
        
    }
}