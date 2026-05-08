#ifndef ARROW_INPUT_H
#define ARROW_INPUT_H

#include <termios.h>

void set_raw_mode(struct termios *orig_termios);
void reset_mode(struct termios *orig_termios);
<<<<<<< HEAD
int read_arrows(void);
=======
int read_arrows(int enter_key);
>>>>>>> game

#endif

