#include <stdlib.h>
#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int findDeepestPit(int n, int* array){
  int depth = -1, idx = 0;
  int P = 0, Q = 0, R = 0;

  if ((n == 0) || !array) {
    return -1;
  }

  for (idx = 0; idx < n - 1; idx++) {
    P = array[idx];

    // Find P
    if (P > array[idx+1]) {
      // Checking Descend to find Q
      int next = idx + 1;
      do {
        if (next >= n) { break; }

        Q = array[next++];
      } while(Q > array[next]);

      // Checkign Ascend to find R
      do {
        if(next >= n) { break; }

        R = array[next];
        if (Q < R && R > array[next-1]) {
          // Find one pit and calculate depth
          int new_depth = MIN(P-Q, R-Q);

          // Compare the depth
          depth = MAX(depth, new_depth);
        }
        next++;
      } while(R < array[next]);
    }
  }

  return depth;
}

int main(int argc, char **argv) {
    
    int idx = 0;
    scanf("%d", &idx);

    int *array = malloc(idx * sizeof(int));
    for (int i = 0; i < idx; i++) {
        scanf("%d", &array[i]);
    }

    printf("%d", findDeepestPit(idx, array));
    
    free(array);
    
    return 0;
}