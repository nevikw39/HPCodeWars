/* Find the distance in feet that the projectile travels
Example Input, velocity and angle in degrees.
63.9 65
-1

Program Output:
97.2198
*/

#include <string>
#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
   float velocity, angle, distance;

   cout << "Enter velocity, then angle." << endl;
   cin >> velocity;

//   while (velocity >=0)
//   {
	   cin >> angle;
	   distance = velocity*velocity * sin(2*(3.14159265)*angle/180) / 9.80665;
	   cout << distance << endl;
//	   cin >> velocity;	
//   }	
}