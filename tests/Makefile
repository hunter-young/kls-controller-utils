CXX = gcc
CXX_FLAGS = -Wall -Werror -g
.DEFAULT_GOAL := all
MAKE_ARGS = --no-print-directory

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

all: $(SRCS)
	make $(MAKE_ARGS) c_commandcontroller_test c_controllerdata_test

c_commandcontroller_test:
	$(CXX) $(CXX_FLAGS) c_commandcontroller_test.c -o bin/commandcontroller_test

c_controllerdata_test:
	$(CXX) $(CXX_FLAGS) c_controllerdata_test.c include/controllerdata.c -o bin/controllerdata_test

clean:
	rm -rf *.o bin/*
