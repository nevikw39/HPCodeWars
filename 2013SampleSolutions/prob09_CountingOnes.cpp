// Write a program that returns the number of 1s used when writing all integers from 0 to n
/* Example Input:
13
1
-1

Program Output:
6
1
*/

#include <string>
#include <iostream>

using namespace std;

int numberOfOnes(int value)
{
	int oneCount=0;

	while (value > 0)
	{
		if (value % 10 == 1)
			oneCount++;
		value /= 10;
	}
	return oneCount;
}

int main( int argc, char* argv[] )
{
   int i;
   int currentValue, oneCount;

   cout << "Enter Integers, one line at a time." << endl;
   cin >> currentValue;

   while (currentValue >=0)
   {
	   oneCount = 0;
	   for (i=1; i<=currentValue; i++)
		   oneCount += numberOfOnes(i);
	   cout << oneCount << endl ;
	   cin >> currentValue;
   }	
}