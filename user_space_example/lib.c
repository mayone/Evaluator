#include "lib.h"
#include "profiler.h"

void helloWorld()
{
	prof_begin("Hello World");
	int hello = 123;
	prof_end("Hello World");
}
