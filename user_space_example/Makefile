CC      = gcc
CCFLAGS = -I../profiler
LDFLAGS =
SRCS = $(wildcard *.c \
		../profiler/profiler.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
EXEC = example

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
%.o: %.c
	$(CC) $(CCFLAGS) -c $? -o $@

run:
	./$(EXEC)

clean:
	rm -rf *~ $(OBJS) $(EXEC)
