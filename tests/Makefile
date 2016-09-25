CXX = gcc
CXX_FLAGS = -Wall -Werror
.DEFAULT_GOAL := all
MAKE_ARGS = --no-print-directory

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

all: $(SRCS)
	make $(MAKE_ARGS) c_commandcontroller_test

c_commandcontroller_test:
	$(CXX) $(CXX_FLAGS) c_commandcontroller_test.c -o bin/commandcontroller_test

clean:
	rm -rf *.o bin/*
