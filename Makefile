libsak.so: sak.c
	gcc -Wall -Werror -shared -o libsak.so sak.c -I/usr/include/PCSC/



# Notes for shared libraries: https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html