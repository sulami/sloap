#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "term.h"

int
main(int argc, char *argv[])
{
	int opt;
	time_t start, now;
	double threshold = 900; /* 15 minutes by default. */

	while ((opt = getopt(argc, argv, "ht:")) != -1) {
		switch (opt) {
		case 'h':
			puts("Usage: %s [-t seconds] command");
			puts("Use 'q' to abort timer");
			return EXIT_SUCCESS;
		case 't':
			threshold = strtod(optarg, NULL);
			break;
		default:
			fprintf(stderr, "Usage: %s [-t seconds] command\n",
			        argv[0]);
			return EXIT_FAILURE;
		}
	}

	puts("SLOAP started.");

	nonblock();

	time(&start);

	for (;;) {
		if (kbhit()) {
			if (reset_input() == 113) {
				/* 'q', not going to include keysyms here. */
				puts("SLOAP exited.\r");

				return EXIT_SUCCESS;
			}

			puts("Timer has been reset.\r");
			time(&start);
		}

		time(&now);

		if (difftime(now, start) > threshold)
			break;

		sleep(1); /* Be nice to the CPU. */
	}

	puts("Wakeup time!\r");

	return EXIT_SUCCESS;
}

