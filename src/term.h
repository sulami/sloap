#ifndef TERM_H_INCLUDED
#define TERM_H_INCLUDED

#include <termios.h>

/*
 * Get the original terminal mode, set TCSANOW for the new one and
 * register reset_terminal_mode() for program exit.
 */
void nonblock();

/*
 * Use the original terminal mode to reset the terminal on program
 * exit.
 */
void reset_terminal_mode();

#endif

