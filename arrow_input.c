#include <termios.h>
#include <stdio.h>
#include <unistd.h>


#define SET_RAW_MODE(); \
    struct termios orig_termios; \
    tcgetattr(STDIN_FILENO, &orig_termios); \
    set_raw_mode(&orig_termios);

#define RESET_MODE(); \
    reset_mode(&orig_termios);


void set_raw_mode(struct termios *orig_termios) {
    struct termios raw = *orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void reset_mode(struct termios *orig_termios) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios);
}

/**
 * @brief Reads the arrow input and returns an integer representing the key pressed.
 * * @return An integer representing the arrow:
 * *
 * * - 1: Up arrow
 * 
 * * - 2: Down arrow
 * 
 * * - 3: Right arrow
 * 
 * * - 4: Left arrow
 * 
 * * - -1: Error occurred
 */
int read_arrows(void) {
    SET_RAW_MODE();
    int result = -1;
    
    int ch;
    while (1) {
        int ch = getchar();

        if (ch == '\033') {
            getchar();
            switch (getchar()) {
                case 'A':
                    result = 1;
                    break;
                case 'B':
                    result = 2;
                    break;
                case 'C':
                    result = 3;
                    break;
                case 'D':
                    result = 4;
                    break;
            }
            if (result != -1) break;
        }
    }

    RESET_MODE();
    return result;
}