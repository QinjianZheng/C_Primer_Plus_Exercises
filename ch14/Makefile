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

ex8: ex8.o
	$(CC) -o $@ $^

ex9: ex9.o
	$(CC) -o $@ $^

ex10: ex10.o
	$(CC) -o $@ $^

ex11: ex11.o
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

ex8.o: ex8.c
	$(CC) $(CCFLAGS) -c $^

ex9.o: ex9.c
	$(CC) $(CCFLAGS) -c $^

ex10.o: ex10.c
	$(CC) $(CCFLAGS) -c $^

ex11.o: ex11.c
	$(CC) $(CCFLAGS) -c $^

clean:
	rm -rf *.o ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 

create:
	for ((i=1;i<=11;i++)); do touch ex$$i.c;         echo \/\* $$i\*\/ \\n\\n#include \<stdio.h\> > ex$$i.c;done
