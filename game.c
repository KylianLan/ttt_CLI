#include <stdio.h>

#include "arrow_input.h"

#define clear_screen() printf("\e[1;1H\e[2J")

struct game {
    int board[3][3];
    int current_player; // 0 for X, 1 for O
    char* players_names[32];
};


void green(void) {
    printf("\033[0;32m");
}
void red(void) {
    printf("\033[0;31m");
}
void reset_color(void) {
    printf("\033[0m");
}

/**
 * @brief Checks if a cell is empty or not
 * @param g: The current game in which the board has to be checked
 * @param x: The column to be checked
 * @param y: The row to be checked
 * * @return
 * *
 * * - 1 if the cell is empty
 * 
 * * - 0 if the cell is marked
 */
int is_cell_empty(struct game* g, int x, int y) {
    if (g->board[y][x] == -1) return 1;
    return 0;
}

void display_board(struct game* g, int x, int y) {
    clear_screen();
    for (int i = 0; i < 5; i++) {
        printf("\t\t");
        for (int j = 0; j < 12; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0 && j % 4 != 0) {
                    if ((x != -1 && y != -1) &&  (j / 4 == x && i / 2 == y)) {
                        (!is_cell_empty(g, j/4, i/2) ? red() : green());
                        printf("%c", ((g->current_player ? 'O' : 'X')));
                        reset_color();
                    } else {
                        printf("%c", (g->board[i / 2][j / 4] == 0 ? 'X' : (g->board[i / 2][j / 4] == 1 ? 'O' : ' ')));
                    }
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

struct game init_game(void) {
    clear_screen();

    struct game g;
    g.current_player = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            g.board[i][j] = -1;
        }
    }

    return g;
}

void place_mark(struct game* g, int row, int col) {
    g->board[row][col] = g->current_player;
    g->current_player = !g->current_player;
}

void select_cell(struct game* g) {
    int res = -1;
    int x_selection = 0;
    int y_selection = 0;
    int valid_selection = 0;

    while (!valid_selection) {
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
            display_board(g, x_selection, y_selection);
        }
        if (is_cell_empty(g, x_selection, y_selection)) valid_selection = 1;
        
    }
    
    place_mark(g, y_selection, x_selection);
}

/**
 * @brief Checks if a player has won the game or not
 * @param g: The current game in which the board has to be checked
 * * @return
 * *
 * * - 1 or 0 corresponding to a player's code if they are winning
 * 
 * * - -1 if no one won the game
 */
int check_win(struct game* g) {

    for (int i = 0; i < 3; i++) {
        if (g->board[i][0] != -1 &&
            g->board[i][0] == g->board[i][1] &&
            g->board[i][1] == g->board[i][2]) {
                return g->board[i][0];
            }
    }

    for (int i = 0; i < 3; i++) {
        if (g->board[0][i] != -1 &&
            g->board[0][i] == g->board[1][i] &&
            g->board[1][i] == g->board[2][i]) {
                return g->board[0][i];
            }
    }

    if (g->board[1][1] != -1) {
        if (g->board[0][0] == g->board[1][1] && g->board[1][1] == g->board[2][2]) {
            return g->board[1][1];
        }
        if (g->board[0][2] == g->board[1][1] && g->board[1][1] == g->board[2][0]) {
            return g->board[1][1];
        }
    }

    return -1;
}

void start_game(void) {
    struct game g = init_game();
    display_board(&g, 0, 0);
    int winner = -1;

    for (int i = 0; i < 9; i++) {
        select_cell(&g);
        display_board(&g, 0, 0);
        if ((winner = check_win(&g)) != -1) {
            break;
        }
    }

    if (winner != -1) {
        printf("Player %c wins!\n", (winner == 0 ? 'X' : 'O'));
    } else {
        printf("Draw\n");
    }
}
