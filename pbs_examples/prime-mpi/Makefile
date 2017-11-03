CC=icc

all: prime prime_sieve prime_mpi

prime: prime.c
	$(CC) -std=c99 -o $@ $^

prime_sieve: prime_sieve.c
	$(CC) -g -std=c99 -o $@ $^

prime_mpi: prime_mpi.c
	$(CC) -std=c99 -lmpi -o $@ $^


