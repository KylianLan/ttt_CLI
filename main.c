#include "input.c"

int main(void) {
    char* text = read_string();
    if (text != NULL) {
        printf("You entered: %s\n", text);
        free(text);
    }
    return 0;
}