#include <sys/select.h>

#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "term.h"

static struct termios orig, new;

void
reset_terminal_mode()
{
	tcsetattr(0, TCSANOW, &orig);
}

void
nonblock()
{
	tcgetattr(STDIN_FILENO, &orig);
	memcpy(&new, &orig, sizeof(new));

	atexit(reset_terminal_mode);
	cfmakeraw(&new);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

