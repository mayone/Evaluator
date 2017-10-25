#include "lib.h"
#include "evaluator.h"

void helloWorld()
{
	eval_start("Hello World");
	int hello = 123;
	eval_end("Hello World");
}
