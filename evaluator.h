#ifndef __EVALUATOR_H__
#define __EVALUATOR_H__

#ifdef  __cplusplus
extern "C"
{
#endif /* __cplusplus */

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


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __EVALUATOR_H__ */
