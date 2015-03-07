#include <sys/select.h>

#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "term.h"

fd_set fds;
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

int
kbhit()
{
	struct timeval tv = { 0L, 0L };

	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

	return FD_ISSET(STDIN_FILENO, &fds);
}

int
reset_input()
{
	int r;
	unsigned char c;

	if ((r = read(0, &c, sizeof(c))) < 0) {
		return r;
	} else {
		return c;
	}
}

