CC = gcc
CFLAGS = -Wall -g
OBJ = main.o task3.o

task3: $(OBJ)
	$(CC) -o task3 $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o task3
