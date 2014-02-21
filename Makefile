CC_FLAGS= -g -Wall -fpic
CC=g++

SUBDIRS=alg test

define make_subdir
@for subdir in $(SUBDIRS) ; do \
    ( cd $$subdir && make $1) \
    done;
endef

all:
	$(call make_subdir , all)


clean:
	rm -rf lib/*.so
	$(call make_subdir , clean)


