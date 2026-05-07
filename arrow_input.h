#ifdef ARROW_INPUT_H
#define ARROW_INPUT_H

#include <termios.h>

void set_raw_mode(struct termios *orig_termios);
void reset_mode(struct termios *orig_termios);
int read_arrows(void);

#endif

