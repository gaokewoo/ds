CC_FLAGS= -g -Wall -fpic -Wextra 
CC=g++

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %, $(SRCS))

.cc:
	$(CC) $(CC_FLAGS) -I ../gmock/gtest/include -I ../ -o $@ $< ../lib/gmock_main.a -L../lib/ -lalg -lpthread
	@echo

all: $(BUILD)

clean:
	rm -f $(BUILD)
