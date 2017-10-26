#include <stdio.h>
#include <string.h>
#include <time.h>

#include "profiler.h"


struct _profiler profiler;

void prof_begin(const char *title)
{
	int i, n, section_found;
	struct section *sect;

	section_found = 0;
	n = profiler.num_sections;

	for (i = 0; i < n; i++)
	{
		sect = &profiler.sections[i];
		if (strcmp(title, sect->title) == 0)
		{
			section_found = 1;
			clock_gettime(CLOCK_REALTIME, &sect->ts_begin);
			break;
		}
	}

	if (!section_found)	// New section
	{
		i = profiler.num_sections++;
		sect = &profiler.sections[i];
		strcpy(sect->title, title);
		clock_gettime(CLOCK_REALTIME, &sect->ts_begin);
	}
}

void prof_end(const char *title)
{
	int i, n, section_found;
	double time_begin, time_end;
	struct section *sect;

	section_found = 0;
	n = profiler.num_sections;

	for (i = 0; i < n; i++)
	{
		sect = &profiler.sections[i];
		if (strcmp(title, sect->title) == 0)
		{
			clock_gettime(CLOCK_REALTIME, &sect->ts_end);
			time_begin = sect->ts_begin.tv_sec + (sect->ts_begin.tv_nsec / 1000000000.0);
			time_end = sect->ts_end.tv_sec + (sect->ts_end.tv_nsec / 1000000000.0);
			sect->elapsed_time += time_end - time_begin;
			sect->num_rounds++;
			section_found = 1;
			break;
		}
	}

	if (!section_found)
	{
		printf("Error: Section %s has no begin!\n", title);
	}
}

void prof_dump(void)
{
	int i, n;
	struct section *sect;

	n = profiler.num_sections;
	if (n == 0)
	{
		return;
	}

	printf("==========================================\n");
	printf("Number of sections\t%d\n", n);
	for (i = 0; i < n; i++)
	{
		sect = &profiler.sections[i];
		printf("------------------------------------------\n");
		printf("Section title:\t\t%s\n", sect->title);
		printf("Number of rounds:\t%d\n", sect->num_rounds);
		printf("Total elapsed time:\t%.9lf second\n", sect->elapsed_time);
		printf("Average time per round:\t%.9lf second\n", sect->elapsed_time / sect->num_rounds);
	}
}
