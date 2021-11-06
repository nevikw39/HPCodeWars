// CodeWars11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{

	const int sizeMatrix = 8;

	int cwMatrix[sizeMatrix][sizeMatrix];
	int scanResult[2];
	
	//
	int i, j, a;

	//
	scanResult[0] = 0;
	scanResult[1] = 0;

	//input matrix
	//printf("\nEnter 64 integers:\n");
	for (i = 0; i < sizeMatrix; i++)
		for (j = 0; j < sizeMatrix; j++)
		{
			scanf("%d ", &a);
			cwMatrix[i][j] = a;
		}

		/* do not print matrix
	printf("\nYour Matrix:\n");
	for (i = 0; i < sizeMatrix; i++)
	{
		for (j = 0; j < sizeMatrix; j++)
		{
			printf("%d ", cwMatrix[i][j]);
		}
		printf("\n");
	}
	*/

	//scan
	//for (i = 0; i < sizeMatrix - 1; i++)
		//for (j = 0; j < sizeMatrix - 1; j++)
	for (i = 0; i < sizeMatrix; i++)
		for (j = 0; j < sizeMatrix - 1; j++)
		{
			if ( abs(cwMatrix[i][j] - cwMatrix[i][j+1]) == 1 )
			{
				scanResult[0] = scanResult[0] + 1;
				//printf("\n\n%d %d ", cwMatrix[i][j], cwMatrix[i][j+1]);
			}
			if ( abs(cwMatrix[j][i] - cwMatrix[j+1][i]) == 1 )
			{
				scanResult[1] = scanResult[1] + 1;
				//printf("\n\n%d %d ", cwMatrix[j][i], cwMatrix[j+1][i]);
			}
		}


	//print results
	printf("%d %d\n", scanResult[0], scanResult[1]);

	return 0;
}

