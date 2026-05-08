#include <stdio.h>

// #include "arrow_input.h"

#define clear_screen() printf("\e[1;1H\e[2J")

struct game {
    int board[3][3];
    int current_player; // 0 for X, 1 for O
};

void start_game(void) {
    struct game g;
    g.current_player = 0;
}

void place_mark(struct game* g, int row, int col) {
    
}

int main() {
    struct game g;
    g.current_player = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d, ", g.board[i][j] == 0);
        }
        printf("\n");
    }

    return 0;
}
