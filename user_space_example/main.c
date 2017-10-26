#include <unistd.h>

#include "profiler.h"
#include "lib.h"


int main(int argc, char const *argv[])
{
	int i;

	helloWorld();

	prof_begin("I am tired");
	usleep(1000);
	prof_end("I am tired");

	for(i = 0; i < 2; i++)
	{
		prof_begin("Sleep 0.5 second");
		usleep(500000);
		prof_end("Sleep 0.5 second");
	}

	prof_dump();

	return 0;
}
