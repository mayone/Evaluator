#ifndef __KPROFILER_H__
#define __KPROFILER_H__

#ifdef  __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <linux/ktime.h>

#define MAX_TITLE_LENGTH 32
#define MAX_NUM_SECTIONS 32
#define MIN_NSEC_THRSHLD 256


void prof_begin(const char *name);
void prof_end(const char *name);
void prof_dump(void);

struct section
{
	char title[MAX_TITLE_LENGTH];
	int num_rounds;
	struct timespec ts_begin;
	struct timespec ts_end;
	unsigned long elapsed_time;
};

struct _profiler
{
	int num_sections;
	struct section sections[MAX_NUM_SECTIONS];
};

extern struct _profiler profiler;


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __KPROFILER_H__ */
