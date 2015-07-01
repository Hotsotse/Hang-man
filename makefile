SRCS := $(wildcard src/*.cpp)
OBJS := $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))
CC = g++
DEBUG = -g
CFLAGS = -Wall -I include/ -c $(DEBUG)
LFLAGS = -Wall -I include/ $(DEBUG)

game : $(OBJS)
	$(CC) $(LFLAGS) -o bin/$@ $^

obj/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	\rm obj/*.o bin/game
