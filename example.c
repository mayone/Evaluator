#include <unistd.h>
#include "evaluator.h"

int main(int argc, char const *argv[])
{
	eval_start("I am tired");
	usleep(1000);
	eval_end("I am tired");

	eval_start("Sleep 0.5 second");
	usleep(500000);
	eval_end("Sleep 0.5 second");

	eval_start("Sleep 0.5 second");
	usleep(500000);
	eval_end("Sleep 0.5 second");

	eval_dump();

	return 0;
}