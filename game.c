#include <stdio.h>

#include "arrow_input.h"

#define clear_screen() printf("\e[1;1H\e[2J")

struct game {
    int board[3][3];
    int current_player; // 0 for X, 1 for O
    char* players_names[2];
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

struct game start_game(void) {
    clear_screen();

    struct game g;
    g.current_player = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            g.board[i][j] = -1;
        }
    }

    display_board(&g);
    return g;
}

void place_mark(struct game* g, int row, int col) {

}

void select_cell(struct game* g) {
    int res = -1;
    int x_selection = 0;
    int y_selection = 0;

    while ((res = read_arrows(1)) != 5) {
        switch (res) {
            case 1:
                if (y_selection > 0) y_selection--;
                break;
            case 2:
                if (y_selection < 2) y_selection++;
                break;
            case 3:
                if (x_selection < 2) x_selection++;
                break;
            case 4:
                if (x_selection > 0) x_selection--;
                break;
        }
    }
    printf("Coucou\n");
    printf("X = %d\tY = %d\n", x_selection, y_selection);
}

void check_win(struct game* g) {

}

int main() {
    struct game g = start_game();

    for (int i = 0; i < 9; i++) {
        select_cell(&g);
    }

    return 0;
}
