all: 				electrotest			

electrotest: 			electrotest.c lib/libpower.so lib/libresistance.so lib/libcomponent.so
				gcc -o electrotest electrotest.c -L./lib -lpower -lresistance -lcomponent -Wl,-rpath,./lib 

lib/libcomponent.so: 		lib_c/libcomponent.c lib_c/libcomponent.h		
				gcc -c -fPIC -fPIC lib_c/libcomponent.c
				gcc -shared -fPIC -o lib/libcomponent.so libcomponent.o

lib/libresistance.so:		lib_c/libresistance.c lib_c/libresistance.h			
				gcc -c -fPIC lib_c/libresistance.c
				gcc -shared -fPIC -o lib/libresistance.so libresistance.o

lib/libpower.so: 		lib_c/libpower_i.c lib_c/libpower_r.c lib_c/libpower.h 			
				gcc -c -fPIC lib_c/libpower_i.c 
				gcc -c -fPIC lib_c/libpower_r.c -lm
				gcc -shared -fPIC -o lib/libpower.so libpower_r.o libpower_i.o

clean:
				-rm *.o lib/*.so
				-rm electrotest

install: 			  
	 			cp electrotest /home/kristin/bin 						
				cp lib/libcomponent.so /home/kristin/lib
				cp lib/libpower.so /home/kristin/lib
				cp lib/libresistance.so /home/kristin/lib
				gcc -o bin/electrotest electrotest.c -L./lib -lpower -lresistance -lcomponent -Wl,-rpath,. -lm

uninstall: 
				rm -f /home/kristin/bin/electrotest /home/kristin/lib/libcomponent.so /home/kristin/lib/libpower.so  						/home/kristin/lib/libresistance.so
				
				



