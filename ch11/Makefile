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

ex12: ex12.o
	$(CC) -o $@ $^

ex13: ex13.o
	$(CC) -o $@ $^

ex14: ex14.o
	$(CC) -o $@ $^

ex15: ex15.o
	$(CC) -o $@ $^

ex16: ex16.o
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

ex9.o: ex9.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex10.o: ex10.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex11.o: ex11.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex12.o: ex12.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex13.o: ex13.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex14.o: ex14.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex15.o: ex15.c
	$(CC) $(CCFLAGS) -c $^ -o $@

ex16.o: ex16.c
	$(CC) $(CCFLAGS) -c $^ -o $@

clean:
	rm -rf *.o ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 

create:
	for ((i=1;i<=16;i++)); do \
		touch ex$$i.c; \
		echo \/\* $$i\*\/ \\n\\n#include \<stdio.h\>> ex$$i.c; \
	done
