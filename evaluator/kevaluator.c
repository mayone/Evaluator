#include <linux/string.h>
#include <linux/ktime.h>

#include "kevaluator.h"


struct _evaluator evaluator;

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
			section_found = 1;
			sect->tms_start = current_kernel_time();
			break;
		}
	}

	if (!section_found)	// New section
	{
		i = evaluator.num_sections++;
		sect = &evaluator.sections[i];
		strcpy(sect->title, title);
		sect->tms_start = current_kernel_time();
	}
}

void eval_end(const char *title)
{
	int i, n, section_found;
	unsigned long start, end;
	long diff;
	struct section *sect;

	section_found = 0;
	n = evaluator.num_sections;

	for (i = 0; i < n; i++)
	{
		sect = &evaluator.sections[i];
		if (strcmp(title, sect->title) == 0)
		{
			sect->tms_end = current_kernel_time();
			start = sect->tms_start.tv_sec * 1000000 + sect->tms_start.tv_nsec / 1000000;
			//printk("start: %lu\n", start);
			end = sect->tms_end.tv_sec * 1000000 + sect->tms_end.tv_nsec / 1000000;
			//printk("end: %lu\n", end);
			diff = (long)end - (long)start;
			if (diff > MIN_MSEC_THRSHLD)
			{
				sect->num_rounds++;
				sect->elapsed_time += diff;
			}
			section_found = 1;
			break;
		}
	}

	if (!section_found)
	{
		printk("Error: Section %s has no start!\n", title);
	}
}

void eval_dump(void)
{
	int i, n;
	struct section *sect;

	n = evaluator.num_sections;
	for (i = 0; i < n; i++)
	{
		sect = &evaluator.sections[i];
		printk("==========================================\n");
		printk("Section title:\t\t%s\n", sect->title);
		printk("Number of rounds:\t\t%d\n", sect->num_rounds);
		printk("Total elapsed time:\t%lu msec\n", sect->elapsed_time);
		printk("Average time per round:\t%lu msec\n", sect->elapsed_time / sect->num_rounds);
	}
}
