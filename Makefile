CC = gcc
LIBFLAG = -L. -lresistance -Wl,-rpath,.

all:			program

program:		main.c libresistance.so
			$(CC) -o program main.c $(LIBFLAG)

libresistance.so:	lib/calc.c lib/calc.h 
			$(CC) -c -fPIC lib/calc.c
			$(CC) -shared -fPIC -o libresistance.so calc.o
		
