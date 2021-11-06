// HP_Code_War_HP_Tower.cpp : Defines the entry point for the console application.
//

#include "stdlib.h"

int CountWays(int n) {
   
    if (n < 0){
	return 0;
	} else if (n == 0){
	return 1;
	}  else {
	   return CountWays(n-1)+ CountWays(n-2) + CountWays(n-3);
	}
}
int main()
{
	int n = 0 , s = 0;

	// printf("Set the height of HP Tower = ");
	scanf_s("%d",&n);

	s = CountWays(n);
	// printf("There %d ways to build HP Tower\n", s);
	printf("\n%d\n", s);
	system("PAUSE"); 

	return 0;
}

