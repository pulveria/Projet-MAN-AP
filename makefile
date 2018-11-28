all: test1 test2 test3 test4 test5


test1: test1.o
			 gcc -o $@ $^  $(LDFLAGS)

test2: test2.o
			 gcc -o $@ $^  $(LDFLAGS)

test3: test3.o
			 gcc -o $@ $^  $(LDFLAGS)

test4: test4.o
				gcc -o $@ $^  $(LDFLAGS)

test5: test5.o
				gcc -o $@ $^  $(LDFLAGS)
%.o: %.c
			 gcc -c $(CFLAGS) $<

clean:
		   rm -f *.o core
