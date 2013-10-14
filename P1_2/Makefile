CC=gcc
#CFLAGS=­-std=c99 -ansi -­Wall -­D_GNU_SOURCE
CPPFLAGS=
all:	stat
stat:	stat.o
	$(CC) -o stat stat.o
stat.o:	stat.c
	$(CC) -c -std=c99 -Wall stat.c
clean:	
	rm -rf stat.o stat
