#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

/* Find the primes between 3 and 50,000,000 */
int main()
{
  uint32_t end = 100000000;

  // Compute space needed for primes
  uint32_t space_for_primes = (uint32_t) (end / log(end)) * 1.162;;

  // Allocate space for primes
  uint32_t* primes = (uint32_t*) malloc(space_for_primes*sizeof(uint32_t));
  if(primes == NULL)
  {
    fprintf(stderr, "Unable to allocate memory for primes!\n");
    exit(1);
  }

  // Add a few primes
  primes[0] = 2;
  primes[1] = 3;
  primes[2] = 5;
  uint32_t num_primes = 3; // We start with 1 for #2

  // Search for primes
  for(uint32_t c = primes[num_primes-1] + 2; c <= end; c += 2)
  {
    bool is_prime = true;
    uint32_t fsr = (uint32_t) floor(sqrt(c));
    //printf("fsr: %u\n", fsr);
    for(uint32_t di = 0; primes[di] <= fsr; di++)
    {
      //printf("%u %% %u == %u\n", c, primes[di], c % primes[di]);
      if(c % primes[di] == 0)
      {
	is_prime = false;
	break;
      }
    }

    if(is_prime)
    {
      //printf("%u\n", c);
      primes[num_primes] = c;
      num_primes++;
    }
  }

  printf("Number of primes through %u: %u\n", end, num_primes); 
}
