CFLAGS=-std=c11 -g

scc: scc.c

test: scc
	./test.sh

clean:
	rm -f scc *.o *~ tmp*

.PHONY: test clean