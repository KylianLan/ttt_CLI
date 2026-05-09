#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

/// @brief Reads a single character from standard input and returns it.
/// @return The character read from standard input. Returns '\0' if an error occurred.
char read_char(void) {
    char c;
    printf("> ");
    if (scanf(" %c", &c) == 1) {
        return c;
    }

    return '\0';
}

/// @brief Reads a string from standard input and returns it.
/// @param size The maximum size of the string variable to be returned
/// @return A pointer to the read string, or NULL if an error occurred.
/// @note The string has maximum length of 99 characters (plus the null terminator).
/// @note The trailing newline character is automatically removed from the returned string.
/// @warning The caller is responsible for freeing the returned string.
char* read_string(int size) {
    if (!size) {
        size = 100;
    }
    char* string = malloc(size * sizeof(char));
    if (string == NULL) return NULL;

    printf("> ");
    if (fgets(string, size, stdin) == NULL) {
        free(string);
        return NULL;
    }

    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1 ] = '\0';
    }

    return string;
}

void wait_for_input(void) {
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    orig_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);

    while (!getchar());

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}