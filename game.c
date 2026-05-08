#include <stdio.h>

// #include "arrow_input.h"

#define clear_screen() printf("\e[1;1H\e[2J")

struct game {
    int board[3][3];
    int current_player; // 0 for X, 1 for O
};

void display_board(struct game* g) {
    clear_screen();
    for (int i = 0; i < 5; i++) {
        printf("\t\t");
        for (int j = 0; j < 12; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0 && j % 4 != 0) {
                    printf("%c", (g->board[i / 2][j / 4] == 0 ? 'X' : (g->board[i / 2][j / 4] == 1 ? 'O' : ' ')));
                } else if (j % 4 == 0 && j !=0) {
                    printf("|");
                } else {
                    printf(" ");
                }
            } else {
                if (j % 4 == 0 && j != 0) {
                    printf("+");
                } else if (j % 4 != 0 && j != 0) {
                    printf("-");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void start_game(void) {
    clear_screen();

    struct game g;
    g.current_player = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            g.board[i][j] = -1;
        }
    }

    display_board(&g);
}

void place_mark(struct game* g, int row, int col) {
    
}

int main() {
    start_game();

    return 0;
}
