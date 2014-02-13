CC_FLAGS= -g -Wall
CC=g++

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %, $(SRCS))

LINK_SRC = alg/Sort.cc alg/Subsequence.hpp alg/List.hpp

.cc:
	$(CC) $(CC_FLAGS) -o $@ $< $(LINK_SRC)

all: $(BUILD)

clean:
	rm -f $(BUILD)

