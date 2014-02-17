CC_FLAGS= -g -Wall -fpic
CC=g++

SUBDIRS=alg

TARGET_NAME=test

define make_subdir
@for subdir in $(SUBDIRS) ; do \
    ( cd $$subdir && make $1) \
    done;
endef

all:
	$(call make_subdir , all)
	$(CC) $(CC_FLAGS) -o $(TARGET_NAME) $(TARGET_NAME).cc -L. -lalg

clean:
	$(call make_subdir , clean)
	rm $(TARGET_NAME)

