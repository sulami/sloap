#include <stdio.h>
#include <time.h>
#include <unistd.h>

int
main()
{
	double threshold = 10;
	time_t start, now;

	puts("SLOAP started.");

	time(&start);

	for (;;) {
		time(&now);

		if (difftime(now, start) > threshold)
			break;

		sleep(1); /* be nice to the cpu */
	}

	puts("Wakeup time!");

	return 0;
}

