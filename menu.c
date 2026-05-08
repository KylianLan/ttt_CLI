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

/**
 * @brief Displays the title, can be modified by editing title_ascii.txt
 */
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

/**
 * @brief Shows available options and makes the selected one turn green
 * @param selection The selected option (will become green to show the user which one is selected)
 */
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

/**
 * @brief Handles the menu interactions
 */
void show_menu(void) {
    display_title();
    
    int res = 0;
    int selection = 0;
    display_options(selection);
    while (1) {
        res = read_arrows(1); // reads the arrows input to interact with the menu
        if (res == 1 || res == 2) selection = !selection; 
        /**
         * selection is either 0 or 1
         * 0 = start the game
         * 1 = leave the game
         */
        else if (res == 3 || res == 5) {
            if (selection == 1) {
                break;
            }
            if (selection == 0) {
                start_game();
                return;
            }
        }
        move_up_and_clear();
        move_up_and_clear();
        display_options(selection);
        
    }
}