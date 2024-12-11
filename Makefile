CC = gcc
CFLAGS = -Wall -Wextra
OBJ = main.o task3.o

all: task3

task3: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) task3