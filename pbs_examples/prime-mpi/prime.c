#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

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

/* Find the primes between 3 and 50,000,000 */
int main()
{
  uint32_t primes = 1; // We start with 1 for #2
  uint32_t end = 100000000;
  uint32_t prime_list[5762000];
  prime_list[0] = 2;
  

  for(uint32_t c = 3; c <= end; c += 2)
  {
    if(isPrime(c))
    {
      //printf("%u\n", c);
      prime_list[primes] = c;
      primes++;
    }
  }

  printf("Number of primes through %u: %u\n", end, primes); 
}
