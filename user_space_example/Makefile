CC      = gcc
CCFLAGS = -I../evaluator
LDFLAGS =
SOURCES = main.c lib.c ../evaluator/evaluator.c
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
