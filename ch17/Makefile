CC = gcc
CCFLAGS = -Wall -Werror
ex1: ex1.o
	$(CC) -o $@ $^

ex2TestDriver: ex2TestDriver.o ex2.o
	$(CC) -o $@ $^

ex3TestDriver: ex3TestDriver.o ex3.o
	$(CC) -o $@ $^

ex4: ex4.o queue.o
	$(CC) -o $@ $^

ex5: ex5.o stack.o list.o
	$(CC) -o $@ $^

ex6: ex6.o
	$(CC) -o $@ $^

ex7: ex7.o
	$(CC) -o $@ $^

ex8: ex8.o
	$(CC) -o $@ $^

ex1.o: ex1.c
	$(CC) $(CCFLAGS) -c $^

ex2.o: ex2.c ex2.h
	$(CC) $(CCFLAGS) -c ex2.c

ex3.o: ex3.c ex3.h
	$(CC) $(CCFLAGS) -c ex3.c

ex4.o: ex4.c
	$(CC) $(CCFLAGS) -c $^

ex5.o: ex5.c stack.h list.h
	$(CC) $(CCFLAGS) -c ex5.c

ex6.o: ex6.c
	$(CC) $(CCFLAGS) -c $^

ex7.o: ex7.c
	$(CC) $(CCFLAGS) -c $^

ex8.o: ex8.c
	$(CC) $(CCFLAGS) -c $^

queue.o: queue.c queue.h
	$(CC) $(CCFLAGS) -c queue.c

clean:
	rm -rf *.o *.dSYM ex1 ex2TestDriver ex3TestDriver ex4 ex5 ex6 ex7 ex8 

create:
	for ((i=1;i<=8;i++)); do touch ex$$i.c;         echo \/\* $$i\*\/ \\n\\n#include \<stdio.h\> > ex$$i.c;done
