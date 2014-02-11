CC_FLAGS= -g -Wall
CC=g++

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %, $(SRCS))

.cc:
	$(CC) $(CC_FLAGS) -o $@ $< alg/Sort.cc

all: $(BUILD)

clean:
	rm -f $(BUILD)

