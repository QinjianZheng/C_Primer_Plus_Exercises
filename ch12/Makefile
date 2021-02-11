CC = gcc
CCFLAGS = -Wall -Werror
ex1: ex1.o
	$(CC) -o $@ $^

ex2: ex2.o pe12-2a.o
	$(CC) -o $@ $^

ex3: ex3.o pe12-3a.o
	$(CC) -o $@ $^

ex4: ex4.o
	$(CC) -o $@ $^

ex5: ex5.o
	$(CC) -o $@ $^

ex6: ex6.o
	$(CC) -o $@ $^

ex7: ex7.o diceroll.o
	$(CC) -o $@ $^

ex8: ex8.o
	$(CC) -o $@ $^

ex9: ex9.o
	$(CC) -o $@ $^

ex1.o: ex1.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex2.o: ex2.c pe12-2a.h
	$(CC) $(CCFLAGS) -c $^

pe12-2a.o: pe12-2a.c
	$(CC) $(CCFLAGS) -c $^

ex3.o: ex3.c pe12-3a.h
	$(CC) $(CCFLAGS) -c $^ 

pe12-3a.o: pe12-3a.c
	$(CC) $(CCFLAGS) -c $^

ex4.o: ex4.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex5.o: ex5.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex6.o: ex6.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex7.o: ex7.c diceroll.h
	$(CC) $(CCFLAGS) -c ex7.c

diceroll.o: diceroll.c diceroll.h
	$(CC) $(CCFLAGS) -c diceroll.c

ex8.o: ex8.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex9.o: ex9.c
	$(CC) $(CCFLAGS) -c $^ -o $@

clean:
	rm -rf *.o ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 

create:
	for ((i=1;i<=9;i++)); do touch ex$$i.c;         echo \/\* $$i\*\/ \\n\\n#include \<stdio.h\> > ex$$i.c;done
