CC = cc
CFLAGS += -g

all:
	$(CC) $(CFLAGS) main.c -o a.out

clean:
	rm -f *.o *.out
	ls -n

test:
	gdb -q a.out
