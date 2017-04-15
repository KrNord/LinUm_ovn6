LIBFLAG = -L. -lresistance -Wl,-rpath,.

all: 			test_libresistance

test_libresistance: 	main.c libresistance.so
			gcc -o test_libresistance main.c $(LIBFLAG)

calc_resistance.o:	calc_resistance.c libresistance.h
			gcc -c -fPIC calc_resistance.c

libresistance.so: 	calc_resistance.o 
			gcc -shared -fPIC -o libresistance.so calc_resistance.o

clean:
			rm *.o
			rm *.so
			rm test_libresistance










	
