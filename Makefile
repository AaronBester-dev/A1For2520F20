CFLAGS = -std=c99 -pedantic -Wall
CC = gcc

all: test_getbytes test_getbits test_bits2ull test_bits2ll test_spff test_dpff

bandb.o: bandb.c
	$(CC) $(CFLAGS) -c bandb.c -o bandb.o 

test_getbytes.o: test_getbytes.c 
	$(CC) $(CFLAGS) -c test_getbytes.c -o test_getbytes.o 

test_getbits.o: test_getbits.c
	$(CC) $(CFLAGS) -c test_getbits.c -o test_getbits.o 

test_bits2ull.o: test_bits2ull.c
	$(CC) $(CFLAGS) -c test_bits2ull.c -o test_bits2ull.o 

test_bits2ll.o: test_bits2ll.c
	$(CC) $(CFLAGS) -c test_bits2ll.c -o test_bits2ll.o 

test_spff.o: test_spff.c
	$(CC) $(CFLAGS) -c test_spff.c -o test_spff.o 

test_dpff.o: test_dpff.c
	$(CC) $(CFLAGS) -c test_dpff.c -o test_dpff.o 

test_getbytes: test_getbytes.o bandb.h bandb.o
	$(CC) $(CFLAGS) test_getbytes.o bandb.o -o test_getbytes 

test_getbits: test_getbits.o bandb.h bandb.o
	$(CC) $(CFLAGS) test_getbits.o bandb.o -o test_getbits 

test_bits2ull: test_bits2ull.o bandb.h bandb.o
	$(CC) $(CFLAGS) test_bits2ull.o bandb.o -o test_bits2ull 

test_bits2ll: test_bits2ll.o bandb.h bandb.o
	$(CC) $(CFLAGS) test_bits2ll.o bandb.o -o test_bits2ll 

test_spff: test_spff.o bandb.h bandb.o
	$(CC) $(CFLAGS) test_spff.o bandb.o -o test_spff 

test_dpff: test_dpff.o bandb.h bandb.o
	$(CC) $(CFLAGS) test_dpff.o bandb.o -o test_dpff 

clean:
	rm -i bandb.o test_getbytes.o test_getbytes test_getbits.o test_getbits test_bits2ull.o test_bits2ull test_bits2ll.o test_bits2ll test_spff.o test_spff test_dpff.o test_dpff