/* A Question of Time

Give the minutes after the hour, and assuming the hourhand is
  approximately evenly angled across the centerline of a clock,
  give the time.

Example Input:
18
5
6
46
0
-1

Program Output:
8:18
11:05
11:06
2:46
12:00
*/

#include <string>
#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
   int i;
   int minute, hour;

   cout << "Enter Minutes, one line at a time." << endl;
   cin >> minute;

   while ((minute >=0) && (minute<60))
   {
	   hour = (60-minute) / 5;
	   if (hour==0) hour=12;
	   cout << hour << ":";
	   if (minute<10) cout << '0';
	   cout << minute << endl ;

	   cin >> minute;
   }	
}