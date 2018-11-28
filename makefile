all: test1 test2 test3 test4 test5


test1: test1.o
			 gcc -std=c99 -g -Wall -Wextra -o $@ $^  $(LDFLAGS)

test2: test2.o
			 gcc -std=c99 -g -Wall -Wextra -o $@ $^  $(LDFLAGS)

test3: test3.o
			 gcc -std=c99 -g -Wall -Wextra -o $@ $^  $(LDFLAGS)

test4: test4.o
				gcc -std=c99 -g -Wall -Wextra -o $@ $^  $(LDFLAGS)

test5: test5.o
				gcc -std=c99 -g -Wall -Wextra -o $@ $^  $(LDFLAGS)
%.o: %.c
			 gcc -std=c99 -g -Wall -Wextra -c $(CFLAGS) $<

clean:
		   rm -f *.o core
