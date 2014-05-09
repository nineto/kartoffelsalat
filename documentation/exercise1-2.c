/* This program computes a fibonacci sequence in two different
 * approaches: iterative and recursive. It also determines the
 * computing time for each approach.
 * The program computes the sums for fibonacci numbers 'n' in the range
 * 35 <= n <= 45. It prints the fibonacci solutions along with the
 * determined computing times in standard output. 
 * 
 * File Name: exercise1-2.c        Author: Juergen Goebel
 * Date: 09.04.2014
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define F0 0                            /* first step of fib. seq.    */
#define F1 1                            /* second step of fib. seq.   */
#define MIN 35                          /* bottom limit of input range*/
#define MAX 45                          /* top limit of input range   */

struct Clocks
{
  clock_t start_CPU, 
          end_CPU,
          total_CPU;
  
  time_t  start_Wall,
          end_Wall,
          total_Wall;
};

long long fibonacci_iterative (int);
long long fibonacci_recursive (int);
void print_time (struct Clocks);

int main (void)
{
  long long result;
  struct Clocks iter,
                recur;
  int i;

  /* Start block for Iterative Fibonacci */
  printf ("Iterative Fibonacci\n====\n");
  
  iter.start_CPU = clock ();
  iter.start_Wall = time (NULL);
  
  /* computes and prints all sums in
   * range with MIN and MAX boundaries
   */
  for (i = MIN; i <= MAX; i++)
  {
    result = fibonacci_iterative (i);
    printf ("%i: %lld\n", i, result);   
  }
  
  iter.end_CPU = clock ();
  iter.end_Wall = time (NULL);
  iter.total_CPU = iter.end_CPU -
                   iter.start_CPU;
  iter.total_Wall = iter.end_Wall -
                    iter.start_Wall;

  print_time (iter);
  /* End block for Iterative Fibonacci */
  
  /* Start block for Recursive Fibonacci */
  printf ("Recursive Fibonacci\n====\n");
  recur.start_CPU = clock ();
  recur.start_Wall = time (NULL);

  for (i = MIN; i <= MAX; i++)
  {
    result = fibonacci_recursive (i);
    printf ("%i: %lld\n", i, result);   
  }

  recur.end_CPU = clock ();
  recur.end_Wall = time (NULL);
  recur.total_CPU = recur.end_CPU -
                    recur.start_CPU;
  recur.total_Wall = recur.end_Wall -
                     recur.start_Wall;

  print_time (recur);
  /* End block of Recursive Fibonacci */

  return EXIT_SUCCESS;
}

long long fibonacci_iterative (int n)
{
  long long first,
            second,
            next;
  int i;
  first = F0;
  second = F1;
  next = 0;

  for (i = F1; i <= n; i++)
  {
    if (i == F1)
      next = i;
    else
    {
      next = first + second;
      first = second;
      second = next;
    }
  }

  return next;
}

long long fibonacci_recursive (int n)
{
  switch (n)
  {
    case F0:
      return F0;
      break;
    case F1:
      return F1;
      break;
    default: 
      return
        (fibonacci_recursive (n - 1) + 
         fibonacci_recursive (n - 2)); 
      break;
  }
}

void print_time (struct Clocks generic)
{
  printf ("\nCPU clock\n");
  printf ("START: \t%ld\n",
            generic.start_CPU);
  printf ("END: \t%ld\n",
            generic.end_CPU);
  printf ("TOTAL: \t%ld\n",
            generic.total_CPU);
  printf ("TOTAL IN SEC: \t%ld\n",
            (generic.total_CPU / 
              CLOCKS_PER_SEC));

  printf ("\nWall clock\n");
  printf ("START: \t%ld\n",
            generic.start_Wall);
  printf ("END: \t%ld\n",
            generic.end_Wall);
  printf ("TOTAL: \t%ld\n",
            generic.total_Wall);
  printf ("\n\n");
}