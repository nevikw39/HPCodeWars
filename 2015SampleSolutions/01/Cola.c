
#include <stdio.h>

int
GetNumStdIn () 
{
  int ch;
  scanf("%u", &ch); // read in unsigned decimal format
  return ch;
}

int main () 
{
  int toExchange;
  int total;
  int empty;
  int input;

  toExchange = 0;
  total = 0; 
  input = 0;

  toExchange = 3;

  // Get the original cola bought from standard input
  // printf ("How many cola did you buy? ...\n");
  total = GetNumStdIn ();
  empty = total;

  while (empty >= toExchange) {
    // Drank more cola's in exchange of empty bottles 
    total += empty / toExchange; 
    empty -= (empty / toExchange) * (toExchange - 1);
    // printf ("# left (%d)\n", empty);
  }

  // printf ("max cola to drink is (%d)\n", total);
  printf ("%d\n", total);
  return 0;
}
