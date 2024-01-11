# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
CFLAGS  = -g -Wall -static-libgcc -static-libstdc++ -static

# The build target 
TARGET = cheat

main: main.o
	$(CC) $(CFLAGS) -o cheat main.o

main.o: main.cpp config.def.h config.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET)