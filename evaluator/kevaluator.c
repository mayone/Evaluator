#include <linux/string.h>
#include <linux/ktime.h>

#include "kevaluator.h"


struct _evaluator evaluator;

void eval_begin(const char *title)
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
			section_found = 1;
			getnstimeofday(&sect->ts_begin);
			break;
		}
	}

	if (!section_found)	// New section
	{
		i = evaluator.num_sections++;
		sect = &evaluator.sections[i];
		strcpy(sect->title, title);
		getnstimeofday(&sect->ts_begin);
	}
}

void eval_end(const char *title)
{
	int i, n, section_found;
	struct timespec ts_diff;
	unsigned long time_diff;
	struct section *sect;

	section_found = 0;
	n = evaluator.num_sections;

	for (i = 0; i < n; i++)
	{
		sect = &evaluator.sections[i];
		if (strcmp(title, sect->title) == 0)
		{
			getnstimeofday(&sect->ts_end);
			ts_diff = timespec_sub(sect->ts_end, sect->ts_begin);
			time_diff = ts_diff.tv_sec * 1000000000 + ts_diff.tv_nsec;
			if (time_diff > MIN_NSEC_THRSHLD)
			{
				sect->num_rounds++;
				sect->elapsed_time += time_diff;
			}
			section_found = 1;
			break;
		}
	}

	if (!section_found)
	{
		printk("Error: Section %s has no begin!\n", title);
	}
}

void eval_dump(void)
{
	int i, n;
	struct section *sect;

	n = evaluator.num_sections;
	if (n == 0)
	{
		return;
	}

	printk("==========================================\n");
	printk("Number of sections:\t%d\n", n);
	for (i = 0; i < n; i++)
	{
		sect = &evaluator.sections[i];
		if (sect->num_rounds > 0)
		{
			printk("------------------------------------------\n");
			printk("Section title:\t\t%s\n", sect->title);
			printk("Number of rounds:\t\t%d\n", sect->num_rounds);
			printk("Total elapsed time:\t%lu nsec\n", sect->elapsed_time);
			printk("Average time per round:\t%lu nsec\n", sect->elapsed_time / sect->num_rounds);
		}
	}
}
