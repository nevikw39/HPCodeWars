/* A Weighty Problem
Given ten sums representing the paired weights of 5 children, find the
original 5 weights of the children.

Example Input:
114 129 118 125 123 122 121 124 120 116
109 118 114 116 125 107 111 112 121 123
121 114 100 110 100 121 114 111 104 125
0 0 0 0 0 0 0 0 0 0

Program Output:
56 58 60 64 65
52 55 57 59 66
45 55 55 59 66
*/

#include <string>
#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
   int sums[10];
   int weights[5];
   int i,j,k, tmp;
   int fullSum;

   cout << "Enter ten paired sums (all zeros to end.)" << endl;

	cin >> sums[0];

	while (sums[0]!=0)
	{	  
		for (i=1;i<10;i++)
		{
			cin >> tmp;
			// Add to array in a sorted method
			for (j=0;j<i;j++)
			{
				if (tmp < sums[j])
				{
					for (k=i;k>j;k--)
						sums[k]=sums[k-1];
					break; // Stop the j-loop
				}
			}
			sums[j]=tmp;
		}
//		for (i=0;i<10;i++) cout << sums[i] <<" ";
		for (fullSum=0, i=0; i<10;i++)
			fullSum+=sums[i];
		fullSum = fullSum/4;
		weights[2] = fullSum - sums[0] - sums[9];
		weights[4] = sums[8] - weights[2];
		weights[0] = sums[1] - weights[2];
		weights[1] = sums[0] - weights[0];
		weights[3] = sums[9] - weights[4];
		for (i=0;i<5;i++) cout << weights[i] << " ";
		cout << endl;

		cin >> sums[0]; // Read first element of next line
    }	
}