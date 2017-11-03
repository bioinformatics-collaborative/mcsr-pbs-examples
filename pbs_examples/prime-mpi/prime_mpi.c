#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <mpi.h>

/* A function that determines whether or not a number is prime
 * by attempting to divide it equally by all odd numbers <= to
 * its square root. Returns 1 if prime, 0 if not.
 */
int isPrime(uint32_t n)
{
  uint32_t fsr = (uint32_t) floor(sqrt(n));
  if(n % 2 == 0) return 0;
  for(uint32_t i = 3; i <= fsr; i += 2)
  {
    if(n % i == 0) return 0;
  }

  return 1;
}

int main()
{
  uint32_t primes = 0;
  //uint32_t end = 4294967200;
  uint32_t end = 100000000;
  int rank;
  int size;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

  if(rank != 0)
  {
    uint32_t start = 3 + (rank-1) * 2; // Start looking for primes here
    uint32_t inc = 2 * (size-1); // Increment candidate prime by this each time
    for(uint32_t c = start; c <= end; c += inc)
    {
      if(isPrime(c))
      {
	// Send prime number to head process
        MPI_Send(&c, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        primes++;
      }
    }

    printf("Number of primes found on CPU %d through %u: %u\n", 
           rank, end, primes);

    // Send 0 to head node to indicate this worker is done
    uint32_t zero = 0;
    MPI_Send(&zero, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
  else
  {
    primes = 1; // For 2
    uint32_t done = 0; // Number of workers that are done
    uint32_t prime; // To hold received prime numbers
    while(done != (size-1)) // Continue receiving until all workers are done
    {
      MPI_Recv(&prime, 1, MPI_INT, MPI_ANY_SOURCE, 0,
               MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      if(prime != 0)
      {
        printf("%d\n", prime);
	primes++; // Increment the number of primes
      }
      else
      {
        done++; // One of the processes is done
      }
    }

    printf("Total number of primes: %u\n", primes);
  }

  MPI_Finalize();
}

