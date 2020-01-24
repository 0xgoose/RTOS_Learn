CC = cc
CFLAGS += -g

all:
	$(CC) $(CFLAGS) main.c -o a.out

clean:
	rm -f *.o *.out

test:
	gdb -q a.out
