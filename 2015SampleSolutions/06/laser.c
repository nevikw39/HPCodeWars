
#include <stdio.h>
int
GetNumStdIn () 
{
  int ch;
  scanf("%u", &ch); // read in unsigned decimal format
  return ch;
}

int 
GetNum (
  FILE *fp
  ) 
{
  int got;
  int read;
  int ch;

  read = 0;
  got = 0;
  ch = 0;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch < 0x30 || ch > 0x39) {
      if (got == 1) {
        break;
      }
      continue;
    }
    read = read * 10 + ch - 0x30;; 
    got = 1;
  } 

  return read;
}

int 
main (
  ) 
{
  int i;
  int j;
  int width;
  int height;
  int res;
  int shape[10][10];
  int count;
  int wasOn;

  width = 0;
  height = 0;
  count = 0;
  res = 0;

  // Get user input of "height" of the block from standard input
  // printf ("Height of the block to be lasered? ...\n");
  height = GetNumStdIn ();
  // printf ("Width of the block to be lasered? ...\n");
  width = GetNumStdIn ();

  if (width * height == 0) return 0;

  // printf ("Height residues of the block after lasered? ...\n");
  for (i = 0; i < width; i++) {
    res = GetNumStdIn ();
    for (j = 0; j < height; j++) {
      if (res > 0) {
        shape [height - j - 1][i] = 1;
        res--;
      } else {
        shape [height - j - 1][i] = 0;
      }
    }
  }

  // now count how many times does laser switch

  if (shape [0][0]) {
    wasOn = 0;
  } else {
    wasOn = 1;
    count = 1; // turn on at the beginning
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (shape [i][j]) { // laser off
        if (wasOn) { // if laser was on
          wasOn = 0; // turn it off
        } 
      } else { // laser on
        if (wasOn == 0) { // if laser was off
          wasOn = 1; // has to turn it on to remove target
          count++; // this counts for switch on process
          // printf ("Turn laser on (%d)th time@ [%d][%d]\n", count, i, j);
        }
      }
    }
    //turn off laser for one layer (height)
    wasOn = 0;
  }

  // printf ("Totally (%d) laser operations is needed\n", count);
  printf ("%d\n", count);
  return 0;
}
