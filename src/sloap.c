#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "term.h"

int
main()
{
	double threshold = 10;
	time_t start, now;

	puts("SLOAP started.");

	nonblock();

	time(&start);

	for (;;) {
		if (kbhit()) {
			if (reset_input() == 113) {
				/* 'q', not going to include keysyms here. */
				puts("SLOAP exited.\r");

				return 0;
			}

			puts("Timer has been reset.\r");
			time(&start);
		}

		time(&now);

		if (difftime(now, start) > threshold)
			break;

		sleep(1); /* be nice to the cpu */
	}

	puts("Wakeup time!\r");

	return 0;
}

