OBJS = main.o scanner.o -o bid
OOPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g

all : bstrees

bstrees : main.o scanner.o
	gcc $(LOPTS) $(OBJS)

bstrees.o : main.c
	gcc $(OOPTS) main.c

scanner.o : scanner.c scanner.h
	gcc $(OOPTS) scanner.c

test : bstrees
	./bid bids.txt

clean :
	rm -f main.o scanner.o bid
