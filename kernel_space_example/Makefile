MODULE_NAME = example
SRC = main.c ../profiler/kprofiler.c

# Define path
PWD := $(shell pwd)
KVERSION := $(shell uname -r)
KDIR_LINUX := /lib/modules/$(KVERSION)/build

$(MODULE_NAME)-objs = $(SRC:.c=.o)
obj-m := $(MODULE_NAME).o

all:
	$(MAKE) -C $(KDIR_LINUX) M=$(PWD)  modules

info:
	modinfo $(obj-m:%.o=%.ko)

clean:
	$(MAKE) -C $(KDIR_LINUX) M=$(PWD) clean
	rm $(PWD)/../profiler/*.o
