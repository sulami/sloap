#include <stdio.h>
#include <time.h>

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
	}

	puts("Wakeup time!");

	return 0;
}

