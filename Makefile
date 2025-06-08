.POSIX:

SRC = main.c

all: main
main:
	${CC} ${SRC} -o $@ -g

.PHONY: all main

