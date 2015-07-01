SRCS := $(wildcard src/*.cpp)
OBJS := $(addprefix bin/,$(notdir $(SRCS:.cpp=.o)))
CC = g++
DEBUG = -g -std=c++11
CFLAGS = -Wall -I include/ -c $(DEBUG)
LFLAGS = -Wall -I include/ $(DEBUG)

hangman : $(OBJS)
	$(CC) $(LFLAGS) -o bin/$@ $^

bin/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	\rm bin/*
