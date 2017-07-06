OBJS = main.o scanner.o -o bid
OOPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g

all : bid

bid : main.o scanner.o
	gcc $(LOPTS) $(OBJS)

bid.o : main.c
	gcc $(OOPTS) main.c

scanner.o : scanner.c scanner.h
	gcc $(OOPTS) scanner.c

test : bid
	./bid

clean :
	rm -f main.o scanner.o bid
