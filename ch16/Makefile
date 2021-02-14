CC = gcc
CCFLAGS = -Wall -Werror
ex1: ex1.o
	$(CC) -o $@ $^

ex2: ex2.o
	$(CC) -o $@ $^

ex3: ex3.o
	$(CC) -o $@ $^

ex4: ex4.o
	$(CC) -o $@ $^

ex5: ex5.o
	$(CC) -o $@ $^

ex6: ex6.o
	$(CC) -o $@ $^

ex7: ex7.o
	$(CC) -o $@ $^

ex1.o: ex1.c
	$(CC) $(CCFLAGS) -c $^

ex2.o: ex2.c
	$(CC) $(CCFLAGS) -c $^

ex3.o: ex3.c
	$(CC) $(CCFLAGS) -c $^

ex4.o: ex4.c
	$(CC) $(CCFLAGS) -c $^

ex5.o: ex5.c
	$(CC) $(CCFLAGS) -c $^

ex6.o: ex6.c
	$(CC) $(CCFLAGS) -c $^

ex7.o: ex7.c
	$(CC) $(CCFLAGS) -c $^

clean:
	rm -rf *.o *.dSYM ex1 ex2 ex3 ex4 ex5 ex6 ex7 

create:
	for ((i=1;i<=7;i++)); do touch ex$$i.c;         echo \/\* $$i\*\/ \\n\\n#include \<stdio.h\> > ex$$i.c;done
