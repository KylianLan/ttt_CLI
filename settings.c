#include <stdio.h>

#include "arrow_input.h"
#include "input.h"
#include "menu.h"
#include "game.h"

#define clear_screen() printf("\e[1;1H\e[2J")


void show_settings(int selection) {
    clear_screen();
    display_title();
    
    char options[3][32] = {{"Change player X name"}, {"Change player O name"}, {"Back"}};
    for (int i = 0; i < 3; i++) {
        if (selection == i) {
            green();
        }
        printf("\t%s\n", options[i]);
        reset_color();
    }
}

void settings(struct players* p) {
    clear_screen();
    display_title();
    printf("\t\tSettings\n");
    show_settings(0);

    int res = 0;
    int selection = 0;

    while (1) {
        res = read_arrows(1);
        if (res == 1) {
            selection = (selection + 2) % 3;
        } else if (res == 2) {
            selection = (selection + 1) % 3;
        } else if (res == 3 || res == 5) {
            break;
        }
        show_settings(selection);
    }

    if (selection == 0) {
        clear_screen();
        display_title();
        printf("\tEnter name for player X: \n");
        p->player_x_name = read_string(0);
    } else if (selection == 1) {
        clear_screen();
        display_title();
        printf("\tEnter name for player O: \n");
        p->player_o_name = read_string(0);
    } else {
        clear_screen();
        display_title();
        return;
    }
}