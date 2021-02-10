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

ex1.o: ex1.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex2.o: ex2.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex3.o: ex3.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex4.o: ex4.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex5.o: ex5.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex6.o: ex6.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex7.o: ex7.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex8.o: ex8.c
	$(CC) $(CCFLAGS) -c $^ -o $@

clean:
	rm -rf *.o ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 

create:
	for ((i=1;i<=8;i++)); do touch ex$$i.c; done
