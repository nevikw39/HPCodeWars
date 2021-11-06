/* Making a Brute Force Waffle Solver
	... to solve Waffles/Skyscraper puzzles of up to 6x6


*/

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

#include <string>
#include <iostream>

using namespace std;

#define MAX_SOLVES 1

// Square size
#define DIMENSION 6

int reqs [DIMENSION][DIMENSION]=
	{ {0,0,0,0,0,0},
	  {0,0,0,0,0,0},
	  {0,0,0,0,0,0},
	  {0,0,0,0,0,0},
	  {0,0,0,0,0,0},
	  {0,0,0,0,0,0} };

int grid [DIMENSION][DIMENSION]=
	{ {0,0,0,0,0,0},
	  {0,0,0,0,0,0},
	  {0,0,0,0,0,0},
	  {0,0,0,0,0,0},
	  {0,0,0,0,0,0},
	  {0,0,0,0,0,0} };

int size;
int topReq [DIMENSION] = {0,0,0,0,0,0};
int botReq [DIMENSION] = {0,0,0,0,0,0};
int leftReq [DIMENSION] = {0,0,0,0,0,0};
int rightReq [DIMENSION] = {0,0,0,0,0,0};

/**********************************************
 * checkElem: Check end conditions or interim
 *            conditions of elements assigned.
 *
 * Return: -1 if current assignments fail.
 *          1 if current assignment is final and correct
 *          0 otherwise (still can't tell).
 **********************************************/
int checkElem(int row, int col)
{
	int i, val, req;
	int count, highViewed, newVal;
	int retVal=0;

	val = grid[row][col];

	// Requirements
	if (((req=reqs[row][col]) != 0) && (req != val))
		{retVal = -1; return retVal;}

	// Check Horizontal, Vertical, Row, Col
	//Horizontal
	for (i=0;i<col;i++)
	{
		 if (grid[row][i] == val)
			 {retVal = -1; return retVal;}
	}

	//Vertical
	for (i=0;i<row;i++)
	{
		 if (grid[i][col] == val)
			 {retVal = -1; return retVal;}
	}

	// Placed largest value.  Check leftReq and topReq requirements.
	if (val == size)
	{
		// column/topReq
		if(topReq[col]>0) // Requirement exists to check
		{
			for (i=1,count=1,highViewed=grid[0][col];i<=row;i++)
			{ if ((newVal=grid[i][col]) > highViewed) { count++; highViewed=newVal;} }
			if (topReq[col] != count)
				 {retVal = -1; return retVal;}
		}
		// row/leftReq
		if(leftReq[row]>0)
		{
			for (i=1,count=1,highViewed=grid[row][0];i<=col;i++)
			{ if ((newVal=grid[row][i]) > highViewed) { count++; highViewed=newVal;} }
			if (leftReq[row] != count)
				 {retVal = -1; return retVal;}
		}
	}

	//End of Row
	if (col == (size-1))
	{
		// row/rightReq
		if(rightReq[row]>0)
		{
			for (i=size-2,count=1,highViewed=grid[row][size-1];(i>=0)&&(highViewed<size);i--)
			{ if ((newVal=grid[row][i]) > highViewed) { count++; highViewed=newVal;} }
			if (rightReq[row] != count)
				 {retVal = -1; return retVal;}
		}
	}

	// End of Column
	if (row == (size-1))
	{
		// column/botReqtom
		if(botReq[col]>0)
		{
			for (i=size-2,count=1,highViewed=grid[size-1][col];(i>=0)&&(highViewed<size);i--)
			{ if ((newVal=grid[i][col]) > highViewed) { count++; highViewed=newVal;} }
			if (botReq[col] != count)
				 {retVal = -1; return retVal;}
		}
	}

	// Check end
	if ((row==col) && (row==(size-1)) )
		retVal = 1;

	return retVal;
}

/*********************************************
 * solve: Recursive function to assign values
 *        and test for success/failure
 *
 * Parameters: local copies of the used array
 *             and the elements array.
 *             Which element to assign now.
 *
 * Returns: 1 if successful completion, 0 if not.
 *          -1 if bad data.
 *********************************************/
int solve(int row, int col)
{
	int i, checkSuccess,x,y;  /* loop count, success variable */
	static int solves=MAX_SOLVES;

	if (col >= size)           /* Update row/column */
		{
			row++;
			col=0;
			if (row >= size)
				return -1;  /* Too big */
		}

	for (i=1; i<=size; i++) // Loop through the values
	{
		grid[row][col]=i;

			/* Check here for success.  Return 1 if done.
				Return -1 if fail.  Return 0 if not sure. */
			checkSuccess = checkElem(row,col);
			if (checkSuccess == 1)
			{
				/* Print results here */
				printf ("Solution %2d: \n",
						MAX_SOLVES+1-solves);
				for (x=0;x<size;x++)
				{
					for (y=0;y<size;y++)
					{
						printf(" %2d", grid[x][y]);
					}
					printf("\n");
				}
            printf("\n");

				if (--solves <=0) return 1;
			}
			else if (checkSuccess == 0)
				/* Get next value in list, recursively */
				if (solve(row,col+1) == 1)
					return 1;
		 grid[row][col]=0;

	} /* Continue loop to end of values */

	return 0;
}

void fillSpecialReqs()
{
	return; // To be filled in if it's needed
}
int main()
{
	int i;
	size = 5;
	// Uncomment the next line if the input allows for different sizes
	//cin >> size;
	if (size > DIMENSION) return -1;
	for (i=0;i<size;i++) { cin >> topReq[i];}
	for (i=0;i<size;i++) { cin >> leftReq[i]; cin >> rightReq[i];}
	for (i=0;i<size;i++) { cin >> botReq[i];}
	fillSpecialReqs(); // Use clues to mark some squares before starting brute force

	solve(0,0);
	//cout<<endl<<"0 to end."<<endl;
	//cin>>i;
	return 0;
}