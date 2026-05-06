#include "input.h"

/// @brief Reads a single character from standard input and returns it.
/// @return The character read from standard input. Returns '\0' if an error occurred.
char read_char() {
    char c;
    printf("> ");
    if (scanf(" %c", &c) == 1) {
        return c;
    }

    return '\0';
}

/// @brief Reads a string from standard input and returns it.
/// @return A pointer to the read string, or NULL if an error occurred.
/// @note The string has maximum length of 99 characters (plus the null terminator).
/// @note The trailing newline character is automatically removed from the returned string.
/// @warning The caller is responsible for freeing the returned string.
char* read_string(void) {
    char* string = malloc(100 * sizeof(char));
    if (string == NULL) return NULL;

    printf("> ");
    if (fgets(string, 100, stdin) == NULL) {
        free(string);
        return NULL;
    }

    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1 ] = '\0';
    }

    return string;
}