#include <unistd.h>

#include "evaluator.h"
#include "lib.h"


int main(int argc, char const *argv[])
{
	int i;

	helloWorld();

	eval_begin("I am tired");
	usleep(1000);
	eval_end("I am tired");

	for(i = 0; i < 2; i++)
	{
		eval_begin("Sleep 0.5 second");
		usleep(500000);
		eval_end("Sleep 0.5 second");
	}

	eval_dump();

	return 0;
}
