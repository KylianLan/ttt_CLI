#include <stdio.h>

#include "arrow_input.h"
#include "menu.h"
#include "game.h"
#include "settings.h"

#define clear_screen() printf("\e[1;1H\e[2J")
#define move_up_and_clear()  printf("\033[A\033[2K")

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
    char options[3][16] = {{"Start"}, {"Settings"}, {"Exit"}};
    for (int i = 0; i < 3; i++) {
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

    struct players p;
    p.player_o_name = "O";
    p.player_x_name = "X";
    
    int res = 0;
    int selection = 0;
    display_options(selection);
    while (1) {
        clear_screen();
        display_title();
        display_options(selection);
        res = read_arrows(1); // reads the arrows input to interact with the menu
        if (res == 1) {
            selection = (selection + 2) % 3;
        } else if (res == 2) {
            selection = (selection + 1) % 3;
        }
        /**
         * selection is either 0 or 1
         * 0 = start the game
         * 1 = settings
         * 2 = leave the game
         */
        else if (res == 3 || res == 5) {
            if (selection == 2) {
                return;
            }
            if (selection == 1) {
                settings(&p);
            }
            if (selection == 0) {
                start_game(&p);
            }
        }
    }
}