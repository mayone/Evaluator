CC      = gcc
CCFLAGS = -I../profiler
LDFLAGS =
SOURCES = main.c lib.c ../profiler/profiler.c
OBJECTS = $(notdir $(SOURCES:.c=.o))
EXECUTE = example

all: $(EXECUTE)
$(EXECUTE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
$(OBJECTS): $(SOURCES)
	$(CC) $(CCFLAGS) $(SOURCES) -c
#	$(CC) $(CCFLAGS) -c $< -o $@

run:
	./$(EXECUTE)

clean:
	rm -rf *~ $(OBJECTS) $(EXECUTE)
