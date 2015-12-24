CC=g++
#compiler flags:
#-g adds debugging infomation to the executable file
#-Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall
#DEPS = depending header file
OBJ = TCPServer.o TCPConnection.o

# $@ is item before ':', $^ is items after ':'
test: $(OBJ)
	$(CC) -o $@ test.cpp $^ $(CFLAGS)

# $< is the first item after ':'
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o

