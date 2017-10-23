#ifndef __EVALUATOR_H__
#define __EVALUATOR_H__

#ifdef  __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_TITLE_LENGTH 32
#define MAX_NUM_SECTIONS 32

void eval_start(const char *name);

void eval_end(const char *name);

void eval_dump();

struct section
{
	char title[MAX_TITLE_LENGTH];
	int num_rounds;
	struct timespec tms_start;
	struct timespec tms_end;
	double elapsed_time;
};

struct _evaluator
{
	int num_sections;
	struct section sections[MAX_NUM_SECTIONS];
};

static struct _evaluator evaluator;

void eval_start(const char *title)
{
	int i, n, section_found;
	struct section *sect;

	section_found = 0;
	n = evaluator.num_sections;

	for (i = 0; i < n; i++)
	{
		sect = &evaluator.sections[i];
		if (strcmp(title, sect->title) == 0)
		{
			sect->num_rounds++;
			section_found = 1;
			clock_gettime(CLOCK_REALTIME, &sect->tms_start);
			break;
		}
	}

	if (!section_found)	// New section
	{
		i = evaluator.num_sections++;
		sect = &evaluator.sections[i];
		strcpy(sect->title, title);
		sect->num_rounds++;
		clock_gettime(CLOCK_REALTIME, &sect->tms_start);
	}
}

void eval_end(const char *title)
{
	int i, n, section_found;
	struct section *sect;

	section_found = 0;
	n = evaluator.num_sections;

	for (i = 0; i < n; i++)
	{
		sect = &evaluator.sections[i];
		if (strcmp(title, sect->title) == 0)
		{
			clock_gettime(CLOCK_REALTIME, &sect->tms_end);
			double start = sect->tms_start.tv_sec + (sect->tms_start.tv_nsec / 1000000000.0);
			double end = sect->tms_end.tv_sec + (sect->tms_end.tv_nsec / 1000000000.0);
			sect->elapsed_time += end - start;
			section_found = 1;
			break;
		}
	}

	if (!section_found)
	{
		printf("Error: Section %s has no start!\n", title);
	}
}

void eval_dump()
{
	int i, n;
	struct section *sect;

	n = evaluator.num_sections;
	for (i = 0; i < n; i++)
	{
		sect = &evaluator.sections[i];
		printf("=======================================\n");
		printf("Section title:\t\t%s\n", sect->title);
		printf("Number of rounds:\t%d\n", sect->num_rounds);
		printf("Total elapsed time:\t%.9lf second\n", sect->elapsed_time);
		printf("Average time per round:\t%.9lf second\n", sect->elapsed_time / sect->num_rounds);
	}
}

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __EVALUATOR_H__ */
