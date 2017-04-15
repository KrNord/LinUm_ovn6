all: test_libresistance

test_libresistance: main.c libresistance.so
	gcc -o test_libresistance main.c -lm -L. -lresistance -Wl,-rpath

calc_resistance.o: calc_resistance.c calc_resistance.h
	gcc -c -fPIC calc_resistance.c -lm

libresistance.so: calc_resistance.o 
	gcc -shared -fPIC -o libresistance.so libresistance.o 

clean:
	rm *.o
	rm *.so
	rm test_libresistance





	
