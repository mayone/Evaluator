#ifndef __KEVALUATOR_H__
#define __KEVALUATOR_H__

#ifdef  __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <linux/ktime.h>
//#include <linux/timekeeping.h>

#define MAX_TITLE_LENGTH 32
#define MAX_NUM_SECTIONS 32
#define MIN_MSEC_THRSHLD 16


void eval_start(const char *name);

void eval_end(const char *name);

void eval_dump(void);

struct section
{
	char title[MAX_TITLE_LENGTH];
	int num_rounds;
	struct timespec tms_start;
	struct timespec tms_end;
	unsigned long elapsed_time;
};

struct _evaluator
{
	int num_sections;
	struct section sections[MAX_NUM_SECTIONS];
};

extern struct _evaluator evaluator;


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __KEVALUATOR_H__ */
